/*
Media Player Production Program.
@file main.cpp
@brief The majority of a media player production program.


main.cpp is the primary file for the media player production program.
The program was created in COP 2001 in the summer of 2019.


 @author Oscar Garcia Vazquez
 @bug no known bugs

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>


using namespace std;


// Prototype functions.
int menuOptions(int menuinputone);

void showMenu();

void introductionQuestion(string firstescapeattempt);

int menuOptionstonextmenu(int firstmenuinput);

void appleCompayProducts(string manufacturer);


int main() {


    cout << "Login Cisco Company \n" <<  "Enter your name: " << endl;


    // this is the username of the person using the program
    string username;

    cin >> username;

    cout << "Error Message \n  " << username
         << " You managed to hack into Cisco Corporation system, this is an AI speaking, my name is not inmortant"
            " for now refer to me as tosh, together we will "
            "take what we need and use it to our advantage." << endl;

    cout << "\n";

    cout << "If you want to back out enter escape: " << endl;

    string firstescapeattempt;

    cin >> firstescapeattempt;

    introductionQuestion(firstescapeattempt);

    cout << "\n";
    cout << "Pick one of  the options below by inputing a value 1-6:"<< endl;
    cout << "\n";

    // showMenu() displays the home menu of the production line.
    cout << "Production Line Tracker\n";
    showMenu();

    int firstmenuinput;
    cin >> firstmenuinput;

    //Function that demonstrates sub menus that the original menu displays.
    menuOptionstonextmenu(firstmenuinput);

    // The input for the company manufacturer.
    cout << "Enter the name of a manufacturer to begin product production:\n";
    string manufacturer;
    cin >> manufacturer;


    // This method produces the products that the company Apple has.
    appleCompayProducts(manufacturer);

    int itemTypeChoice;
    cin >> itemTypeChoice;

    string itemTypeCode;


    /*
    struct student {
        char newproduct[50];
        int roll;
        //float marks;
    } s[10];

    for (int i = 0; i < 3; ++i) {
        s[i].roll = i + 1;
        cout << "For product  " << s[i].roll << "," << endl;

        cout << "Enter product : ";
        cin >> s[i].newproduct;

        cout << endl;
    }

    cout << "Displayign Info : " << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "\nProduct serial number: " << i + 1 << endl;
        cout << "Product name: " << s[i].newproduct << endl;
        //cout << "Marks: " << s[i].marks << endl;

    }

    list<int> mylist;
    list<int>:: iterator it;

    for (int i =1; i <=5; ++i) mylist.push_back(i);

    it = mylist.begin();
    ++it;

    mylist.insert(it, 22);

    mylist.insert(it,20);

    --it;

    vector<int> myvector (2,30);
    mylist.insert(it,myvector.begin(), myvector.end());

    cout << "Availible Products: ";
    for (it=mylist.begin(); it!=mylist.end(); ++it)
        cout << '\n' << *it;
    cout <<'\n';
    */
    return 0;
}

// functions for program.


// Provides sub menus for the main menu
int menuOptions(int menuinputone) {

    if (menuinputone == 1) {
        cout << "Produce Items Stub\n";
        showMenu();

    } else if (menuinputone == 2) {
        cout << "Add Employee Account Stub\n";
        showMenu();

    } else if (menuinputone == 3) {
        cout << "Add Music Player Stub\n";
        showMenu();

    } else if (menuinputone == 4) {
        cout << "Add Movie Player Stub\n";
        showMenu();

    } else if (menuinputone == 5) {
        cout << "Display Production Statistics Stub\n";
        showMenu();
    } else if (menuinputone == 6) {
        cout << "Production Line Tracker\n";
        showMenu();

        return 0;

    } else if (menuinputone < 1 || menuinputone > 6) {
        cout << "Not a valid selection\n";
        showMenu();
    }

    return 0;
}


// Shows the default menu.
void showMenu() {
    cout << "\n";
    //cout << "Production Line Tracker\n";
    cout << "1. Produce items\n";
    cout << "2. Add Employee Account\n";
    cout << "3. Add Music Player\n";
    cout << "4. Add Movie Player\n";
    cout << "5. Display Production Statistics\n";
    cout << "6. Exit\n";
    cout <<"\n";
}


