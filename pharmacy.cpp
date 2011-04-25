#include "pharmacy.h"

Pharmacy::Pharmacy() {
  
  drugs_count = 0;
  drugs = new Drug*[100]; // ToDo: implementar expanção de array
  
  clients_count = 0;
  clients = new Client*[100]; // ToDo: implementar expanção de array
}

Pharmacy::~Pharmacy() {
}

int Pharmacy::getId() const {
  return id;
}

void Pharmacy::setId(int value) {
  id = value;
}

string Pharmacy::getName() const {
  return name;
}

void Pharmacy::setName(string value) {
  name = value;
}

void Pharmacy::addDrug1(Drug *new_drug, Drug *new_drug2, Drug *new_drug3) {

  
  /*
   if (drugs_count == 0) {
   drugs = new Drug*[1];
   }
   */
  
  //Drug ** old_drugs = drugs;
  //drugs_count++;
  //drugs = new Drug*[drugs_count];
  
  /*
  for(int i = 0; i < drugs_count; i++) {
    drugs[i] = old_drugs[i];
  }
  */
  
  drugs[0] = new_drug;
  drugs[1] = new_drug2;
  drugs[2] = new_drug3;
  
  cout << drugs[0]->getName() << "\n";
  cout << drugs[1]->getName() << "\n";
  cout << drugs[2]->getName() << "\n";
  

  
  //delete[] old_drugs;
  
  //cout << drugs_count;

}

void Pharmacy::addDrug(Drug new_drug) {
  
  
  
  drugs[drugs_count] = &new_drug;
  
  drugs_count++;
  
  // ToDo: implementar expanção de array
  /*
  Drug ** old_drugs = drugs;
  drugs = new Drug*[drugs_count+1];
  
  for(int i = 0; i < drugs_count-1; i++) {
    drugs[i] = old_drugs[i];
  }
   
   */
  
}

void Pharmacy::listDrugs() {
  for(int i = 0; i < drugs_count; i++) {
    cout << " -> " << drugs[i]->getName() << "\n";
    cout << typeid(*drugs[i]).name() << "\n";
  }
}


void Pharmacy::addClient(Client new_client) {
  
  
  
  clients[clients_count] = &new_client;
  
  clients_count++;
  
  // ToDo: implementar expanção de array
  /*
  Drug ** old_drugs = drugs;
  drugs = new Drug*[drugs_count+1];
  
  for(int i = 0; i < drugs_count-1; i++) {
    drugs[i] = old_drugs[i];
  }
   
   */
  
}

void Pharmacy::listClients() {
  for(int i = 0; i < clients_count; i++) {
    cout << " -> " << clients[i]->getName() << "\n";
  }
}




/*
void expand() {
	std::cout << " Expanding..." << std::endl;
	Vehicle ** old = vehicles;
	currentSize = 2*currentSize;
	vehicles = new Vehicle*[currentSize];
	
	for( int i = 0; i < n_vehicles; i++) {
		vehicles[i] = old[i];
	}
	delete[] old;
}
*/