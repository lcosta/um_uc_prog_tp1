#include "syrup.h"

Syrup::Syrup() : Drug() {
  
  // configure specific unit of product
  setMeasureUnit("ml"); 
}

Syrup::~Syrup() {
}

int Syrup::getDose() const {
  return dose;
}

void Syrup::setDose(int value) {
  dose = value;
}

string Syrup::getTypeOfCasing() const {
  return type_of_casing;
}

void Syrup::setTypeOfCasing(string value) {
  type_of_casing = value;
}

