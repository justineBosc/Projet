// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Image.h"

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                Constructors
// ===========================================================================

  Image::Image(void)
  {
    w_=0;
    h_=0;
    maxVal_=0;
    data_=nullptr;
  }
  
  Image::Image(int W, int H, int maxVal)
  {
    w_=W;
    h_=H;
    maxVal_=maxVal;
    data_= new unsigned char[w_*h_*3];
    for (int i=0; i<w_*h_*3; i++)
    {
      data_[i]=0;
    }
  }
  
  Image::Image(std::string file)
  {
    std::ifstream f(file.c_str(), std::ios::in);
    std::string p6;
    f >> p6;
    f >> w_ >> h_ >> maxVal_;
    data_=new unsigned char [w_*h_*3];
    f.read((char*)data_, sizeof(unsigned char)*w_*h_*3);
    f.close();
  }
  
  Image::Image(const Image& image)
  {
    w_=image.w_;
    h_=image.h_;
    maxVal_=image.maxVal_;
    data_=new unsigned char[w_*h_*3];
    memcpy(data_, image.data_, sizeof(unsigned char)*w_*h_*3);
  }

// ===========================================================================
//                                 Destructor
// ===========================================================================

  Image::~Image(void)
  {
    delete [] data_;
    data_=nullptr;
  }

// ===========================================================================
//                               Public Methods
// ===========================================================================

  void Image::save(std::string file)
  {
    std::ofstream f(file.c_str(), std::ios::out | std::ios::trunc | std::ios::binary);
    f << "P6\n" << w_ << " " << h_ << "\n" << maxVal_ << "\n";
    f.write((char*)data_, sizeof(char)*w_*h_*3);
    f.close();
  }

// ===========================================================================
//                              Protected Methods
// ===========================================================================


