#include "pharmacy.h"

Pharmacy::Pharmacy() {
  
  drugs_count = 0;
  drugs = new Drug*[1];
  
  clients_count = 0;
  clients = new Client*[1];
}

Pharmacy::~Pharmacy() {
}

string Pharmacy::getId() const {
  return id;
}

void Pharmacy::setId(string value) {
  id = value;
}

string Pharmacy::getName() const {
  return name;
}

void Pharmacy::setName(string value) {
  name = value;
}


void Pharmacy::addDrug(Drug *new_drug) {
  drugs[drugs_count] = new_drug;
  drugs_count++;
  expandDrugs();
}

void Pharmacy::listDrugs() {
  for (int i = 0; i < drugs_count; i++) {
    drugs[i]->print();
  }
}


void Pharmacy::addClient(Client *new_client) {
  clients[clients_count] = new_client;
  clients_count++;
  expandClients();
}

void Pharmacy::listClients() {
  for (int i = 0; i < clients_count; i++) {
    clients[i]->print();
  }
}

void Pharmacy::expandDrugs(){
  Drug ** old = drugs;
  drugs = new Drug*[drugs_count + 1];
  for (int i=0; i < drugs_count; i++) {
    drugs[i] = old[i];
  }
  delete[] old;
}

void Pharmacy::expandClients(){
  Client ** old = clients;
  clients = new Client*[clients_count + 1];
  for (int i=0; i < clients_count; i++) {
    clients[i] = old[i];
  }
  delete[] old;
}


void Pharmacy::writeDrugs(ostream &out){
  cout << "Start Write Drugs:\n";
  for (int i = 0; i < drugs_count; i++) {
    drugs[i]->write(out);
  }
}


void Pharmacy::writeClients(ostream &out){
  cout << "Start Write Clients:\n";
  for (int i = 0; i < clients_count; i++) {
    clients[i]->write(out);
  }
}

void Pharmacy::saveToFile(){
  std::fstream outToFile;
  
  //string file_name = getId() + ".txt.db";
  


  outToFile.open("db.txt", ofstream::out|ofstream::trunc);
  if(!outToFile.fail()) {
    outToFile << getName() << "\n";
    outToFile << drugs_count << "\n";
    outToFile << clients_count << "\n";
    writeDrugs(outToFile);
    writeClients(outToFile);
    outToFile.close();
  } 
  else {
    cout << "Error writing to file..." << endl;
  } 
}


void Pharmacy::readFromFile(){

  fstream inFromFile;
  inFromFile.open("db.txt", ios::in);
  if(!inFromFile.fail()) {
    
    
    string name_f_in_file;
    getline(inFromFile, name_f_in_file);
    setName(name_f_in_file);
    
    
    
    int drugs_count_in_file;
    inFromFile >> drugs_count_in_file;
    
    inFromFile.ignore();
    
    int clients_count_in_file;
    inFromFile >> clients_count_in_file;
    
    
    inFromFile.ignore();
    
    
    
    
    //START: Add Drugs in file
    for (int i= 0; i < drugs_count_in_file; i++) {
      string class_name;
      getline(inFromFile, class_name);

      int id_in_file;
      inFromFile >> id_in_file;
      inFromFile.ignore();
      
      string name_in_file;
      getline(inFromFile, name_in_file);
      
      string laboratory_in_file;
      getline(inFromFile, laboratory_in_file);
      
      //Date expiration_date_in_file;
      
      float price_in_file;
      inFromFile >> price_in_file;
      inFromFile.ignore();
      
      float pooling_in_file;
      inFromFile >> pooling_in_file;
      inFromFile.ignore();
      
      int quantity_in_file;
      inFromFile >> quantity_in_file;
      inFromFile.ignore();
      
      int stock_in_file;
      inFromFile >> stock_in_file;

      if ( class_name.compare("sachet") == 0 ) {
        int dose_in_file;
        inFromFile.ignore();
        inFromFile >> dose_in_file;
        inFromFile.ignore();
        addDrug(new Sachet(id_in_file,
                           name_in_file,
                           laboratory_in_file,
                           Date(1,1,1),
                           price_in_file,
                           pooling_in_file,
                           quantity_in_file,
                           stock_in_file,
                           dose_in_file));
        
        
      }
      
      else if ( class_name.compare("syrup") == 0 ) {
        int dose_in_file;
        inFromFile.ignore();
        inFromFile >> dose_in_file;
        inFromFile.ignore();
        string type_of_casing_in_file;
        getline(inFromFile, type_of_casing_in_file);
        
        addDrug(new Syrup(id_in_file,
                           name_in_file,
                           laboratory_in_file,
                           Date(1,1,1),
                           price_in_file,
                           pooling_in_file,
                           quantity_in_file,
                           stock_in_file,
                           dose_in_file,
                           type_of_casing_in_file));
      }
       
      else if ( class_name.compare("tablet") == 0 ) {
        inFromFile.ignore();
        addDrug(new Tablet(id_in_file,
                           name_in_file,
                           laboratory_in_file,
                           Date(1,1,1),
                           price_in_file,
                           pooling_in_file,
                           quantity_in_file,
                           stock_in_file));
      }
      
      
      else if ( class_name.compare("varied") == 0 ) {
        inFromFile.ignore();
        addDrug(new Varied(id_in_file,
                           name_in_file,
                           laboratory_in_file,
                           Date(1,1,1),
                           price_in_file,
                           pooling_in_file,
                           quantity_in_file,
                           stock_in_file));
      }
    }
    //END: Add Drugs in file
    
    //START: Add Clients in file
    for (int i=0; i < clients_count_in_file; i++) {
      int id_c_in_file;
      //inFromFile.ignore();
      inFromFile >> id_c_in_file;
      
      inFromFile.ignore();
      
      string name_c_in_file;
      getline(inFromFile, name_c_in_file);
      

      
      
      int age_c_in_file;
      inFromFile >> age_c_in_file;
      
      
      addClient(new Client(id_c_in_file, name_c_in_file, age_c_in_file));
      
      
    }
    //END: Add Clients in file
    
    
    inFromFile.close();
  }
  else {
    cout << "Error reading file..." << endl;
  }
  
}
     









