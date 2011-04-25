#include "client.h"

Client::Client() {
  
}

Client::~Client() {
}

int Client::getId() const {
  return id;
}

void Client::setId(int value) {
  id = value;
}

string Client::getName() const {
  return name;
}

void Client::setName(string value) {
  name = value;
}

int Client::getAge() const {
  return age;
}

void Client::setAge(int value) {
  age = value;
}