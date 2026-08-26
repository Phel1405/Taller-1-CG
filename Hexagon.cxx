#include "Hexagon.h"
#include "GL/gl.h"

Hexagon::
Hexagon( float r, unsigned int s )
  : Circle( GL_LINE_LOOP, s ),
    Radius( r )
{
}

Hexagon::
~Hexagon( )
{
}

void Hexagon::
Draw( )
{
  glScalef( this->Radius, this->Radius, 1 );
  this->Circle::Draw( );
}


// eof - Hexagon.cxx
