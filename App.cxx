// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include "App.h"

#include <GL/gl.h>
#include <GL/glut.h>

// -------------------------------------------------------------------------
World clockWorld;

// -------------------------------------------------------------------------
void init( int ac, char** av, const std::string& title, int W, int H )
{
  // Create window
  glutInit( &ac, av );
  glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
  glutInitWindowSize( W, H );
  clockWorld.WindowId = glutCreateWindow( title.c_str( ) );

  // Set clearing color
  glClearColor( 0.4f, 0.4f, 0.4f, 1.0f );
}

// -------------------------------------------------------------------------
void finish( )
{
  // NOTE: destructors should be automatically called
}

// eof - App.cxx
