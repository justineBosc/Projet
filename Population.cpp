// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Population.h"


// ===========================================================================
//                       Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                Constructors
// ===========================================================================

  Population::Population(void){
    W_=0;
    H_=0;
    Env_=nullptr;
    Image_=nullptr;
  }
  
  Population::Population(int W, int H){
    W_=W;
    H_=H;
    Env_ = new Individu[W_*H_];
    
    //ALéatoirement position Ga
    int Position_Individu_Ga[(W_*H_)/2];
    Position_Individu_Ga[0]=rand()/(double)(RAND_MAX) * (W_*H_);
    int i=0;
    while (i<((W_*H_)/2))
    {
      for (int j=0; j<i; j++)
      {
        do
        {
          Position_Individu_Ga[i]=rand()/(double)(RAND_MAX) * (W_*H_);
        }
        while(Position_Individu_Ga[i]==Position_Individu_Ga[j]);
      }
      i+=1;
    }
    
    for(int i=0; i<((W_*H_)/2); i++)
    {
      Env_[Position_Individu_Ga[i]].set_G(1);
    }
  }

// ===========================================================================
//                                 Destructor
// ===========================================================================

  Population::~Population(void){
    delete [] Env_;
    Env_=nullptr;
  }

// ===========================================================================
//                               Public Methods
// ===========================================================================

  void Population::save_picture(std::string picture_name)
  {
    Image_=new Image(get_W(), get_H(), 255);
    for(int x=0; x<get_W(); x++)
    {
      for(int y=0; y<get_H(); y++)
      {
        if(Env_[x*y].get_G()==1)
        {
          Image_ -> set_color(x, y, 0, 0);
          Image_ -> set_color(x, y, 1, 255);
          Image_ -> set_color(x, y, 2, 0);
        }
        else if(Env_[x*y].get_G()==0)
        {
          Image_ -> set_color(x, y, 0, 255);
          Image_ -> set_color(x, y, 1, 0);
          Image_ -> set_color(x, y, 2, 0);
        }
      }
    }
    Image_ -> save(picture_name);
    delete Image_;
    Image_ = nullptr;
  }

// ===========================================================================
//                              Protected Methods
// ===========================================================================


