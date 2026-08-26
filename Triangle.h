
#ifndef __pujOpenGL__Triangle__h__
#define __pujOpenGL__Triangle__h__

#include "Circle.h"

class Triangle
  : public Circle
{
public:
  Triangle( float r, unsigned int s = 3 );
  virtual ~Triangle( ) override;

  virtual void Draw( ) override;

protected:
  float Radius { 1 };
};

#endif

// eof - Triangle.h
