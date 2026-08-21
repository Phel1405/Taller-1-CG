// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include "Object.h"

#include <GL/gl.h>

// -------------------------------------------------------------------------
Object::
Object( int dm )
  : DrawMode( dm )
{
}

// -------------------------------------------------------------------------
Object::
~Object( )
{
  for( Object* c: this->Children )
    delete c;
  this->Children.clear( );
}

// -------------------------------------------------------------------------
void Object::
SetColor( float r, float g, float b )
{
  this->Color[ 0 ] = r;
  this->Color[ 1 ] = g;
  this->Color[ 2 ] = b;
}

// -------------------------------------------------------------------------
void Object::
AddChild( Object* c )
{
  if( c != nullptr )
    this->Children.push_back( c );
}

// -------------------------------------------------------------------------
void Object::
Draw( )
{
  glColor3fv( this->Color );
  //glBegin( GL_LINE_LOOP );
  glBegin( this->DrawMode );
  {
    for( unsigned int i = 0; i < this->Points.size( ); i += 2 )
      glVertex2f( this->Points[ i ], this->Points[ i + 1 ] );
  }
  glEnd( );

  for( Object* o: this->Children )
  {
    glPushMatrix( );
    glLoadIdentity( );
    o->Draw( );
    glPopMatrix( );
  } // end for
}

// eof - Object.cxx
