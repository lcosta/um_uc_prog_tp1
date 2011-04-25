#include "drug.h"

Drug::Drug() {

}

Drug::~Drug() {
}

// START: gets and sets

int Drug::getId() const {
  return id;
}

void Drug::setId(int value) {
  id = value;
}

string Drug::getName() const {
  return name;
}

void Drug::setName(string value) {
  name = value;
}

string Drug::getLaboratory() const {
  return laboratory;
}

void Drug::setLaboratory(string value) {
  laboratory = value;
}

Date Drug::getExpirationDate() const {
  return expiration_date;
}

void Drug::setExpirationDate(Date value) {
  expiration_date = value;
}

float Drug::getPrice() const {
  return price;
}

void Drug::setPrice(float value) {
  price = value;
}

float Drug::getPooling() const {
  return pooling;
}

void Drug::setPooling(float value) {
  pooling = value;
}

string Drug::getMeasureUnit() const {
  return measure_unit;
}

void Drug::setMeasureUnit(string value) {
  measure_unit = value;
}

int Drug::getQuantity() const {
  return quantity;
}

void Drug::setQuantity(int value) {
  quantity = value;
}

int Drug::getStock() const {
  return stock;
}

void Drug::setStock(int value) {
  stock = value;
}

// END: gets and sets


// START: methods
float Drug::getPricePooling(){
  return 0;
};
// END: methods
