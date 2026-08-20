// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------
#ifndef __pujOpenGL__App__h__
#define __pujOpenGL__App__h__

#include <string>
#include "World.h"

// -------------------------------------------------------------------------
extern World clockWorld;

// -------------------------------------------------------------------------
void init( int ac, char** av, const std::string& title, int W, int H );
void finish( );

#endif // __pujOpenGL__App__h__

// eof - App.h
