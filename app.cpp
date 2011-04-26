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
void editDrug();
void salesDrugs();

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

  
  
  
  Client *client_in = new Client();
  
  
  
  int go_to = -1;
  while(run) {
    
    
    if(go_to != -1){
      opt_phar = go_to;
      go_to = -1;
    }
    else {
      printMenuMain();
      //cin >> opt_phar;
      //cin.ignore();
      opt_phar = getInt("");
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
        
        cout << "\nFarmácia '" << name_in << "' criada com sucesso\n\n";
        
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
            name_in = getString("Introduza o novo nome? ");
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
            cout << endl;
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
            cout << endl;
            break;
            
          case 3:// Listar medicamneto
            cout << endl;
            current_pharmacy.listDrugs();
            cout << endl;
            break;
            
          case 4:// Listar cliente
            cout << endl;
            current_pharmacy.listClients();
            cout << endl;
            break;
            
          case 5:// Editar medicamento
            cout << endl;
            
            editDrug();
            
            cout << endl;
            break;
            
          case 6:// Editar cliente
            cout << endl;
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
            cout << endl;
            break;
            
          case 7:// Vender medicamento
            salesDrugs();
            break;
            
          case 8:// Menu principal 
            go_to = -1;
            break;
            
            
          case 9: // Sair
            run = false;
            break;
            
          default:
            cout << endl;
            cout << "Tente novamente..." << endl;
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

void salesDrugs(){
  Drug * sale_drug;
  Client * sale_client;
  float sale_total = 0;
  int idx;
  int id_d;
  
  cout << "Escolha na lista abaixo um ID de cliente:\n\n";
  current_pharmacy.listClients();
  cout << endl;
  
  
  
  int id_c = getInt("digite o ID? ");
  idx = current_pharmacy.existIdClients(id_c);
  
  if (idx >= 0) {
    
    sale_client = current_pharmacy.getClientByIdx(idx);
    
    bool sale_p = false;
    int _sale_p = getInt("Informe se o cliente tem receita para aplicar a comparticipação [1:sim e 2:não]? ");
    cout << endl << endl;
    if (_sale_p == 1) {
      sale_p = true;
    }
    else {
      sale_p = false;
    }

    
    cout << "Escolha na lista abaixo o ID de medicamento:\n\n";
    current_pharmacy.listDrugs();
    cout << endl;
    
    id_d = 1000;
    while(id_d > 0){
      cout << "digite o ID [-1:sair]? ";
      cin >> id_d;
      cin.ignore();
      
      idx = current_pharmacy.existIdDrugs(id_d);
      if ( idx >= 0) {
        sale_drug = current_pharmacy.getDrugByIdx(idx);
        
        cout << "Comprar: " << sale_drug->getName() << " | preço: ";
        
        if (sale_drug->getQuantity() > 0) {
          sale_drug->setQuantity(sale_drug->getQuantity() - 1);
          
          sale_total += sale_drug->getPrice(sale_p);
          cout << sale_drug->getPrice(sale_p) << endl << endl;
          
        }

      }
      else {
        cout << "Não existe stock para este medicamento\n";
      }

      
      
    }
    
    cout << "Total de vendas: " << sale_total << "€";
    cout << " para o cliente: " << sale_client->getName() << endl << endl;
    
    current_pharmacy.saveToFile();
  }

}

void editDrug(){  
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
  
  id_drug = getInt("ID do medicamento? ");
  cin.ignore();
  
  int idx = current_pharmacy.existIdDrugs(id_drug);
  if ( idx >= 0) {
    
    
    Drug * edit_drug = current_pharmacy.getDrugByIdx(idx);
    
    cout << "Registo actual:" << endl << endl;
    edit_drug->print();
    cout << endl;
    
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
    
    
    // all drugs
    edit_drug->setName(name);
    edit_drug->setLaboratory(laboratory);
    edit_drug->setExpirationDate(expiration_date);
    edit_drug->setPrice(price);
    edit_drug->setPooling(pooling);
    edit_drug->setQuantity(quantity);
    edit_drug->setStock(stock);
    
    if (typeid(*edit_drug) == typeid(Syrup)) {
      dose = getInt("Doses? ");
      type_of_casing = getString("Tipo de invólucro? ");
      
      ((Syrup*)edit_drug)->setDose(dose);
      ((Syrup*)edit_drug)->setTypeOfCasing(type_of_casing);
    }
    
    else if (typeid(*edit_drug) == typeid(Sachet)) {
      dose = getInt("Doses? ");
      ((Sachet*)edit_drug)->setDose(dose);
    }
    
    current_pharmacy.saveToFile();
    
  }  
  else {
    cout << "Não existe medicamento com este ID\n";
  }
}

int addDrug(){
  
  int opt;
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
  cout << endl << endl;
  cout << " **** Menu Principal ****" << endl;
  cout << "|----------------------|" << endl;
  cout << "|  1 - Criar Farmacia  |" << endl;
  cout << "|  2 - Abrir Farmacia  |" << endl;
  cout << "|  3 - Menu Opcoes     |" << endl;
  cout << "|  4 - Sair            |" << endl;
  cout << " ---------------------- " << endl;
  cout << "digite a opção? " << endl;
}

void printMenuOptions() {
  cout << endl << endl;
  cout << " ******* Menu Opcoes  ********" << endl;
  cout << "|****************************|" << endl;
  cout << "|   0 - Editar farmacia      |" << endl;
  cout << "|   1 - Inserir medicamento  |" << endl;
  cout << "|   2 - Inserir cliente      |" << endl;
  cout << "|   3 - Listar medicamento(s)|" << endl;
  cout << "|   4 - Listar cliente(s)    |" << endl;
  cout << "|   5 - Editar medicamento   |" << endl;
  cout << "|   6 - Editar cliente       |" << endl;
  cout << "|   7 - Vender Medicamento   |" << endl;
  cout << "|   8 - Menu Principal       |" << endl;
  cout << "|   9 - Sair                 |" << endl;
  cout << " **************************** " << endl;
  cout << "digite a opção? " << endl;
}

void printMenuDrugs() {
  cout << endl << endl;
  cout << "**Menu Tipo de Medicamento***" << endl;
  cout << "|---------------------------|" << endl;
  cout << "|   1 - Comprimido          |" << endl;
  cout << "|   2 - Xarope              |" << endl;
  cout << "|   3 - Saquetas            |" << endl;
  cout << "|   4 - Outros              |" << endl;
  cout << "|   5 - Voltar              |" << endl;
  cout << "|   6 - Sair                |" << endl;
  cout << " --------------------------- " << endl;
  cout << "digite a opção? " << endl;
}

void getdir (string dir)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error - opening " << dir << endl;
  }
  else {
    while ((dirp = readdir(dp)) != NULL) {
      if(strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0){
        cout << string(dirp->d_name) << "\n";
      }
    }
    closedir(dp);
    cout << "\nLista de IDs das famácias existentes, digite o desejado: ";
  }

  
  
  
  
}