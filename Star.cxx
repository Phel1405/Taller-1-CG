#include "Star.h"
#include "GL/gl.h"

Star::Star( float r, unsigned int s )
  : Triangle( r, s )
{
}

Star::~Star( )
{
}

void Star::
Draw( )
{
  glPushMatrix( );
  this->Triangle::Draw( );
  glPopMatrix( );

  glPushMatrix( );
  glRotatef( 180.0f, 0, 0, 1 );
  this->Triangle::Draw( );
  glPopMatrix( );
}


// eof - Star.cxx
