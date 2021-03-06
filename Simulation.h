#ifndef SIMULATION_H__
#define SIMULATION_H__

// ===========================================================================
//                                  Includes
// ===========================================================================

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Image.h"
#include "Env.h"
#include "Individu.h"



class Simulation{
  
public:
// =========================================================================
//                               Constructors
// =========================================================================

  Simulation(int time, int max_T, int max_init_A);

// =========================================================================
//                                Destructor
// =========================================================================

  ~Simulation(void);

// =========================================================================
//                                  Getters
// =========================================================================

  inline int get_time(void) const;

// =========================================================================
//                                  Setters
// =========================================================================

  inline void set_time(int time);

// =========================================================================
//                                 Operators
// =========================================================================

// =========================================================================
//                              Public Methods
// =========================================================================

  void run(void);
  void save_picture(std::string picture_name);

protected :
// =========================================================================
//                             Protected Methods
// =========================================================================

// =========================================================================
//                                Attributes
// =========================================================================

//==========================================================================

  int time_;            //Simulation time
  int* state_;          //State's Array : 0=cohabitation; 1=Exclusion; 2=Extinction
  Image* Phase_;        
  int T_;
  int Ainit_;
     

};

// ===========================================================================
//                            Getters' definitions
// ===========================================================================
 
  inline int Simulation::get_time(void) const{
    return time_;
  }
 
// ===========================================================================
//                            Setters' definitions
// ===========================================================================

  inline void Simulation::set_time(int time){
    time_=time;
  }

// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================
	

#endif // SIMULATION_H__

