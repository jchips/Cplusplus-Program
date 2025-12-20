/* Jaye Rhinehart */
#include <stdexcept>

#include "StoreMenu.h"

int main() {
    StoreMenu cornerGrocerMenu;
    map<string, int> storeItems;
    int menuOption;
    bool cont = true;
    string foodItem;
    cin.exceptions(ios::failbit);

    cornerGrocerMenu.readStoreItems();
    while (cont) {
        /* Display menu */
        cout << "Welcome to Corner Grocer" << endl;
        cout << "------------------------" << endl;
        cout << "Enter a menu option (1-4), out of the following:" << endl;
        cout << "(1) Get frequency of food item" << endl;
        cout << "(2) List frequency of all items" << endl;
        cout << "(3) View frequency in form of histogram" << endl;
        cout << "(4) Exit" << endl;
        cout << endl;

        /* User input validation */
        try {
            cin >> menuOption;
            if (menuOption < 1 || menuOption > 4) {
                throw runtime_error("Menu option not valid");  // throw error: menu choice is not 1-4
            }
        }
        catch (ios_base::failure& excpt) {
            cout << "Error: Nan" << endl
                << endl;  // handle error Nan
            break;
        }
        catch (runtime_error& excpt) {
            cout << "Error: " << excpt.what() << endl
                << endl;  // handle invalid input
            continue;      // re-display menu
        }
        cin.clear();

        /* Handle menu option */
        switch (menuOption) {
        case 1:
            cornerGrocerMenu.menuOptionOne();
            cout << endl
                << endl;
            break;
        case 2:
            cornerGrocerMenu.menuOptionTwo();
            cout << endl
                << endl;
            break;
        case 3:
            cornerGrocerMenu.menuOptionThree();
            cout << endl
                << endl;
            break;
        case 4:
            cont = false;
            break;
        default:
            break;
        }
    }
    return 0;
}