// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include "Hand.h"

#include <GL/gl.h>
#include <cmath>

// -------------------------------------------------------------------------
Hand::Hand(float length, std::function<float()> f)
    : Square(GL_POLYGON), Length(length / std::sqrt(float(2))), Function(f) {}

// -------------------------------------------------------------------------
Hand::~Hand() {}

// -------------------------------------------------------------------------
void Hand::Draw() {
  float a = this->Function();

  glRotatef(a, 0, 0, 1);
  glScalef(this->Length * 0.08, this->Length, 1);
  glRotatef(45, 0, 0, 1);
  glTranslatef(0.5, 0.5, 0);
  this->Square::Draw();
}

// eof - Hand.cxx
