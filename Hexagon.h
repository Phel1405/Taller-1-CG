
#ifndef __pujOpenGL__Hexagon__h__
#define __pujOpenGL__Hexagon__h__

#include "Circle.h"

class Hexagon
  : public Circle
{
public:
  Hexagon( float r, unsigned int s = 6 );
  virtual ~Hexagon( ) override;

  virtual void Draw( ) override;

protected:
  float Radius { 1 };
};

#endif

// eof - Hexagon.h
