#ifndef _pharmacy_h_
#define _pharmacy_h_

#include "drug.h"
#include "client.h"

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
  void addDrug1(Drug *new_drug, Drug *new_drug2, Drug *new_drug3);
  void addDrug(Drug new_drug);
  void listDrugs();
  
  void addClient(Client new_client);
  void listClients();
  // END: methods
  

};

#endif