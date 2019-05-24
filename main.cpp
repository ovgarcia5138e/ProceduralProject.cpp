//Hello world program


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Prototype functions.
int menuOptions(int menuinputone);
void showMenu();
void introductionQuestion(string firstescapeattempt);
int menuOptionstonextmenu(int firstmenuinput);
void appleCompayProducts(string manufacturer);

int main() {

    ofstream myfile;
    myfile.open("ProductList.txt");
    myfile << "Hello World! \n";
    myfile.close();

    cout << "Lets get Started enter your name: " << endl;

    string username;

    cin >> username;

    cout << "Hey " << username << " you managed to hack into Cisco Corportation system, this is an AI speaking, my name is not inmortant"
                                  " for now refer to me as tosh togther we will "
                                  "take what we need and use it to our advantage." << endl;

    cout <<"\n";

    cout << "If you want to back out enter escape: " << endl;

    string firstescapeattempt;

    cin >> firstescapeattempt;

    introductionQuestion(firstescapeattempt);

    cout << "\n";
    cout << "Pick on of  the options below by inputing a value 1-6:"
            << endl;

    // showMenu() displays the home menu of the production line.
    showMenu();

    int firstmenuinput;
    cin >> firstmenuinput;


    menuOptionstonextmenu(firstmenuinput);

    // Eventually the user will be able to choose the item to produce.
    // For now, just have them input the information.
    cout << "Enter the manufacturer\n";
    string manufacturer;
    cin >> manufacturer;

    appleCompayProducts(manufacturer);

    int itemTypeChoice;
    cin >> itemTypeChoice;

    string itemTypeCode;
    // write code to set the item type code based on the selected item type
    // Audio "MM", Visual "VI", AudioMobile "AM", or VisualMobile "VM".



    return 0;
}

// functions for program.

int menuOptions(int menuinputone) {

    if (menuinputone == 1 ) {
        cout << "Produce Items Stub\n";
        cout << "1. Produce items\n";
        cout << "2. Add Employee Account\n";
        cout << "3. Add Music Player\n";
        cout << "4. Add Movie Player\n";
        cout << "5. Display Production Statistics\n";
        cout << "6. Exit\n";

    } else if (menuinputone == 2) {
        cout << "Add Employee Account Stub\n";
        cout << "1. Produce items\n";
        cout << "2. Add Employee Account\n";
        cout << "3. Add Music Player\n";
        cout << "4. Add Movie Player\n";
        cout << "5. Display Production Statistics\n";
        cout << "6. Exit\n";

    } else if (menuinputone == 3) {
        cout << "Add Music Player Stub\n";
        cout << "1. Produce items\n";
        cout << "2. Add Employee Account\n";
        cout << "3. Add Music Player\n";
        cout << "4. Add Movie Player\n";
        cout << "5. Display Production Statistics\n";
        cout << "6. Exit\n";

    } else if (menuinputone == 4) {
        cout << "Add Movie Player Stub\n";
        cout << "1. Produce items\n";
        cout << "2. Add Employee Account\n";
        cout << "3. Add Music Player\n";
        cout << "4. Add Movie Player\n";
        cout << "5. Display Production Statistics\n";
        cout << "6. Exit\n";

    } else if (menuinputone == 5) {
        cout << "Display Production Statistics Stub\n";
        cout << "1. Produce items\n";
        cout << "2. Add Employee Account\n";
        cout << "3. Add Music Player\n";
        cout << "4. Add Movie Player\n";
        cout << "5. Display Production Statistics\n";
        cout << "6. Exit\n";

    } else if (menuinputone == 6) {

        cout << "Production Line Tracker\n";
        cout << "1. Produce items\n";
        cout << "2. Add Employee Account\n";
        cout << "3. Add Music Player\n";
        cout << "4. Add Movie Player\n";
        cout << "5. Display Production Statistics\n";
        cout << "6. Exit\n";

        return 0;

    } else if (menuinputone < 1 || menuinputone > 6) {
        cout << "Not a valid selection\n";
        cout << "1. Produce items\n";
        cout << "2. Add Employee Account\n";
        cout << "3. Add Music Player\n";
        cout << "4. Add Movie Player\n";
        cout << "5. Display Production Statistics\n";
        cout << "6. Exit\n";
    }

    return 0;
}

