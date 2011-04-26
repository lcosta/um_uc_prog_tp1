#include <fstream>
#include <iostream>
#include <typeinfo>
#include <string>
#include <dirent.h>

#include "drugs_package.h"

#include "pharmacy.h"






using namespace std;


Pharmacy current_pharmacy = Pharmacy();



void printMenuMain();
void printMenuOptions();
void getdir (string dir);


string getString(string msg){
  string s;
  
  cout << msg;
  getline (cin,s);
  
  if (s.length() == 0) {
    cout << "\nintroduza um nome valido.\n";
    return getString(msg);
  }
  
  return s;
}

int getInt(string msg){
  int i;
  
  cout << msg;
  cin >> i;
  
  if (i <= 0) {
    cin.ignore();
    cout << "\nintroduza um valor maior que 0.\n";
    return getInt(msg);
  }
  
  return i;
}

int main() {
  
  bool run = true;
  int opt;
  int opt_phar;
  string name_in;
  
  Client *client_in = new Client();
  
  int go_to = -1;
  while(run) {
    
    
    if(go_to != -1){
      opt_phar = go_to;
      go_to = -1;
    }
    else {
      printMenuMain();
      cin >> opt_phar;
      cin.ignore();
    }

    
    
    switch (opt_phar) {
        
      case 1: // Criar Farmacia
        break;
        
      case 2: // Abrir Farmacia
        cout << "Escolha a Farmacia (sem .txt):\n";
        getdir("./db");
        cin >> opt_phar;
        current_pharmacy.readFromFile(opt_phar);
        current_pharmacy.setId(opt_phar);
        cout << "A farmacia '" << current_pharmacy.getName() << "' foi carregada.\n";
        go_to = 3;
        break;
    
        
      case 3: // Menu opcoes
        printMenuOptions();
        
        cin >> opt;
        cin.ignore();
        go_to = 3;
        switch (opt) {
            
          case 0:// Editar Farmacia
            
            cout << "Introduza o novo nome? ";
            
            current_pharmacy.setName(name_in);
            
            current_pharmacy.saveToFile();
            
            cout << "O nome da farmacia foi alterado para '" << current_pharmacy.getName() << "'.\n";
            
            break;
            
          case 1:// Inserir medicamento
            break;
            
          case 2:// Inserir cliente
            opt = getInt("ID do cliente? ");
            cin.ignore();
            if (current_pharmacy.existIdClients(opt) == -1) {
              
              client_in->setId(opt);
              
              client_in->setName(getString("Nome do cliente? "));
              
              client_in->setAge(getInt("Idade do cliente? "));
              cin.ignore();
              current_pharmacy.addClient(client_in);
              
              current_pharmacy.saveToFile();
            }
            else {
              cout << "Já existe cliente com este ID\n";
            }

            break;
            
          case 3:// Listar medicamneto
            current_pharmacy.listDrugs();
            break;
            
          case 4:// Listar cliente
            current_pharmacy.listClients();
            break;
            
          case 5:// Editar medicamento
            break;
            
          case 6:// Editar cliente
            opt = getInt("ID do cliente? ");
            cin.ignore();
            if (current_pharmacy.existIdClients(opt) != -1) {
              
              client_in->setId(opt);
              
              client_in->setName(getString("Nome do cliente? "));
              
              client_in->setAge(getInt("Idade do cliente? "));
              cin.ignore();
              current_pharmacy.editClient(opt, client_in);
              
              current_pharmacy.saveToFile();
            }
            else {
              cout << "Não existe cliente com este ID\n";
            }
            
            
            
            
            break;
            
          case 7:// Vender medicamento
            break;
            
          case 8:// Menu principal 
            go_to = -1;
            break;
            
            
          case 9: // Sair
            run = false;
            break;
            
          default:cout << "Tente novamente..." << endl;
            break;
        }
        
        break;
        
      case 4:// Sair 
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
  std::cout << "|  2 - Abrir Farmacia  |" << std::endl;
  std::cout << "|  3 - Menu Opcoes     |" << std::endl;
  std::cout << "|  4 - Sair            |" << std::endl;
  std::cout << " ---------------------- " << std::endl;
}

void printMenuOptions() {
  std::cout << " ******* Menu Opcoes  ********" << std::endl;
  std::cout << "|****************************|" << std::endl;
  std::cout << "|   0 - Editar farmacia      |" << std::endl;
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

void getdir (string dir)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error - opening " << dir << endl;
  }
  
  while ((dirp = readdir(dp)) != NULL) {
    if(strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0){
      cout << string(dirp->d_name) << "\n";
    }
  }
  closedir(dp);
}