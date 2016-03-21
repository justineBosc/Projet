// ===========================================================================
//                                  Includes
// ===========================================================================

#include "Simulation.h"


// ===========================================================================
//                       Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                Constructors
// ===========================================================================

  Simulation::Simulation(int time, int max_T, int max_init_A)
  {
    time_=time;
    state_=0;
    
    state_A_T_=new int[max_T*(max_init_A+1)];
    for(int i=0; i<(max_T*(max_init_A+1)); i++)
    {
      state_A_T_[i]=0;
    }
    
    Phase_=nullptr; 
  }

// ===========================================================================
//                                 Destructor
// ===========================================================================

  Simulation::~Simulation(void)
  {
    delete [] state_A_T_;
    state_A_T_=nullptr;
  }

// ===========================================================================
//                               Public Methods
// ===========================================================================

// ===========================================================================
//                              Protected Methods
// ===========================================================================
