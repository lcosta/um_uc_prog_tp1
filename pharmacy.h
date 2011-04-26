#ifndef _pharmacy_h_
#define _pharmacy_h_

#include "drugs_package.h"
#include "client.h"
#include "date.h"


class Pharmacy {
protected:
  int id;
  string name;
  
  Drug ** drugs;
  int drugs_count;
  
  Client ** clients;
  int clients_count;
  
public:
  Pharmacy();	
  ~Pharmacy();

  // START: gets and sets
  int getId() const;
  void setId(int value);

  string getName() const;
  void setName(string value);
  // END: gets and sets  
  
  
  // START: methods
  void addDrug(Drug *new_drug);
  void listDrugs();
  
  void addClient(Client *new_client);
  void listClients();
  
  void expandDrugs();
  void expandClients();
  
  void writeDrugs(ostream &out);
  void writeClients(ostream &out);
  void saveToFile();
  void readFromFile(int open_id);
  
  // END: methods
  

};

#endif