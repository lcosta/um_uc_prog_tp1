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
void printMenuDrugs();
void getdir (string dir);
int addDrug();

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
    cout << "\nintroduza um valor maior que 0.\n";
    return getInt(msg);
  }
  
  return i;
}

float getFloat(string msg){
  float i;
  
  cout << msg;
  cin >> i;
  
  if (i <= 0) {
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
  int int_in;
  
  
  
  Client *client_in = new Client();
  
  Tablet *tablet_in = new Tablet();
  Syrup *syrup_in = new Syrup();
  Sachet *sachet_in = new Sachet();
  Varied *varied_in = new Varied();
  
  
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
        opt_phar = getInt("Indique o código da farmácia? ");
        cin.ignore();
        name_in = getString("Indique o nome da farmácia? ");
        current_pharmacy = Pharmacy();
        current_pharmacy.setId(opt_phar);
        current_pharmacy.setName(name_in);
        current_pharmacy.saveToFile();
        
        break;
        
      case 2: // Abrir Farmacia
        cout << "Escolha o ID da Farmacia a abrir:\n";
        getdir("./db");
        //cin >> opt_phar;
        opt_phar = getInt("");
        cin.ignore();
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
            printMenuDrugs();
            go_to = addDrug();
            
            if (go_to == -1) {
              run = false;
            }

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


int addDrug(){
  
  int opt, int_in;
  int go_to = 3;
  
  int id_drug;
  string name;
  string laboratory;
  Date expiration_date;
  int day, month, year;
  float price;
  float pooling;
  int quantity;
  int stock;
  
  int dose;
  string type_of_casing;
  
  
  cin >> opt;
  cin.ignore();
  
  id_drug = getInt("ID do medicamento? ");
  cin.ignore();
  
  
  if (current_pharmacy.existIdDrugs(id_drug) == -1) {
    
    
    name = getString("Nome do medicamento? ");
    laboratory = getString("Nome do laboratório? ");
    
    cout << "Data de validade:\n";
    year = getInt("ano? ");
    cin.ignore();
    month = getInt("mês? ");
    cin.ignore();
    day = getInt("dia? ");
    expiration_date = Date(day, month, year);
    
    price = getFloat("Preço? ");
    pooling = getFloat("Valor de comparticipação? ");
    quantity = getInt("Quantidade por caixa? ");
    stock = getInt("Stock? ");
    
    
    
    
    switch (opt) {
      case 1: //Comprimido
        current_pharmacy.addDrug(new Tablet(id_drug,
                                            name,
                                            laboratory,
                                            expiration_date,
                                            price,
                                            pooling,
                                            quantity,
                                            stock));
        break;
      case 2: //Xarope
        
        dose = getInt("Doses? ");
        type_of_casing = getString("Tipo de invólucro? ");        
        current_pharmacy.addDrug(new Syrup(id_drug,
                                       name,
                                       laboratory,
                                       expiration_date,
                                       price,
                                       pooling,
                                       quantity,
                                       stock,
                                       dose,
                                       type_of_casing));
        break;
      case 3: //Saquetas
        
        dose = getInt("Doses? ");
        current_pharmacy.addDrug(new Sachet(id_drug,
                                           name,
                                           laboratory,
                                           expiration_date,
                                           price,
                                           pooling,
                                           quantity,
                                           stock,
                                           dose));
        
        break;
      case 4: //Outros
        
        current_pharmacy.addDrug(new Varied(id_drug,
                                            name,
                                            laboratory,
                                            expiration_date,
                                            price,
                                            pooling,
                                            quantity,
                                            stock));
        
        break;
      case 5: //Voltar
        
        break;
      case 6: //Sair
        go_to = -1;
        break;
      default:cout << "Tente novamente..." << endl;
        break;
    }
    
    current_pharmacy.saveToFile();
    
  }  
  else {
    cout << "Já existe medicamento com este ID\n";
  }
  
  return go_to;
  
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

void printMenuDrugs() {
  std::cout << "**Menu Tipo de Medicamento***" << std::endl;
  std::cout << "|---------------------------|" << std::endl;
  std::cout << "|   1 - Comprimido          |" << std::endl;
  std::cout << "|   2 - Xarope              |" << std::endl;
  std::cout << "|   3 - Saquetas            |" << std::endl;
  std::cout << "|   4 - Outros              |" << std::endl;
  std::cout << "|   5 - Voltar              |" << std::endl;
  std::cout << "|   6 - Sair                |" << std::endl;
  std::cout << " -------------------------- " << std::endl;
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