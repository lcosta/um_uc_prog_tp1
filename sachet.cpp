#include "sachet.h"

Sachet::Sachet() : Drug() {
  
  // configure specific unit of product
  setMeasureUnit("gr"); 
}


Sachet::Sachet(int const _id,
               string const  _name,
               string const  _laboratory,
               Date const  _date,
               float const  _price,
               float const  _pooling,
               int const  _quantity,
               int const  _stock,
               
               int const  _dose) : Drug() {
  
  setMeasureUnit("gr");
  
  setId(_id);
  setName(_name);
  setLaboratory(_laboratory);
  setExpirationDate(_date);
  setPrice(_price);
  setPooling(_pooling);
  setQuantity(_quantity);
  setStock(_stock);
  
  setDose(_dose);
  
}


Sachet::~Sachet() {
}

int Sachet::getDose() const {
  return dose;
}

void Sachet::setDose(int value) {
  dose = value;
}
