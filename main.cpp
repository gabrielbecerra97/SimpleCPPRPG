#include <iostream>
#include <stdexcept>
#include <string>
#include <chrono>
#include <thread>
#include "headers/SaveFileHandler.h"

using namespace std;

void output (string outputString) {
    chrono::milliseconds duration(500);

    this_thread::sleep_for(duration);
    cout << outputString;
    this_thread::sleep_for(duration);
}

string input() {
    string typedInput;
    chrono::milliseconds duration(500);

    this_thread::sleep_for(duration);
    cout << ">>";
    
    cin >> typedInput;
    
    cout << "\n";
    
    return typedInput;
}

void newGameOption () {
    output("Starting a new game\n");
}

void loadGameOption () {
    output("Loading from save file\n");
}

void exitOption () {
    output("Bye, you prick!\n");
}


void displayMainMenu () {
    //region define
    int selectedOption;
    string mainMenu, selectedOptionInput;

    void (*options[3])() = {
        newGameOption,
        loadGameOption,
        exitOption
    }; 
    //endregion

    //region print
    mainMenu = "\bWelcome to a simple C++ text RPG\b";
    mainMenu += "\n\nPlease type the option number:";
    mainMenu += "\n\t[1] New game";
    mainMenu += "\n\t[2] Load game";
    mainMenu += "\n\t[3] Exit\n";
    
    cout << mainMenu;
    //endregion

    //region process input
    selectedOptionInput = input();

    try {
        selectedOption = stoi(selectedOptionInput);
    } catch (const invalid_argument& e) {
        output("Damn fool, you must type a number between 1 and 3, try again and don't mess with the menu please");
        return displayMainMenu();
    } catch (const out_of_range& e) {
        output("Are you trying to compensate for something? Enter a number from 1 to 3");
        return displayMainMenu();
    }

    if (selectedOption < 1 || selectedOption > 3) {
        output("I know is hard to you follow simple instructions, but please, limit to type an option from the menu");
        return displayMainMenu();
    }

    options[selectedOption - 1]();
    //endregion
}


int  main () {
    output("1");
    output("2");
    output("3");
    displayMainMenu();
    return 0;
}