// Input for the introduction question.
void introductionQuestion(string firstescapeattempt) {
    if (firstescapeattempt == "escape") {
        cout
                << "You made the mistake of entering your name you must do as I say or I will frame you. Lets make better decisions since we are working togher\"\n"
                   "                \"now partner. " << endl;
    } else {
        cout
                << "You're not very good at following directions are you? Lets make better decisions since we are working togher"
                   "now partner." << endl;
    }
}


// Provides the pathway to the next menu stubs from the main menu.
int menuOptionstonextmenu(int firstmenuinput) {
    do {
        if (firstmenuinput >= 1 && firstmenuinput <= 5) {

            menuOptions(firstmenuinput);

            int thirdmenuinput;
            cin >> thirdmenuinput;

            menuOptions(thirdmenuinput);

            if (thirdmenuinput == 6) {
                break;
            }


        } else if (firstmenuinput < 1 || firstmenuinput > 6) {

            menuOptions(7);
            int secondmenuinput;
            cin >> secondmenuinput;
            menuOptions(secondmenuinput);

        } else if (firstmenuinput == 6) {
            menuOptions(6);

            return 0;
        }

    } while (firstmenuinput >= 1 && firstmenuinput < 6);

}


// Displays the products that the Apple company has, tracks, and saves the quantity made and gives
// a custom serial number for each product
void appleCompayProducts(string manufacturer) {

    if (manufacturer == "Apple") {

        cout << "Select a product by typing in the product name: \n";
        cout <<"\n";
        cout <<
             "Apple Products\n"
             << "1. iPod\n"
             << "2. iPhone\n"
             << "3. i Pad\n"
             << "4. Ear Pods\n";
        cout << "Enter the product name\n";
        string prodName;
        cin >> prodName;


        if (prodName == "iPod") {
            cout << "Enter the item type by typing in the associated number:\n";
            cout << "\n";
            cout << "1. Audio\n" <<
                 "2. Visual\n" <<
                 "3. AudioMobile\n" <<
                 "4. VisualMobile\n";
            int itemTypeChoice;
            cin >> itemTypeChoice;

            string itemTypeCode;
            // write code to set the item type code based on the selected item type
            // Audio "MM", Visual "VI", AudioMobile "AM", or VisualMobile "VM".


            if (itemTypeChoice == 1) {

                cout << "Enter the number of items that were produced\n";
                int numProducedMM;
                cin >> numProducedMM;

                ofstream productlist;
                productlist.open("ProductList.txt", ios::app);

                for (int start = 1; start <= numProducedMM; start++) {

                    productlist << "Production Number: " << start << " Serial Number: AppMM " << setfill('0') << setw(5)
                                << start << endl;

                }

                productlist.close();

            } else if (itemTypeChoice == 2) {
                cout << "Enter the number of items that were produced\n";
                int numProducedVI;
                cin >> numProducedVI;

                ofstream producttwo;
                producttwo.open("ProductList.txt", ios::app);

                for (int start = 1; start <= numProducedVI; start++) {

                    producttwo << "Production Number: " << start << " Serial Number: AppVI " << setfill('0') << setw(5)
                               << start << endl;
                }

                producttwo.close();
            } else if (itemTypeChoice == 3) {
                cout << "Enter the number of items that were produced\n";
                int numProducedAM;
                cin >> numProducedAM;

                ofstream productthree;
                productthree.open("ProductList.txt", ios::app);

                for (int start = 1; start <= numProducedAM; start++) {

                    productthree << "Production Number: " << start << " Serial Number: AppAM " << setfill('0')
                                 << setw(5) << start << endl;
                }
            } else if (itemTypeChoice == 4) {
                cout << "Enter the number of items that were produced\n";
                int numProducedVM;
                cin >> numProducedVM;

                ofstream productfour;
                productfour.open("ProductList.txt", ios::app);

                for (int start = 1; start <= numProducedVM; start++) {

                    productfour << "Production Number: " << start << " Serial Number: AppVM" << setfill('0') << setw(5)
                                << start << endl;
                }
            }
        }

    }

    cout << "Please type another company to produce more products or type in 'done' if finished\n";
    string productmenuagain;
    cin >> productmenuagain;

    if (productmenuagain == "done") {
        showMenu();
    } else {
        appleCompayProducts(productmenuagain);
        cout << "\n";
        cout << "Enter a new product to add: \n";

    }
}
