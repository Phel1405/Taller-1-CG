// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include "Circle.h"

#include <cmath>

// -------------------------------------------------------------------------
Circle::
Circle( unsigned int s )
  : Object( )
{
  float _2pi = std::atan( float( 1 ) ) * float( 8 );
  for( unsigned int i = 0; i < s; ++i )
  {
    float w = _2pi * ( float( i ) / float( s ) );
    this->Points.push_back( std::cos( w ) );
    this->Points.push_back( std::sin( w ) );
  } // end for
}

// -------------------------------------------------------------------------
Circle::
~Circle( )
{
}

// eof - Circle.cxx
