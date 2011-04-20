#ifndef _syrup_h_
#define _syrup_h_

#include "drug.h"


class Syrup : public Drug {
protected:
  int dose;
  string type_of_casing;
  
public:
  Syrup();	
  ~Syrup();

  // START: gets and sets
  virtual int getDose() const;
  virtual void setDose(int value);
  virtual string getTypeOfCasing() const;
  virtual void setTypeOfCasing(string value);

  // END: gets and sets  
  
  
  // START: methods
  
  // setar -> measure_unit and id
  
  // END: methods
  

};

#endif