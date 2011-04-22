#include <fstream>
#include <iostream>
#include <typeinfo>
#include <string>

#include "drugs_package.h"

using namespace std;


int main() {
  
  Sachet s = Sachet();
  s.setDose(12);
  s.setQuantity(5);
  cout << s.getQuantity() << " x " << s.getDose() << s.getMeasureUnit();

  
  
  
  Syrup s1 = Syrup();
  s1.setTypeOfCasing("caixa de papel");
  s1.setQuantity(10);
  s1.setDose(900);
  s1.setStock(2000);
  cout << "\n";
  cout << s1.getQuantity() << " x " << s1.getDose() << s1.getMeasureUnit();
  cout << "\n";
  cout << s1.getTypeOfCasing();
  cout << "\n";
  cout << s1.getStock();
  
  Tablet s2 = Tablet();
  s2.setQuantity(12);
  cout << "\n";
  cout << s2.getQuantity() << s2.getMeasureUnit();
  
  Varied s3 = Varied();
  s3.setQuantity(24);
  cout << "\n";
  cout << s3.getQuantity() << s3.getMeasureUnit();
  
  
  return 0;
  
}