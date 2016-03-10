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
                                                                        //Distributed randomly W*H/2 individuals of genotype GB and W*H/2 individuals of genotype GB 
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
    
    for(int i=0; i<((W_*H_)/2); i++)                                    //Attribute genotype GB (=set_G(1)) to the (W*H)/2 first (random) positions
    {                                                                   
      Pop_[Random_Position[i]].set_G(1);
    }
    
    
    for(int i=0; i<W_*H_; i++)                                          //Determines coordinates x and y of each individual
    {                                                                   //And change it
      Pop_[i].set_y(int(i/W_));                                         
      Pop_[i].set_x(i - W_*(int(i/W_)));
      //NE VAS PAS ICI !!!!!!!!!!!!!!!!
      Pop_[i].set_Pdeath(0.05);
      Pop_[i].set_Pmut(0.1);
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
      Pop_[i].set_w(0);
    }
  }
  
  
  int Population::position_best_fitness(int x, int y)
  {
    float max=0.0;
    int pos=0;
    
    for(int i=x-1; i<=x+1; i++){                                        //Browse gaps' Moore neighborhood 
      for(int j=y-1; j<=y+1; j++){
        
        int X=0;                                                        
        int Y=0;
                                                                        //Torus
        if(i<0) { X = W_-1; }                                           //if X<0 replace it at position W-1
        else if(i>=W_) { X = 0; }                                       //if X>=W replace it at position 0
        else { X=i; }                                             
        
        if(j<0) { Y = H_-1; }                                           //Same thing
        else if(j>=H_) { Y = 0; }
        else { Y=j; }
        
        if(get_fitness(X,Y) > max){                                     
          max = get_fitness(X,Y);                                       //max is egal to the best fitness in the Moore neighborhood
          pos=(Y*W_)+X;                                                 //get the position of individual with the best fitness
        }
      }
    }
    return pos;                                                         //return the position of the individual with the best fitness               
  } 
  
  
  void Population::divide(void)
  {        
    
    //============== Find the gaps' position in the Population ===============
    
    int Gap[W_*H_];                                                     //Create an array gap of size W*H
    
    for(int i=0; i<W_*H_;i++){                                          
      Gap[i]=0;                                                         //initialize the gaps' position to zero
    }
    
    int cptr=0;
    
    for(int i=0; i<W_*H_; i++){
      if(Pop_[i].get_vivant()==0){                                      //When vivant is null
        Gap[cptr]=i;                                                    //Add the position in the array
        cptr+=1;                                                        
      }
    }
    
    //=================== Randomize the gaps' position ==========================
    
    int Random_Gap[cptr];                                               //Create an array Random_Gap of size cptr ie the number of gaps
    
    for(int i=0; i<cptr; i++){
      Random_Gap[i]=0;                                                  //Initialize each cell with zero
    }
    
    int r;
    for(int j=0; j<cptr; j++){
      do{
        r=0;
        r=rand()/(double)(RAND_MAX) * cptr;
      }
      while (Random_Gap[r]!=0);
      Random_Gap[r]=Gap[j];                                             
    }
    
    //================ Browse the random position of the gap ===================
    //== Select the individual who has the best fitness in Moore neighborhood ==
    //==================== divide him into the gap =============================
    
    int pos=0;
    
    for(int i=0; i<cptr; i++){
      
      int y= int(Random_Gap[i]/W_);
      int x= Random_Gap[i] - W_*(int(Random_Gap[i]/W_));
      pos=position_best_fitness(x, y);
      
      Pop_[i].set_vivant(1);
      Pop_[pos].set_G(Pop_[i].get_G());                                 //the 2 daughter cells inherit of the mother's genotype
      
      Pop_[pos].set_Ca(Pop_[i].get_Ca()/2);                             //2 cells inherit half of each mother's interne concentrations
      Pop_[i].set_Ca(Pop_[i].get_Ca()/2);
      
      Pop_[pos].set_Cb(Pop_[i].get_Cb()/2);
      Pop_[i].set_Cb(Pop_[i].get_Cb()/2);
    
      Pop_[pos].set_Cc(Pop_[i].get_Cc()/2);
      Pop_[i].set_Cc(Pop_[i].get_Cc()/2);
      
      Pop_[pos].set_w();                                                //Update the fitness
      Pop_[i].set_w();
    }
  }
  
  
  void Population::mutation(void)
  {
    for(int i=0; i<W_*H_; i++){
      Pop_[i].mutation();
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


