#include<vector>
#include<string>
#include<iostream>
#include<ostream>
#include <fstream>
#include "doorsystem.h"


void menu:: menuForDoorsystem(){
    const int exitFromMenu = 6;  

    
     while (position != exitFromMenu) {

    std:: cout << "******************Admin Menu*********************" << std:: endl;
    std:: cout << "1. Remote open door" << std:: endl;
    std:: cout << "2. List all cards in system" << std:: endl;
    std:: cout << "3. Add/remove access" << std:: endl;
    std:: cout << "4. Create new store" << std:: endl;
    std:: cout << "5. Test Card Scanning" << std:: endl;
    std:: cout << "6. Exit" << std:: endl;

    std:: cout << "Select menu position :";
    std:: cin >> position;
    std:: cin.clear();
    system("cls"); 

        switch (position)
    {
    case 1:
        std:: cout << "in pipeline" << std:: endl;
        remoteDoorOpen();
        break;
    
    case 2:
        loadStoreFromFile();
        printStore(loadCards);
        break;
    
    case 3:
        loadStoreFromFile();
        printStore(loadCards);
        changeCardStatus();
        saveStoreInFile(loadCards);        
        break;
    
    case 4:
        creatStore();
        saveStoreInFile(cards);
        break;

    case 5:
        testScanCard();
        break;
    
    case 6:
        break;
    
    default: std:: cout << "Enter position from Menu" << std:: endl;
        break;
    }
     
    } 
}