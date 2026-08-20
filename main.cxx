// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include <cstdlib>
#include <GL/glut.h>

#include "App.h"
#include "Body.h"
#include "Callbacks.h"
#include "Clock.h"
#include "Hand.h"
#include "World.h"

int main( int argc, char** argv )
{
  init( argc, argv, "OpenGL clock", 500, 500 );

  // Init world
  clockWorld.SetBounds( -30, 30, -30, 30 );

  Hand* seconds = new Hand( 19, get_second );
  Hand* minutes = new Hand( 15, get_minute );
  Hand* hour = new Hand( 10, get_hour );
  Body* body = new Body( 20, 100 );

  body->SetColor( 1, 0, 1 );
  hour->SetColor( 0, 0, 1 );
  minutes->SetColor( 0, 1, 0 );
  seconds->SetColor( 1, 0, 0 );

  body->AddChild( hour );
  body->AddChild( minutes );
  body->AddChild( seconds );
  clockWorld.Root = body;

  // Callbacks
  glutDisplayFunc( cb_draw );
  glutIdleFunc( cb_idle );
  glutReshapeFunc( cb_resize );
  glutKeyboardFunc( cb_keyboard );
  glutSpecialFunc( cb_special_keyboard );

  // Go!
  std::atexit( finish );
  glutMainLoop( );

  return( EXIT_SUCCESS );
}

// eof - main.cxx
