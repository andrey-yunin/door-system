#include<vector>
#include<string>
#include<iostream>
#include<ostream>
#include <fstream>
#include <chrono>
#include <windows.h>
#include "doorsystem.h"

// ************************timeing********************************

std::time_t card:: currentDataTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now); 
    
    return end_time;
    }

void lock:: doorOpenTimeLimit() {
    int sec = 3;
    while (sec !=0 )
{
    Sleep(1000);    //Delay  1000 msec (1 sec)
    std::cout << "Door is open: " << sec << " sec" << std::endl;
    sec--;
    
}    
}

// **************************card********************************


void card:: setupCard(){
        std:: cout << "Enter card number" << std:: endl;
        std:: cin >> number;
        std:: cin.clear();
        std:: cout << "Enter card status :" << std:: endl; 
        std:: cout << " 1 - card is available" << std:: endl;
        std:: cout << " 0 - card is blocked" << std:: endl;
        std:: cin >> access;
        std:: cin.clear();
        runtime = currentDataTime();
                      
    } 


void card:: printCard() {
        std:: cout << number << " " << access << " " << ctime(&runtime) << std:: endl;        
       }


    // *********************CARDSSTORE*************************


    void cardsStore:: creatStore(){  
       
    do 
    {   
        card Card;
        Card.setupCard();         
        cards.push_back(Card);         
        if  (checkDoubleCards())  {
            cards.pop_back();            
            std:: cout << "This card is existed enter other number" << std:: endl;            
            }                  
    } while (exit());     
     } 

    void cardsStore:: printStore(std:: vector<card> vect){ 
        //this -> vect = loadCards;
        for (int i = 0; i < vect.size(); i++) {
        vect[i].printCard(); }   

    } 

    bool cardsStore:: exit() {
        char exit;            
        
            std:: cout << "Continue? press y;  to exit press other simbol" << std:: endl;
            std:: cin >> exit;
            std:: cin.clear();
            switch (exit)        {
                case 'y': 
                return true;                        
                default: return false;                                
                break;         
                    }  
                    
        }
    bool cardsStore  :: checkDoubleCards() { 
        bool flag = false;       
        for (int n = 0; n <= cards.size(); n++)  {   
            for (int m = n+1; m <= cards.size(); m++)  {         
                if (cards[n].number == cards[m].number){
                flag = true;                               
                }                                
            }            
        }

        if (flag == true){
            return true;
        }
        else{
            return false;
            }         
    }

    void cardsStore:: saveStoreInFile(std:: vector<card> vect){
        std:: ofstream fout;
        fout.open ("cards.txt", std:: ofstream::out);
        if (!fout.is_open()) {
            std:: cout << "File is not found!" << std:: endl;
            }
        else{
            std:: cout << "File is opened" << std:: endl; 
            for (int i = 0; i < vect.size(); i++) {
                fout.write((char*)&vect[i], sizeof(card));
            }                                
            }  
        fout.close();
    }

    void cardsStore:: loadStoreFromFile(){
        std:: ifstream fin;
        fin.open("cards.txt");
        if (!fin.is_open()) {
            std:: cout << "File is not found!" << std::endl;
            }
        else{
            std:: cout << "File is opened" << std:: endl;
            card upLoadCard; 
            loadCards.clear();                                    
            while (fin.read((char*)&upLoadCard, sizeof(card)))
            {            
             loadCards.push_back(upLoadCard);
                } 
        }
    fin.close();
    }  



    void cardsStore:: changeCardStatus() {
        int cardNumber;
        std:: cout << "Select card number to change access status: " ;
        std:: cin >> cardNumber;
        std:: cin.clear();
        int i =0; 
        while (loadCards[i].number != cardNumber) {i++;}
                loadCards[i].printCard();
                std:: cout << "select other access status. Enter: " << std:: endl;
                std:: cout << " 1 - card is available" << std:: endl;
                std:: cout << " 0 - card is blocked" << std:: endl;
                std::  cin >> loadCards[i].access;
                std:: cin.clear(); 
                loadCards[i].runtime = currentDataTime();
                loadCards[i].printCard();
    }


//*********************lock***************************


void lock:: doorControl(bool key)  {

     enum doorstate {
        doorIsLocked,
        doorIsUnlocked
    };

    bool exit = false; 
    doorstate doorState = doorIsLocked;
    

    while(exit != true){
    
        switch(doorState) {
        case doorIsLocked:
        key;
        if (key == true)
        {
          doorState = doorIsUnlocked;
        }
        
            else  {
                std:: cout << "Door is locked. Lamp is: off" << std:: endl;
                exit = true;
            }
        
        break;        

        case doorIsUnlocked: 

        std:: cout << "Door is unlocked. Lamp is: green" << std:: endl;       
        doorOpenTimeLimit();
        key = false;
        doorState = doorIsLocked; 
        break;      

    }  
    } 



}

void lock::remoteDoorOpen()  {
    doorControl(lockOpenKey);
    std:: cout << "To open door select 1: ";
    std:: cin >> lockOpenKey;
    std:: cin.clear();
    doorControl(lockOpenKey);
    lockOpenKey=false;
}


void lock:: testScanCard() {
    loadStoreFromFile();
    printStore(loadCards);
    int cardNumber;
    std:: cout << "Enter card number to open door : ";
    std:: cin >> cardNumber;
    std:: cin.clear();
    int i=0;
    while (loadCards[i].number != cardNumber) {i++;}
    if (loadCards[i].access == false) {
        std:: cout << "Card is blocked it. Door can't be open" << std:: endl;
    }
    else 
    {
        lockOpenKey = true;
        doorControl(lockOpenKey);
        lockOpenKey = false;
    }
}

     




   
               
        
    
