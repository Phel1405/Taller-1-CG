#include "Body.h"
#include "GL/gl.h"

Triangle::
Triangle( float r, unsigned int s )
  : Circle( GL_LINE_LOOP, s ),
    Radius( r )
{
}

Triangle::
~Triangle( )
{
}

void Triangle::
Draw( )
{
  glScalef( this->Radius, this->Radius, 1 );
  this->Circle::Draw( );
}


// eof - Triangle.cxx
