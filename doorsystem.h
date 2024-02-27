#include<vector>
#include<string>
#include<iostream>
#include<ostream>
#include <chrono>


#ifndef __DOOR_SYSTEM_H
#define __DOOR_SYSTEM_H


class card {
    public:   
    int number =0;
    bool access = true;
    std:: time_t runtime; 

    public:
    void setupCard();      
    std:: time_t currentDataTime();
    void printCard();
};




class cardsStore:  public card {
       
    public:   
    
    std:: vector<card> cards;
    std:: vector<card> loadCards;       

    public: 
    bool exit(); 
    void creatStore();
    bool checkDoubleCards();
    void printStore(std:: vector<card> vect);
    void loadStoreFromFile();
    void saveStoreInFile(std:: vector<card> vect);
    void changeCardStatus();
};  

class lock : public cardsStore {
    
    public:
    bool lockOpenKey = false;
      
    public:
    void doorOpenTimeLimit();
    bool cardNumberIsScanned();
    void doorControl(bool);
    void remoteDoorOpen();
    void testScanCard();

};

class menu: public lock

{
public:
    int position;
public:
    void menuForDoorsystem();
    
};





#endif // __DOOR_SYSTEM_H