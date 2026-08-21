// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------
#ifndef __pujOpenGL__Circle__h__
#define __pujOpenGL__Circle__h__

#include "Object.h"

/**
 */
class Circle
  : public Object
{
public:
  Circle( int dm, unsigned int s = 10 );
  virtual ~Circle( ) override;
};

#endif // __pujOpenGL__Circle__h__

// eof - Circle.h
