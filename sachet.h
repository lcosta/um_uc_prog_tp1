#ifndef _sachet_h_
#define _sachet_h_

#include "drug.h"


class Sachet : public Drug {
protected:
  int dose;
  
public:
  Sachet();	
  ~Sachet();

  // START: gets and sets
  // END: gets and sets  
  
  virtual int getDose() const;
  virtual void setDose(int value);
  
  // START: methods
  
  // END: methods
  

};

#endif