#ifndef INDIVIDU_H__
#define INDIVIDU_H__

// ===========================================================================
//                                  Includes
// ===========================================================================

#include <stdio.h>
#include <cstdlib>
#include <iostream>


class Individu{

public :
// =========================================================================
//                               Constructors
// =========================================================================
  
  Individu(void);

// =========================================================================
//                                Destructor
// =========================================================================

  ~Individu(void);

// =========================================================================
//                                  Getters
// =========================================================================
  
  inline int get_x(void) const;
  inline int get_y(void) const;
  inline int get_G(void) const;
  inline float get_Ca(void) const;
  inline float get_Cb(void) const;
  inline float get_Cc(void) const;
  inline float get_w(void) const;
  inline bool get_vivant(void) const;

// =========================================================================
//                                  Setters
// =========================================================================

  inline void set_x(int x);
  inline void set_y(int y);
  inline void set_G(int g);
  inline void set_Ca(float A);
  inline void set_Cb(float B);
  inline void set_Cc(float C);
  inline void set_w(void);
  inline void set_w(float Wmin);
  inline void set_vivant(bool v);

// =========================================================================
//                                 Operators
// =========================================================================

// =========================================================================
//                              Public Methods
// =========================================================================

  void mutation(float Pmut);
  void death(float Pdeath);

protected :
// =========================================================================
//                             Protected Methods
// =========================================================================

// =========================================================================
//                                Attributes
// =========================================================================
 
  int x_;
  int y_;
  int G_;             //Ga -> G_=0; Gb -> G_=1
  float Ca_;
  float Cb_;
  float Cc_;
  float w_;
  bool vivant_;

};

// ===========================================================================
//                            Getters' definitions
// ===========================================================================
 
  inline int Individu::get_x(void) const{
	  return x_;
  }
  
  inline int Individu::get_y(void) const{
    return y_;
  }
  
  inline int Individu::get_G(void) const{
	  return G_;
  }
  
  inline float Individu::get_Ca(void) const{
	  return Ca_;
  }
  
  inline float Individu::get_Cb(void) const{
	  return Cb_;
  }
  
  inline float Individu::get_Cc(void) const{
	  return Cc_;
  }
  
  inline float Individu::get_w(void) const{
	  return w_;
  }
  
  inline bool Individu::get_vivant(void) const{
	  return vivant_;
  }

// ===========================================================================
//                            Setters' definitions
// ===========================================================================

  inline void Individu::set_x(int x){
	  x_=x;
  }
  
  inline void Individu::set_y(int y){
    y_=y;
  }
  
  inline void Individu::set_G(int g){
	  G_=g;
  }
  
  inline void Individu::set_Ca(float A){
	  Ca_=A;
  }
  
  inline void Individu::set_Cb(float B){
	  Cb_=B;
  }
  
  inline void Individu::set_Cc(float C){
	  Cc_=C;
  }
  
  inline void Individu::set_w(void){
	  w_=0;
  }
  
  inline void Individu::set_w(float Wmin){
    if(G_==0){
      if(Cb_<Wmin){ w_=0; }
      else { w_=Cb_; }
    }
    else if (G_==1){
      if(Cc_<Wmin){ w_=0; }
      else { w_=Cc_; }
    }
  }
  
  inline void Individu::set_vivant(bool v){
	  vivant_=v;
  }
  
// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================
	

#endif // INDIVIDU_H__
