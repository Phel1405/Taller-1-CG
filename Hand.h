// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------
#ifndef __pujOpenGL__Hand__h__
#define __pujOpenGL__Hand__h__

#include <functional>

#include "Square.h"
#include "Object.h"

/**
 */
class Hand
  : public Square
{
public:
  Hand( float length, std::function< float( ) > f );
  virtual ~Hand( ) override;

  virtual void Draw( ) override;

  // para centro en punta de manecilla
  float GetLength( ) const;
  void SetTip( Object* tip, float rpm );


protected:
  float Length { 1 };
  std::function< float( ) > Function { []( ) -> int { return( 0 ); } };

  // para centro en punta de manecilla
  Object* Tip { nullptr };
  float TipRPM { 0 };
};

#endif // __pujOpenGL__Hand__h__

// eof - Hand.h
