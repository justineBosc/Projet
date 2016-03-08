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
    Pop_=nullptr;
    Image_=nullptr;
  }
  
  Population::Population(int W, int H){
    W_=W;
    H_=H;
    Pop_ = new Individu[W_*H_];
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
      Pop_[Random_Position[i]].set_G(1);
    }
    
    
    for(int i=0; i<W_*H_; i++)                                          //Determines coordinates x and y of each individual
    {                                                                   //And change it
      Pop_[i].set_y(int(i/W_));                                         
      Pop_[i].set_y(i - W_*(int(i/W_)));
      //NE VAS PAS ICI !!!!!!!!!!!!!!!!
      Pop_[i].set_Pdeath(0.05);
    }
    
    Image_=nullptr;
  }

// ===========================================================================
//                                 Destructor
// ===========================================================================

  Population::~Population(void){
    delete [] Pop_;
    Pop_=nullptr;
  }

// ===========================================================================
//                               Public Methods
// ===========================================================================

  void Population::kill(void)
  {
    for(int i=0; i<W_*H_; i++)
    {
      Pop_[i].death();
    }
  }


  void Population::save_picture(std::string picture_name)
  {
    Image_=new Image(get_W(), get_H(), 255);
    for(int x=0; x<get_W(); x++)
    {
      for(int y=0; y<get_H(); y++)
      {
        if(Pop_[x*H_+y].get_vivant()==1)                                //Attribute Green pixels to individuals of genotype GA 
        {
          Image_ -> set_color(x, y, 0, 0);
          Image_ -> set_color(x, y, 1, 255);
          Image_ -> set_color(x, y, 2, 0);
        }
        else if(Pop_[x*H_+y].get_vivant()==0)                           //Attribute Red pixels to individuals of genotype GB
        {
          Image_ -> set_color(x, y, 0, 0);
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


