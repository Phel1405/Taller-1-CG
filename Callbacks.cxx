// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include "Callbacks.h"
#include "App.h"

#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

// -------------------------------------------------------------------------
void cb_draw() {
  clockWorld.Draw();
  glutSwapBuffers();
}

// -------------------------------------------------------------------------
void cb_idle() { glutPostRedisplay(); }

// -------------------------------------------------------------------------
void cb_resize(int w, int h) {
  clockWorld.Resize(w, h);
  glutPostRedisplay();
}

// -------------------------------------------------------------------------
void cb_keyboard(unsigned char k, int x, int y) {
  std::cout << "key: " << k << std::endl;

  if (k == 27)
    std::exit(1);
  else if (k == ' ') {
    glClearColor(0, 1, 1, 1);
  }
}

// -------------------------------------------------------------------------
void cb_special_keyboard(int k, int x, int y) {}

// eof - Callbacks.cxx
