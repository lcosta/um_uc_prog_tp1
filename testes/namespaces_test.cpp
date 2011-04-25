//#include <string>
//#include <fstream>
#include <iostream>
#include <typeinfo>



using namespace std;
 
//using namespace std::tr1;

namespace farma
{
  string a, b;
  
  void print(){
    
    cout << "teste print";
    
  }
  
  namespace ins
  {
    void x(){
      cout << "teste x";
    }
  }
  
}



int main() {
  
  farma::ins::x();
  


  
  return 0; 
}