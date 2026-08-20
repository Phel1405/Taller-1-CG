// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------
#ifndef __pujOpenGL__Body__h__
#define __pujOpenGL__Body__h__

#include "Circle.h"

/**
 */
class Body
  : public Circle
{
public:
  Body( float r, unsigned int s = 100 );
  virtual ~Body( ) override;

  virtual void Draw( ) override;

protected:
  float Radius { 1 };
};

#endif // __pujOpenGL__Body__h__

// eof - Body.h
