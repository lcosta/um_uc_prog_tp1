#include <fstream>
#include <iostream>
#include <typeinfo>
#include <string>

#include "drugs_package.h"

#include "pharmacy.h"






using namespace std;


Pharmacy current_pharmacy = Pharmacy();



void printMenuMain();
void printMenuOptions();


int main() {
  
  
  
  current_pharmacy.setId("100");
  
  

  current_pharmacy.readFromFile();
  
  //current_pharmacy.addClient(new Client(1,"mosca",27));
  //current_pharmacy.addClient(new Client(1,"sapo",25));
  
  current_pharmacy.listClients();
  
  /*
  current_pharmacy.addDrug(new Sachet(1,
                                      "Sachet 1",
                                      "lab 1",
                                      Date(1,1,1),
                                      10.50,
                                      0.15,
                                      10,
                                      201,
                                      6));
  
  current_pharmacy.addDrug(new Syrup(1,
                                     "Syrup 1",
                                     "lab 1",
                                     Date(1,1,1),
                                     15.50,
                                     0.65,
                                     10,
                                     202,
                                     5,
                                     "vidro"));
  
  current_pharmacy.addDrug(new Tablet(1,
                                      "Tablet 1",
                                      "lab 1",
                                      Date(1,1,1),
                                      25.50,
                                      0.25,
                                      10,
                                      203));
  
  current_pharmacy.addDrug(new Varied(1,
                                  "Varied 1",
                                  "lab 1",
                                  Date(1,1,1),
                                  35.50,
                                  0.50,
                                  10,
                                  204));
  
  */
  
  current_pharmacy.listDrugs();
  
  current_pharmacy.setName("farma 1");
  
  //current_pharmacy.saveToFile();
  

  
  bool run = true;
  int opt;
  int opt_phar;
  
  while(run) {
    printMenuMain();
    cin >> opt_phar;
    
    switch (opt_phar) {
        
      case 1: // Criar Farmacia
        break;
        
      case 2: // Editar Farmacia
        break;
        
      case 3:
        break; // Listar Farmacia
        
      case 4: // Menu opcoes
        printMenuOptions();
        cin >> opt;
        
        switch (opt) {
            
            
          case 1:// Inserir medicamento
            break;
            
          case 2:// Inserir cliente 
            break;
            
          case 3:// Listar medicamneto
            break;
            
          case 4:// Listar cliente
            break;
            
          case 5:// Editar medicamento
            break;
            
          case 6:// Editar cliente 
            break;
            
          case 7:// Vender medicamento
            break;
            
          case 8:// Menu principal 
            break;
            
            
          case 9: // Sair
            run = false;
            break;
            
          default:cout << "Tente novamente..." << endl;
            break;
        }
        
        break;
        
      case 5:// Sair 
        run = false;
        break;
      default:cout << "Tente novamente..." << endl;
        break;

    }
  }
  
  return 0;
  
}


void printMenuMain() {
  std::cout << " **** Menu Principal ****" << std::endl;
  std::cout << "|----------------------|" << std::endl;
  std::cout << "|  1 - Criar Farmacia  |" << std::endl;
  std::cout << "|  2 - Editar Farmacia |" << std::endl;
  std::cout << "|  3 - Listar Farmacia |" << std::endl;
  std::cout << "|  4 - Menu Opcoes     |" << std::endl;
  std::cout << "|  5 - Sair            |" << std::endl;
  std::cout << " ---------------------- " << std::endl;
}

void printMenuOptions() {
  std::cout << " ******* Menu Opcoes  ********" << std::endl;
  std::cout << "|****************************|" << std::endl;
  std::cout << "|   1 - Inserir medicamento  |" << std::endl;
  std::cout << "|   2 - Inserir cliente      |" << std::endl;
  std::cout << "|   3 - Listar medicamento(s)|" << std::endl;
  std::cout << "|   4 - Listar cliente(s)    |" << std::endl;
  std::cout << "|   5 - Editar medicamento   |" << std::endl;
  std::cout << "|   6 - Editar cliente       |" << std::endl;
  std::cout << "|   7 - Vender Medicamento   |" << std::endl;
  std::cout << "|   8 - Menu Principal       |" << std::endl;
  std::cout << "|   9 - Sair                 |" << std::endl;
  std::cout << " **************************** " << std::endl;
}