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
    T_=max_T;
    Ainit_=max_init_A;
    
    state_=new int[max_T*(max_init_A+1)];
    for(int i=0; i<(max_T*(max_init_A+1)); i++)
    {
      state_[i]=0;
    }
    
    Phase_=nullptr; 
  }

// ===========================================================================
//                                 Destructor
// ===========================================================================

  Simulation::~Simulation(void)
  {
    delete [] state_;
    state_=nullptr;
  }

// ===========================================================================
//                               Public Methods
// ===========================================================================

  void Simulation::run(void)
  {
    int W=0;
    int H=0;
    float D=0.0;
    float h=0.0;
    float Raa=0.0;
    float Rab=0.0;
    float Rbb=0.0;
    float Rbc=0.0;
    float Wmin=0.0;
    float Pmut=0.0;
    float Pdeath=0.0;
    std::string w, height, d, h_, raa, rab, rbb, rbc, wmin, pmut, pdeath;
    std::ifstream f("parameters.txt", std::ios::in);
    f>>w>>W;
    f>>height>>H;
    f>>d>>D;
    f>>h_>>h;
    f>>raa>>Raa;
    f>>rab>>Rab;
    f>>rbb>>Rbb;
    f>>rbc>>Rbc;
    f>>wmin>>Wmin;
    f>>pmut>>Pmut;
    f>>pdeath>>Pdeath;
    f.close(); 
    
    std::ofstream fw;
    
    for(int T=1407; T<(T_+1); T++)
    {
      std::cout<<"T :"<<T<<std::endl;
      for(int A=0; A<(Ainit_+1); A++)
      {
        Environnement* env=new Environnement(W, H, A, D, h, Raa, Rab, Rbb, Rbc, Wmin, Pmut, Pdeath);
        
        int time=0;
        while(time<time_-T)
        {
          env -> metabolism();
          for(int i=0; i<=T; i++)
          {
            env -> diffusion();
            env -> divide();
            env -> mutation();
            env -> kill();
            env -> metabolism(); 
          }
          env -> reset(A);
          time=time+T;
        }
    
        int cptrA=0;
        int cptrB=0;
        int state=0;
    
        cptrA = env -> counter_Ga();
        cptrB = env -> counter_Gb();
        
        if(cptrA==0 && cptrB==0){
          state_[(A*T_)+(T-1)]=0;
          state=0;
        }
        else if(cptrB==0 && cptrA!=0 || cptrA==0 && cptrB!=0){
          state_[(A*T_)+(T-1)]=1;
          state=1;
        }
        else if(cptrA!=0 && cptrB!=0){
          state_[(A*T_)+(T-1)]=2;
          state=2;
        }
        
        //std::cout<<"A :"<<A<<"; state :"<<state<<std::endl;
        
        fw.open("DynamiqueSsMutation2.txt", std::ios::out | std::ios::app);
        fw<<T<<" "<<A<<" "<<state<<"\n";
        fw.close();
        
        delete env;
        env=nullptr;
        
      }
    }
  }
  
  
  void Simulation::save_picture(std::string picture_name)
  {
    int i=0;
    Phase_=new Image(T_, Ainit_+1, 255);
    for(int x=0; x<Ainit_+1; x++)
    {
      for(int y=0; y<T_; y++)
      {
        if(state_[x*T_+y]==2)    
        {
          Phase_ -> set_color(x, y, 0, 0);
          Phase_ -> set_color(x, y, 1, 0);
          Phase_ -> set_color(x, y, 2, 0);
        }
        else if(state_[x*T_+y]==1)                                     
        {
          Phase_ -> set_color(x, y, 0, 255);
          Phase_ -> set_color(x, y, 1, 0);
          Phase_ -> set_color(x, y, 2, 0);
        }
        else if(state_[x*T_+y]==0)                                  
        {
          Phase_ -> set_color(x, y, 0, 0);
          Phase_ -> set_color(x, y, 1, 255);
          Phase_ -> set_color(x, y, 2, 0);
        }
      }
    }
    Phase_ -> save(picture_name);
    delete Phase_;
    Phase_ = nullptr;
  }

// ===========================================================================
//                              Protected Methods
// ===========================================================================
