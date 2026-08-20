// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------
#ifndef __pujOpenGL__Object__h__
#define __pujOpenGL__Object__h__

#include <vector>

/**
 */
class Object {
public:
  Object();
  virtual ~Object();

  void SetColor(float r, float g, float b);
  void AddChild(Object *c);
  virtual void Draw();

protected:
  float Color[3]{1, 1, 1};
  std::vector<float> Points;
  std::vector<Object *> Children;
};

#endif // __pujOpenGL__Object__h__

// eof - Object.h