void showMenu() {
    cout << "\n";
    cout << "Production Line Tracker\n";
    cout << "1. Produce items\n";
    cout << "2. Add Employee Account\n";
    cout << "3. Add Music Player\n";
    cout << "4. Add Movie Player\n";
    cout << "5. Display Production Statistics\n";
    cout << "6. Exit\n";

}

void introductionQuestion(string firstescapeattempt){
    if (firstescapeattempt == "escape") {
        cout << "You made the mistake of entering your name you must do as I say or I will frame you. Lets make better decisions since we are working togher\"\n"
                "                \"now partner. " << endl;
    } else {
        cout << "You're not very good at following directions are you? Lets make better decisions since we are working togher"
                "now partner." << endl;
    }
}

int menuOptionstonextmenu(int firstmenuinput) {
    do {
        if (firstmenuinput >= 1 && firstmenuinput <= 5) {

            menuOptions(firstmenuinput);

            int thirdmenuinput;
            cin >> thirdmenuinput;

            menuOptions(thirdmenuinput);

            if (thirdmenuinput == 6){
                //menuOptions(6);
                //return 0;
                break;
            }


        } else if (firstmenuinput < 1 || firstmenuinput > 6) {

            menuOptions(7);
            int secondmenuinput;
            cin >> secondmenuinput;
            menuOptions(secondmenuinput);

        } else if (firstmenuinput == 6) {
            menuOptions(6);
            //int thirdmenuinput;
            //cin >> thirdmenuinput;
            //menuOptions(thirdmenuinput);
            return 0;
        }

    } while(firstmenuinput >=1 && firstmenuinput < 6);

}

void appleCompayProducts(string manufacturer){

    if  (manufacturer == "Apple"){
        cout <<
             "Apple Products\n"
             << "1. iPod\n"
             <<"2. iPhone\n"
             <<"3. i Pad\n"
             <<"4. Ear Pods\n";
        cout << "Enter the product name\n";
        string prodName;
        cin >> prodName;

        if (prodName =="iPod") {
            cout << "Enter the item type\n";
            cout << "1. Audio\n" <<
                 "2. Visual\n" <<
                 "3. AudioMobile\n" <<
                 "4. VisualMobile\n";
            int itemTypeChoice;
            cin >> itemTypeChoice;

            string itemTypeCode;
            // write code to set the item type code based on the selected item type
            // Audio "MM", Visual "VI", AudioMobile "AM", or VisualMobile "VM".


            if (itemTypeChoice == 1){

                cout << "Enter the number of items that were produced\n";
                int numProducedMM;
                cin >> numProducedMM;

                ofstream productlists;
                productlists.open("ProductList.txt", ofstream::app);
                for (int start = 1; start <= numProducedMM; start++) {
                    //ofstream myfile ("ProductList.txt", ios::in | ios::out | ios::app);

                    if (productlists.is_open()){
                        productlists << "\nProduction Number: " << start << " Serial Number: AppMM " << setfill('0') << setw(5) << start;

                    } else {
                        cout << "Unable to open file.\n";
                    }
                }

            } else if (itemTypeChoice ==2) {
                cout << "Enter the number of items that were produced\n";
                int numProducedVI;
                cin >> numProducedVI;
                for (int start = 1; start <= numProducedVI; start++) {

                    cout << "Production Number: " << start << " Serial Number: AppVI " << setfill('0') << setw(5) << start << endl;
                }
            } else if (itemTypeChoice == 3) {
                cout << "Enter the number of items that were produced\n";
                int numProducedAM;
                cin >> numProducedAM;
                for (int start = 1; start <= numProducedAM; start++) {

                    cout << "Production Number: " << start << " Serial Number: AppAM " << setfill('0') << setw(5) << start << endl;
                }
            } else if (itemTypeChoice == 4) {
                cout << "Enter the number of items that were produced\n";
                int numProducedVM;
                cin >> numProducedVM;
                for (int start = 1; start <= numProducedVM; start++) {

                    cout << "Production Number: " << start << " Serial Number: AppVM" << setfill('0') << setw(5) << start << endl;
                }
            }
        }

    }

}

