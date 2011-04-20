#include "sachet.h"

Sachet::Sachet() : Drug() {
  
  // configure specific unit of product
  setMeasureUnit("gr"); 
}

Sachet::~Sachet() {
}

int Sachet::getDose() const {
  return dose;
}

void Sachet::setDose(int value) {
  dose = value;
}
