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
                                                                        //Distributed randomly W*H/2 individuals of genotype GA and W*H/2 individuals of genotype GB 
    int Position[W_*H_];                                                //Create 2 array of size W*H
    int Random_Position[W_*H_];
                                                                        
    for (int i=0; i<(W_*H_); i++){                                      
      Position[i]=i;                                                    //Put i in case i : Contains values of 0 to (W*H)-1
      Random_Position[i]=0;                                             //Put 0 in each case
    }
    
    int r;                                                              //Create a int r who will contain a ramdom number
    for (int j=0; j<(W_*H_); j++){                                      //Brow Position Array
      do{
        r=0;
        r=rand()/(double)(RAND_MAX) * (W_*H_);
      }
      while (Random_Position[r]!=0);                                    //Generate a random number until Random_Position[random_number] egal 0 
      Random_Position[r]=Position[j];                                   
    }
    
    for(int i=0; i<((W_*H_)/2); i++)                                    //Attribute genotype GA (=set_G(1)) to the (W*H)/2 first (random) positions
    {                                                                   
      Env_[Random_Position[i]].set_G(1);
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
        if(Env_[x*H_+y].get_G()==1)                                     //Attribute Green pixels to individuals of genotype GA 
        {
          Image_ -> set_color(x, y, 0, 0);
          Image_ -> set_color(x, y, 1, 255);
          Image_ -> set_color(x, y, 2, 0);
          std::cout<<"position : "<<x*H_+y<<", G=1"<<std::endl;
        }
        else if(Env_[x*H_+y].get_G()==0)                                //Attribute Red pixels to individuals of genotype GB
        {
          Image_ -> set_color(x, y, 0, 255);
          Image_ -> set_color(x, y, 1, 0);
          Image_ -> set_color(x, y, 2, 0);
          std::cout<<"position : "<<x*H_+y<<", G=0"<<std::endl;
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


