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
#include "Triangle.h"
#include "Hexagon.h"
#include "Star.h"

int main( int argc, char** argv )
{
  init( argc, argv, "OpenGL clock", 500, 500 );

  // Init world
  clockWorld.SetBounds( -30, 30, -30, 30 );

  Hand* seconds = new Hand( 19, get_second );
  Hand* minutes = new Hand( 15, get_minute );
  Hand* hour = new Hand( 10, get_hour );
  Body* body1 = new Body( 20, 100 );
  Body* body2 = new Body( 19.5, 100 );

  body1->SetColor( 0.13, 0.03, 0.01 );
  body2->SetColor( 0.67, 0.67, 0.67 );
  hour->SetColor( 0, 0, 1 );
  minutes->SetColor( 0, 1, 0 );
  seconds->SetColor( 1, 0, 0 );

  body1->AddChild( body2 );
  body2->AddChild( hour );
  body2->AddChild( minutes );
  body2->AddChild( seconds );
  clockWorld.Root = body1;

  Triangle* secondsTip = new Triangle( 2.0f );
  secondsTip->SetColor( 1, 1, 0 );
  seconds->SetTip( secondsTip, seconds->GetLength( ) * 2.0 );

  Hexagon* hourTip = new Hexagon( 1.5f );
  hourTip->SetColor( 0, 1, 1 );
  hour->SetTip( hourTip, hour->GetLength( ) * 2.0 );

  Star* minutesTip = new Star( 1.5f );
  minutesTip->SetColor( 1, 0, 1 );
  minutes->SetTip( minutesTip, minutes->GetLength( ) * 2.0 );

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
