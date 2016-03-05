#ifndef IMAGE_H__
#define IMAGE_H__

// ===========================================================================
//                                  Includes
// ===========================================================================

#include <iostream>
#include <fstream>
#include <cstring>


class Image{
  
public:
// =========================================================================
//                               Constructors
// =========================================================================
  
  Image(void);
  Image(int W, int H, int maxVal);
  Image(std::string file);
  Image(const Image& image);

// =========================================================================
//                                Destructor
// =========================================================================

  ~Image(void);

// =========================================================================
//                                  Getters
// =========================================================================
  
  inline int get_w(void) const;
  inline int get_h(void) const;
  inline int get_maxVal(void) const;
  inline unsigned char get_color(int x, int y, int c);

// =========================================================================
//                                  Setters
// =========================================================================

  inline void set_w(int w);
  inline void set_h(int h);
  inline void set_maxVal(int maxVal);
  inline void set_color(int x, int y, int c, unsigned char val);
  
// =========================================================================
//                                 Operators
// =========================================================================

// =========================================================================
//                              Public Methods
// =========================================================================

  void save(std::string file);

protected :
// =========================================================================
//                             Protected Methods
// =========================================================================

// =========================================================================
//                                Attributes
// =========================================================================

  int w_;                   //Image width (pixels)
  int h_;                   //Image height (pixels)
  int maxVal_;              //Maximum canal value
  unsigned char* data_;     //Image data


};

// ===========================================================================
//                            Getters' definitions
// ===========================================================================
 
 inline int Image::get_w(void) const{
   return w_;
 }
 
 inline int Image::get_h(void) const{
   return h_;
 }
 
 inline int Image::get_maxVal(void) const{
   return maxVal_;
 }
 
 inline unsigned char Image::get_color(int x, int y, int c){
   return data_[(x*h_+y)*3+c];
 }
 
// ===========================================================================
//                            Setters' definitions
// ===========================================================================
  
  inline void Image::set_w(int w){
    w_=w;
  }
  
  inline void Image::set_h(int h){
    h_=h;
  }
  
  inline void Image::set_maxVal(int maxVal){
    maxVal_=maxVal;
  }
  
  inline void Image::set_color(int x, int y, int c, unsigned char val){
    data_[(x*h_+y)*3+c]=val;
  }
  
// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================
	

#endif // IMAGE_H__


