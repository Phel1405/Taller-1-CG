// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------
#include "World.h"
#include <iostream>

#include "Callbacks.h"
#include "Clock.h"
#include "Object.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

// -------------------------------------------------------------------------
World::World() {}

// -------------------------------------------------------------------------
World::~World() {
  if (this->Root != nullptr)
    delete this->Root;
}

// -------------------------------------------------------------------------
void World::SetBounds(float minX, float maxX, float minY, float maxY) {
  this->Bounds[0] = minX;
  this->Bounds[1] = maxX;
  this->Bounds[2] = minY;
  this->Bounds[3] = maxY;
}

// -------------------------------------------------------------------------
void World::Resize(int w, int h) {
  // Update window size and compute aspect ratio
  this->Width = w;
  this->Height = (h == 0) ? 1 : h;
  float a = float(this->Width) / float(this->Height);

  // Define viewport
  glViewport(0, 0, w, h);

  // Update projection matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(this->Bounds[0] * a * this->ZoomFactor,
          this->Bounds[1] * a * this->ZoomFactor,
          this->Bounds[2] * this->ZoomFactor,
          this->Bounds[3] * this->ZoomFactor, -1.0, 1.0);
}

// -------------------------------------------------------------------------
void World::Draw() {
  // Clear state first so the text is not erased immediately afterwards.
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  if (this->Root != nullptr)
    this->Root->Draw();

  this->draw_time();
}

// -------------------------------------------------------------------------
void World::Zoom(float factor) {
  this->ZoomFactor *= factor;
  this->Resize(this->Width, this->Height);
}

// -------------------------------------------------------------------------
void World::draw_time() {
  auto now = std::chrono::system_clock::now();
  std::time_t current_time = std::chrono::system_clock::to_time_t(now);
  std::tm *local_time = std::localtime(&current_time);

  int hour = local_time->tm_hour % 12;
  if (hour == 0)
    hour = 12;

  const char *suffix;

  if (this->day) {
    glClearColor(0.67, 0.85, 1, 1);
    suffix = "AM";
    glColor3f(0, 0, 0);
  } else {
    glClearColor(0.054, 0.098, 0.32, 1);
    suffix = "PM";
    glColor3f(1, 1, 1);
  }
  // = ( local_time->tm_hour >= 12 ) ? "PM" : "AM";
  std::ostringstream oss;
  oss << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2)
      << std::setfill('0') << local_time->tm_min << ":" << std::setw(2)
      << std::setfill('0') << local_time->tm_sec << " " << suffix;

  std::string text = oss.str();

  // dibujar en el mundo
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // glColor3f( 1, 1, 1 );
  glRasterPos2f(-28.0f, 26.0f);

  for (unsigned char ch : text)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ch);
}

// eof - World.cxx
