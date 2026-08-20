// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include "Square.h"

// -------------------------------------------------------------------------
Square::
Square( )
  : Object( )
{
  this->Points.push_back( -0.5 );
  this->Points.push_back( -0.5 );
  this->Points.push_back(  0.5 );
  this->Points.push_back( -0.5 );
  this->Points.push_back(  0.5 );
  this->Points.push_back(  0.5 );
  this->Points.push_back( -0.5 );
  this->Points.push_back(  0.5 );
}

// -------------------------------------------------------------------------
Square::
~Square( )
{
}

// eof - Square.cxx
