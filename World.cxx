// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include "World.h"

#include "Clock.h"  
#include "Object.h"
#include <GL/gl.h>

// -------------------------------------------------------------------------
World::
World( )
{
}

// -------------------------------------------------------------------------
World::
~World( )
{
  if( this->Root != nullptr )
    delete this->Root;
}

// -------------------------------------------------------------------------
void World::
SetBounds( float minX, float maxX, float minY, float maxY )
{
  this->Bounds[ 0 ] = minX;
  this->Bounds[ 1 ] = maxX;
  this->Bounds[ 2 ] = minY;
  this->Bounds[ 3 ] = maxY;
}

// -------------------------------------------------------------------------
void World::
Resize( int w, int h )
{
  // Update window size and compute aspect ratio
  this->Width = w;
  this->Height = ( h == 0 )? 1: h;
  float a = float( this->Width ) / float( this->Height );

  // Define viewport
  glViewport( 0, 0, w, h );

  // Update projection matrix
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  glOrtho(
    this->Bounds[ 0 ] * a, this->Bounds[ 1 ] * a,
    this->Bounds[ 2 ], this->Bounds[ 3 ],
    -1.0, 1.0
    );
}

// -------------------------------------------------------------------------
void World::
Draw( )
{
  // Clear state
  glClear( GL_COLOR_BUFFER_BIT );
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity( );

  if ( is_day() )
    glClearColor( 0.5, 0.5, 1.0, 1 );
  else
    glClearColor( 0.0, 0.0, 0.2, 1 );

  if( this->Root != nullptr )
    this->Root->Draw( );
}

// eof - World.cxx
