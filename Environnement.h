#ifndef ENVIRONNEMENT_H__
#define ENVIRONNEMENT_H__

// ===========================================================================
//                                  Includes
// ===========================================================================

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "Image.h"


class Environnement{
  
public:
// =========================================================================
//                               Constructors
// =========================================================================
  
  Environnement(void);
  Environnement(int W, int H, float init_A);

// =========================================================================
//                                Destructor
// =========================================================================

  ~Environnement(void);

// =========================================================================
//                                  Getters
// =========================================================================
  
  inline int get_W(void) const;
  inline int get_H(void) const;
  inline float get_A(void) const;
  inline float get_B(void) const;
  inline float get_C(void) const;
  

// =========================================================================
//                                  Setters
// =========================================================================

  inline void set_W(int W);
  inline void set_H(int H);
  inline void set_A(float A);
  inline void set_B(float B);
  inline void set_C(float C); 
  
// =========================================================================
//                                 Operators
// =========================================================================

// =========================================================================
//                              Public Methods
// =========================================================================


protected :
// =========================================================================
//                             Protected Methods
// =========================================================================

// =========================================================================
//                                Attributes
// =========================================================================

//==========================================================================
                    //MAYBE I SHOULD ADD X AND Y
//==========================================================================

  int W_;
  int H_;
  float A_;
  float B_;
  float C_;
  Environnement* Env_;
  Image* Image_;

};

// ===========================================================================
//                            Getters' definitions
// ===========================================================================
 
  inline int Environnement::get_W(void) const{
    return W_;
  }
 
  inline int Environnement::get_H(void) const{
    return H_;
  }
 
  inline float Environnement::get_A(void) const{
    return A_;
  }
 
  inline float Environnement::get_B(void) const{
    return B_;
  }
 
  inline float Environnement::get_C(void) const{
    return C_;
  }
 
// ===========================================================================
//                            Setters' definitions
// ===========================================================================
  
  inline void Environnement::set_W(int W){
    W_=W;
  }
  
  inline void Environnement::set_H(int H){
    H_=H;
  }
  
  inline void Environnement::set_A(float A){
    A_=A;
  }
  
  inline void Environnement::set_B(float B){
    B_=B;
  }
  
  inline void Environnement::set_C(float C){
    C_=C;
  }

// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================
	

#endif // ENVIRONNEMENT_H__

