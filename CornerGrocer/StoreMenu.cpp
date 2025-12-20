#include "StoreMenu.h"

#include <cctype>

/**
 * Reads all store items from the CS210_Project_Three_Input_File.txt file and
 * stores them and their frequencies (into a map).
 * @return exit function
 */
int StoreMenu::readStoreItems() {
    ifstream inFS;  // input file stream
    string foodItem;

    inFS.open("CS210_Project_Three_Input_File.txt");  // open input file

    if (!inFS.is_open()) {
        cout << "Could not open file: CS210_Project_Three_Input_File" << endl;  // handle error
        return 0;
    }

    inFS >> foodItem;  // read food item from file
    while (!inFS.fail()) {
        if (storeItems.count(foodItem) == 1) {  // food item is already stored
            storeItems.at(foodItem)++;            // increase amount
        }
        else {
            storeItems.emplace(foodItem, 1);  // add food item
        }
        inFS >> foodItem;  // read food item from file
    }

    if (!inFS.eof()) {
        cout << "Input failure before reaching end of file." << endl;
    }

    inFS.close();
    writeStoreItems();  // create frequency.dat file
    return 0;
}

/* Write all store items and their frequency to frequency.dat file */
void StoreMenu::writeStoreItems() const {
    ofstream outFS;  // output file stream

    outFS.open("frequency.dat");  // open output file

    if (!outFS.is_open()) {
        cout << "Could not open file: frequency.dat" << endl;  // handle error
    }
    else {
        for (const auto& foodItem : storeItems) {
            outFS << foodItem.first << " " << foodItem.second << endl;
        }
    }
    outFS.close();
}

/**
 * Handle menu option 1:
 * Prints a numeric value for the frequency of a food item.
 */
void StoreMenu::menuOptionOne() const {
    string foodItem;
    char firstLetter;
    cout << endl
        << "Menu Option 1" << endl;
    cout << nCharString(BORDER_WIDTH, '-') << endl;  // print border
    cout << "Enter the food item: ";
    cin >> foodItem;
    firstLetter = foodItem[0];  // get first letter

    /* Capitalize first letter (if not already) */
    if (islower(firstLetter)) {
        firstLetter = toupper(firstLetter);
        foodItem[0] = firstLetter;
    }

    if (storeItems.count(foodItem) == 1) {
        if (storeItems.at(foodItem) == 1) {
            cout << "There is " << storeItems.at(foodItem) << " " << foodItem << endl;  // == 1
        }
        else {
            cout << "There are " << storeItems.at(foodItem) << " " << foodItem << endl;  // > 1
        }
    }
    else {
        cout << "There are 0 " << foodItem << endl;
    }
    cout << nCharString(BORDER_WIDTH, '=') << endl;  // print bottom border
}

/**
 * Handle menu option 2:
 * Prints food item list with numbers that represent the frequency of all items purchased.
 */
void StoreMenu::menuOptionTwo() const {
    cout << endl
        << "Menu Option 2" << endl;
    cout << nCharString(BORDER_WIDTH, '-') << endl;  // print border
    for (const auto& foodItem : storeItems) {
        cout << foodItem.first << " " << foodItem.second << endl;  // list food item
    }
    cout << nCharString(BORDER_WIDTH, '=') << endl;  // print bottom border
}

/**
 * Handle menu option 3:
 * Prints the frequency info for all the food items in the form of a histogram.
 */
void StoreMenu::menuOptionThree() const {
    cout << endl
        << "Menu Option 3" << endl;
    cout << nCharString(BORDER_WIDTH, '-') << endl;  // print border
    for (const auto& foodItem : storeItems) {
        cout << foodItem.first << " " << nCharString(foodItem.second, '*') << endl;  // print frequency with '*'
    }
    cout << nCharString(BORDER_WIDTH, '=') << endl;  // print bottom border
}

/**
 * Returns a string of length t_num, each character a t_char.
 * For example, nCharString(5, '*') returns "*****"
 * @param t_num string length, >=0
 * @param t_char character to make string of
 * @return string of n t_char's
 */
string StoreMenu::nCharString(size_t t_num, char t_char) const {
    string charString;
    for (int i = 0; i < t_num; i++) {
        charString += t_char;
    }

    return charString;
}