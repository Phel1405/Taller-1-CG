// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------
#ifndef __pujOpenGL__World__h__
#define __pujOpenGL__World__h__

class Object;

/**
 */
class World {
public:
  World();
  virtual ~World();

  void SetBounds(float minX, float maxX, float minY, float maxY);
  virtual void Resize(int w, int h);
  virtual void Draw();

  bool day{true};
  void draw_time();
  void Zoom(float factor);

public:
  int WindowId;
  int Width;
  int Height;
  float ZoomFactor = 1.0f;

  float Bounds[4]{0, 0, 0, 0};

  Object *Root{nullptr};
};

#endif // __pujOpenGL__World__h__

// eof - World.h
