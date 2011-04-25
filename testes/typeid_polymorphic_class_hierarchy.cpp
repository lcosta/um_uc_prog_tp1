#include <string>
#include <iostream>
#include <typeinfo>
#include <fstream.h>
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
    // propriedades comuns
    out << name;
    
  }
};
class Cat: public Mammal {
public:
  string eye;
  Cat(string const n, string e){
    name = n;
    eye = e;
    cout << "Init Class Cat with: " << name << "\n";
    
  }
  
  void write(std::ostream &out){
    out << "cat\n";
    Mammal::write(out);
    out << "\n";
    out << eye << "\n";
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
  
  void write(std::ostream &out){
    out << "platypus\n";
    Mammal::write(out);
    out << "\n";
  }
  
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
    Cat *c = new Cat(n, "red");
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
      //cout << typeid(*db[i]).name() << endl;
    }
  }
  
  void write(ostream &out){
    cout << "Start Write Data:\n";
    out << count << "\n";
    for (int i = 0; i < count; i++) {
      if ( typeid(*db[i]) == typeid(Cat) ) {
        ((Cat*)db[i])->write(out);
      }
      else if ( typeid(*db[i]) == typeid(Platypus) ) {
        ((Platypus*)db[i])->write(out);
      }
      
    }
    
    cout << "End Write Data:\n";
  }
  
  
  void saveToFile(){
   	std::fstream outToFile;
    outToFile.open("data.txt", ofstream::out|ofstream::trunc);
    if(!outToFile.fail()) {
      write(outToFile);
      outToFile.close();
    } 
    else {
      cout << "Error writing to file..." << endl;
    } 
  }
  
  
  void readFromFile(){
   
    fstream inFromFile;
    inFromFile.open("data.txt", ios::in);
    if(!inFromFile.fail()) {
      
      int count_in_file;
      inFromFile >> count_in_file; // lê o número de veículos no ficheiro
      inFromFile.ignore(); // para saltar por cima do caractere de mudança de linha ('\n')
      
      for (int i= 0; i < count_in_file; i++) {
        string class_name;
        getline(inFromFile, class_name);

       
        string name;
        getline(inFromFile, name);
        if ( class_name.compare("cat") == 0 ) {
          string eye;
          getline(inFromFile, eye);
          add(new Cat(name, eye));
          
        }
        else if ( class_name.compare("platypus") == 0 ) {
          add(new Platypus(name));
        }
        
        
      }
      
      /*
      // cria um array para veículo com o dobro da dimensão do nº actual
      currentSize = n_vehicles * 2; 
      vehicles = new Vehicle*[currentSize];
      
      //lê o estado de cada um dos veículos
      for(int i = 0; i < n_vehicles; i++) {
        std::string s;
        getline(inFromFile, s);
        if(s.compare(typeid(Vehicle).name()) == 0) { // verifica qual o tipo de objecto
          vehicles[i] = Vehicle::read(inFromFile);
        }
        else {
          vehicles[i] = MotorVehicle::read(inFromFile);
        }
        inFromFile.ignore(); // para saltar por cima do caractere de mudança de linha ('\n')
      }
      
      */
      
      //
      //readFrom(inFromFile);
      
      
      inFromFile.close();
    }
    else {
      cout << "Error reading file..." << endl;
      // inicializar o array de veículos
      //currentSize = 2;
      //vehicles = new Vehicle*[currentSize];
      //n_vehicles = 0;
    }
    
  }
  
};





  //Mammal ** p;
  //p[0] = new Mammal;
  //p[1] = new Cat("Field");
  //p[2] = new Platypus("xx");
  
  //cout << "p is pointing to an object of type ";
  //cout << typeid(*p[0]).name() << endl;





Data d = Data();

int main()
{

  
  d.readFromFile();
  d.list();
  
  /*
  
  //d.addCat("gato 1");
  //d.addCat("gato 2");
  //d.addCat("gato 3");

  Cat *c3;
  c3 = new Cat("Field", "blue");
  d.add(c3);
  
  d.add(new Cat("Field1000", "green"));
  d.add(new Platypus("platypus 1"));
  
  
  d.list();
  

  c3->name = "x1";
  Platypus *pl = new Platypus("platypus 1");
  
  cout << "TESTE WRITE:\n";
  c3->write(std::cout);
  pl->write(std::cout);
  cout << "TESTE WRITE:\n";
  
  cout << c3->getName() << "\n";
  cout << c3->name << "\n";
  
  
  //d.write(cout);
  
  d.saveToFile();
   
   
   */
  
  cout << "END\n";
  
  
  
  return 0;
}