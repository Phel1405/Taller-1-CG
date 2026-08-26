// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include "Hand.h"

#include <GL/gl.h>
#include <cmath>
#include <chrono>

// -------------------------------------------------------------------------
Hand::Hand( float length, std::function<float()> f )
    : Square( GL_POLYGON ), Length( length / std::sqrt( float( 2 ) ) ), Function(f) {}

// -------------------------------------------------------------------------
Hand::~Hand() {
  if (this->Tip != nullptr)
    delete this->Tip;
}

// -------------------------------------------------------------------------
float Hand::GetLength( ) const
{
  return( this->Length );
}

// -------------------------------------------------------------------------

void Hand::SetTip( Object *tip, float rpm ) {
  this->Tip = tip;
  this->TipRPM = rpm;
}

// -------------------------------------------------------------------------
void Hand::Draw() {
  float a = this->Function();

  glPushMatrix();
  glRotatef( a, 0, 0, 1 );
  glScalef( this->Length * 0.08, this->Length, 1 );
  glRotatef( 45, 0, 0, 1 );
  glTranslatef( 0.5, 0.5, 0 );
  this->Square::Draw();
  glPopMatrix();


  if (this->Tip != nullptr) {
    static const auto start = std::chrono::steady_clock::now();
    auto now = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>( now - start ).count();

    // grados por segundo = RPM * 360 / 60 = RPM * 6
    float spin = std::fmod( seconds * this->TipRPM * 6.0f, 360.0f );

    glPushMatrix();
    glRotatef( a, 0, 0, 1 ); // misma orientación que la manecilla
    glTranslatef( 0, this->Length * std::sqrt( 2 ), 0 ); // extremo lejano de la manecilla
    glRotatef( spin, 0, 0, 1 ); // rotacion de la figura
    this->Tip->Draw();
    glPopMatrix();
  }
}



// eof - Hand.cxx
