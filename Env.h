#ifndef ENV_H__
#define ENV_H__

// ===========================================================================
//                                  Includes
// ===========================================================================

#include <stdio.h>
#include <cstdlib>
#include <iostream>

#include "Individu.h"
#include "Cell.h"
#include "Image.h"

class Environnement{
  
public:
// =========================================================================
//                               Constructors
// =========================================================================

  Environnement(void);
  Environnement(int W, int H, float init_A, float D, float h, float Raa, float Rab, float Rbb, float Rbc, float Wmin, float Pmut, float Pdeath);

// =========================================================================
//                                Destructor
// =========================================================================

  ~Environnement(void);

// =========================================================================
//                                  Getters
// =========================================================================

  inline int get_W(void) const;
  inline int get_H(void) const;
  
  inline float get_D(void) const;
  inline float get_h(void) const;
  
  inline float get_Raa(void) const;
  inline float get_Rab(void) const;
  inline float get_Rbb(void) const;
  inline float get_Rbc(void) const;
  
  inline float get_fitness(int x, int y);

// =========================================================================
//                                  Setters
// =========================================================================

  inline void set_W(int W);
  inline void set_H(int H);
  
  inline void set_h(int h);
  
// =========================================================================
//                                 Operators
// =========================================================================

// =========================================================================
//                              Public Methods
// =========================================================================

  void kill(void);
  void divide(void);
  int position_best_fitness(int x, int y);
  void mutation(void);
  
  void reset(float init_A);
  
  void metabolism(void);
  void diffusion(void);
  
  int counter_Ga(void);
  int counter_Gb(void);
  
  void save_picture(std::string picture_name);

protected :
// =========================================================================
//                             Protected Methods
// =========================================================================

// =========================================================================
//                                Attributes
// =========================================================================

  int H_;
  int W_;
  
  float D_;
  float h_;
  
  float Raa_;
  float Rab_;
  float Rbb_;
  float Rbc_;
  
  float Wmin_;
  float Pmut_;
  float Pdeath_;
  
  Individu* Pop_;
  Cell* Env_;
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
  
  
  inline float Environnement::get_D(void) const{
    return D_;
  }
  
  inline float Environnement::get_h(void) const{
    return h_;
  }
  
  
  inline float Environnement::get_Raa(void) const{
    return Raa_;
  }
  
  inline float Environnement::get_Rab(void) const{
    return Rab_;
  }
  
  inline float Environnement::get_Rbb(void) const{
    return Rbb_;
  }
  
  inline float Environnement::get_Rbc(void) const{
    return Rbc_;
  }
  
  
  inline float Environnement::get_fitness(int x, int y){
    return Pop_[(y*W_)+x].get_w();                                      //Return the fitness of the position (x,y) individual
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
  
  inline void Environnement::set_h(int h){
    h_=h;
  }

// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================
	

#endif // ENV_H__



