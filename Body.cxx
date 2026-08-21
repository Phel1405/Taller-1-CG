// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include "Body.h"
#include <GL/gl.h>

// -------------------------------------------------------------------------
Body::
Body( float r, unsigned int s )
  : Circle( GL_POLYGON, s ),
    Radius( r )
{
}

// -------------------------------------------------------------------------
Body::
~Body( )
{
}

// -------------------------------------------------------------------------
void Body::
Draw( )
{
  glScalef( this->Radius, this->Radius, 1 );
  this->Circle::Draw( );
}

// eof - Body.cxx
