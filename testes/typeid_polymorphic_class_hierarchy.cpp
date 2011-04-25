#include <string>
#include <iostream>
#include <typeinfo>
//#include <fstream.h>
using namespace std;
class Mammal {
public:
  string name;
  
  virtual bool laysEggs() { 
    return false; 
  }
  virtual string getName(){
    return name;
  }
  
  void write(std::ostream &out){
    out << name << endl;
    
  }
};
class Cat: public Mammal {
public:
  string eye;
  Cat(string const n){
    name = n;
    eye = "blue";
    cout << "Init Class Cat with: " << name << "\n";
    
  }
  
  void write(std::ostream &out){
    Mammal::write(out);
    out << eye << endl;
  }
  
};
class Platypus: public Mammal {
public:
  Platypus(string const n){
    name = n;
    cout << "Init Class Platypus with: " << name << "\n";
    
  }
  bool laysEggs() { 
    return true; 
  }
  /*
  void write(std::ostream &out){
    Mammal::write(out);
  }
  */
};




class Data {
protected:
  Mammal ** db;
  int count;
  
public:
  Data() {
    cout << "init Data\n";
    db = new Mammal*[1];
    count = 0;
  }
  
  void addCat(string const &n){
    Cat *c = new Cat(n);
    db[count] = c;
    count++;
    
    expand();
    
  }
  
  void expand(){
    Mammal ** old = db;
    db = new Mammal*[count + 1];
    for (int i=0; i < count; i++) {
      db[i] = old[i];
    }
    delete[] old;
  }
  
  void add(Mammal *m){
    //Cat *c = new Cat(n);
    //Cat x =  Cat("nome");
    db[count] = m;
    count++;
    expand();
  }
  
  void list(){
    //cout << typeid(*db[0]).name();
    cout << "\nData List\n";
    for (int i = 0; i < count; i++) {
      cout << "Print: " << ((Cat*)db[i])->name << "\n";
      cout << typeid(*db[i]).name() << endl;
    }
  }
  
  
  
};

Mammal ** p;


void  create(){
  
  /*
   Mammal AnyMammal;
   Cat cat;
   Platypus platypus;
   */
  
  p[0] = new Mammal;
  p[1] = new Cat("Field");
  p[2] = new Platypus("xx");
  
  ///cout << p[1]->name;
  
  //cout << ((Mammal*)p[1])->name;
  
  //cout << (*p[1])->name;
  
  /*
   p[0] = &AnyMammal;
   p[1] = &cat;
   p[2] = &platypus;
   */
}

void list(){
  cout << "p is pointing to an object of type ";
  cout << typeid(*p[0]).name() << endl;
  
  cout << "p is pointing to an object of type ";
  cout << typeid(*p[1]).name() << endl;
  
  cout << "p is pointing to an object of type ";
  cout << typeid(*p[2]).name() << endl;
}




Data d = Data();

int main()
{

  
  //p = new Mammal*[10];
  //create();
  //list();
  
  
  
  //Data d = Data();
  //d = new Data;
  
  
  
  d.addCat("gato 1");
  d.addCat("gato 2");
  d.addCat("gato 3");

  Cat *c3;
  c3 = new Cat("Field");
  d.add(c3);
  
  d.add(new Cat("Field1000"));
  d.add(new Platypus("platypus 1"));
  
  
  d.list();
  
  //write_to_binary_file(d);
  
  /*
   Cat *c;
   c = new Cat;
   d.add(&c);
   */
  

  c3->name = "x1";
  Platypus *pl = new Platypus("platypus 1");
  
  cout << "TESTE WRITE:\n";
  c3->write(std::cout);
  pl->write(std::cout);
  cout << "TESTE WRITE:\n";
  
  cout << c3->getName() << "\n";
  cout << c3->name << "\n";
  
  
  cout << "END\n";
  
  
  
  return 0;
}