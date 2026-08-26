
#ifndef __pujOpenGL__Star__h__
#define __pujOpenGL__Star__h__

#include "Triangle.h"

class Star
  : public Triangle
{
public:
  Star( float r, unsigned int s = 3 );
  virtual ~Star( ) override;

  virtual void Draw( ) override;

protected:
  float Radius { 1 };
};

#endif

// eof - Star.h
