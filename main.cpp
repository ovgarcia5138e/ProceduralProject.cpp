/*
 * Media Player Production Program.
 * @file main.cpp
 * @brief The majority of a media player production program
 *
 *
 * main.cpp is the primary file for the media player production program.
 * The program was created in Methodology 2001 in the summer of 2019.
 *
 *
 * @author Oscar Garcia Vazquez
 * @bug no know bugs
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>

//Prototype functions.
void showMenu();

void
menu_input(std::vector<std::string> &, std::vector<std::string> &,
           std::vector<std::string> &, std::vector<std::string> &,
           int, int &, int &, int &, int &, std::vector<std::string> &, std::vector<std::string> &, int &);

void
adding_new_products_to_production(std::vector<std::string> &, std::vector<std::string> &, std::vector<std::string> &,
                                  std::vector<std::string> &);

void print_product_lines(std::vector<std::string> &);

void product_types_menu(std::vector<std::string> &);

void
producing_products(std::vector<std::string> &, std::vector<std::string> &, std::vector<std::string> &,
                   int &, int &VIserial, int &, int &, int &, std::vector<std::string> &, std::vector<std::string> &,
                   int &);

void selecting_item_type(std::vector<std::string> &, int &, int &, int &, int &, int &, std::vector<std::string> &,
                         std::vector<std::string> &, int &);

void starting_place_vectors(std::vector<std::string> &, int &, int &, int &MM, int &);

void find_production_number(std::vector<std::string> &);

void creating_employee_account();

void creating_employee_password();

int main() {

    std::vector<std::string> catalog_vector_manufacturer;
    std::vector<std::string> catalog_vector_products;
    std::vector<std::string> catalog_vector_prod_type = {"VI", "AM", "MM", "VM"};
    std::vector<std::string> catalog_vector_type;
    std::vector<std::string> product_records;
    std::vector<std::string> product_records_serial;

    int VIserial = 0;
    int AMserial = 0;
    int MMserial = 0;
    int VMserial = 0;
    int overall_production_num = 0;
    int producing_products_input;

    // This do while loop returns the program to the main menu after each task the user engages in is complete.
    do {
        showMenu();
        menu_input(catalog_vector_manufacturer, catalog_vector_products, catalog_vector_type, catalog_vector_prod_type,
                   overall_production_num, VIserial, AMserial, MMserial, VMserial, product_records,
                   product_records_serial, producing_products_input);
    } while (true);

    //return 0;
}

// This function displays the main menu of the program.
void showMenu() {
    std::cout << "\n";
    //cout << "Production Line Tracker\n";
    std::cout << "1. Produce items\n";
    std::cout << "2. Add Employee Account\n";
    std::cout << "3. Add to production line\n";
    std::cout << "4. Add Movie Player\n";
    std::cout << "5. Display Production Statistics\n";
    std::cout << "6. Exit\n";
    std::cout << "\n";
}

/*
This function takes in an integer value as an input to direct the user into the proper subsection
of the display menu function.
 */
void
menu_input(std::vector<std::string> &catalog_vector_manufacturer, std::vector<std::string> &catalog_vector_products,
           std::vector<std::string> &catalog_vector_type, std::vector<std::string> &catalog_vector_prod_type,
           int overall_production_num, int &VIserial, int &AMserial, int &MMserial, int &VMserial,
           std::vector<std::string> &product_records, std::vector<std::string> &product_records_serial,
           int &producing_products_input) {
    std::cout << "Enter the number for a menu option to get started:" << "\n";

    int menu_option_input;
    std::cin >> menu_option_input;

    switch (menu_option_input) {
        case 1:
            producing_products(catalog_vector_manufacturer, catalog_vector_products, catalog_vector_type,
                               overall_production_num, VIserial, AMserial, MMserial, VMserial,
                               catalog_vector_prod_type, product_records, producing_products_input);
            break;
        case 2:
            creating_employee_account();
            creating_employee_password();
            break;
        case 3:
            adding_new_products_to_production(catalog_vector_manufacturer, catalog_vector_products, catalog_vector_type,
                                              catalog_vector_prod_type);
            break;
        case 4:
            break;
        case 5:
            find_production_number(product_records_serial);
            break;
        case 6:

            break;
    }

}

/*
This function is for the produce items subsection of the main menu function. It displays the product options
 that are read from a catalog text file, then the use is able to input the integer value for that product to begin
 production and accepts an integer value to select the product.
 */
void producing_products(std::vector<std::string> &catalog_vector_manufacturer,
                        std::vector<std::string> &catalog_vector_products,
                        std::vector<std::string> &catalog_vector_type,
                        int &product_production_num, int &VIserial, int &AMserial, int &MMserial, int &VMserial,
                        std::vector<std::string> &catalog_vector_prod_type, std::vector<std::string> &product_records,
                        int &producing_products_input) {

    starting_place_vectors(product_records, VIserial, VMserial, AMserial, MMserial);


    std::ifstream production_numbers("ProductionRecords.txt");
    std::string production_line;

    if (production_numbers.is_open()) {
        while (getline(production_numbers, production_line)) {

            product_records.push_back(production_line);
        }
    }

    std::cout << "Select the number related to a product: " << "\n";

    print_product_lines(catalog_vector_manufacturer);


    std::cin >> producing_products_input;


    if (producing_products_input == producing_products_input) {
        selecting_item_type(catalog_vector_prod_type, product_production_num, VIserial, AMserial, MMserial,
                            VMserial, product_records, catalog_vector_manufacturer, producing_products_input);
    }

}

void adding_new_products_to_production(std::vector<std::string> &catalog_vector_manufacturer,
                                       std::vector<std::string> &catalog_vector_products,
                                       std::vector<std::string> &catalog_vector_type,
                                       std::vector<std::string> &catalog_vector_prod_type) {
    std::ifstream file("Catalog.txt");
    std::string reading_file;

    while (getline(file, reading_file)) {
        //get rid of catalog_vector_manufacturer.push_back(reading_file);

    }

    //print_product_lines();

    std::cout << "\n";
    std::cout << "Enter a Manufacturer" << "\n";
    std::string new_manufacturer;
    std::cin >>
             new_manufacturer;

    catalog_vector_manufacturer.
            push_back(new_manufacturer);

    std::cout << "Enter a new product" << "\n";
    std::string new_product;
    std::cin >>
             new_product;

    catalog_vector_products.push_back(new_product);

    product_types_menu(catalog_vector_prod_type);

    std::cout << "Enter a new product type" << "\n";
    int new_product_type;
    std::cin >> new_product_type;
    std::string product_type = "mm";

    switch (new_product_type) {
        case 1:
            product_type = "VI";
            break;
        case 2:
            product_type = "AM";
            break;
        case 3:
            product_type = "MM";
            break;
        case 4:
            product_type = "VM";
            break;
    }

    //catalog_vector_type.push_back(new_product_type);

    std::ofstream new_product_to_catalog;
    new_product_to_catalog.open("Catalog.txt", std::ios::app);


    new_product_to_catalog << new_manufacturer << " " << new_product << " " << product_type <<
                           std::endl;

    std::cout << "New product added to the production line.\n";

}

/*
This function displays the product options that are able to be produced it reads from a catalog text fil
that has this information stored.
*/
void print_product_lines(std::vector<std::string> &catalog_vector_manufacturer) {

    std::ifstream myfile("Catalog.txt");
    std::string product_from_catalog;

    int number_of_product = 1;

    while (getline(myfile, product_from_catalog)) {
        catalog_vector_manufacturer.push_back(product_from_catalog);
        std::cout << number_of_product++ << ".) " << product_from_catalog << "\n";
    }

}

//This function displays the four categories a product that is going into production can be classified as.

void product_types_menu(std::vector<std::string> &catalog_vector_prod_type) {
    std::cout << "Enter the number for the according item type" << "\n";
    for (int i = 0; i < catalog_vector_prod_type.size(); i++) {
        std::cout << i + 1 << ". ) " << catalog_vector_prod_type[i] << "\n";
    }

}

/*This function accepts an integer value to assign a product its product type. Then this fucntion
 * procedes to write to a text file that keeps track of all of the produced items.
*/

void selecting_item_type(std::vector<std::string> &catalog_vector_prod_type, int &product_production_num, int &VIserial,
                         int &AMserial, int &MMserial, int &VMserial, std::vector<std::string> &product_records,
                         std::vector<std::string> &catalog_vector_manufacturer, int &producing_products_input) {

    starting_place_vectors(product_records, VIserial, AMserial, MMserial, VMserial);

    std::ofstream product_write;
    product_write.open("ProductionRecords.txt", std::ios::app);

    int hello = producing_products_input - 1;
    std::string product_type_file = catalog_vector_manufacturer[hello].substr(
            catalog_vector_manufacturer[hello].size() - 2, 2);
    std::string product_company = catalog_vector_manufacturer[hello].substr(
            0, catalog_vector_manufacturer[hello].size() - 2);
    int counter = 0;

    if (product_type_file == "VI") {
        counter = VIserial++;
    } else if (product_type_file == "AM") {
        counter = AMserial++;
    } else if (product_type_file == "MM") {
        counter = MMserial++;
    } else if (product_type_file == "VM") {
        counter = VMserial++;
    }

    std::cout << "Enter the number to be produced: " << "\n";

    int number_to_produce;
    std::cin >> number_to_produce;

    int overall_production_numbers = product_records.size();

    for (int i = 1; i <= number_to_produce; i++) {
        product_write << "Production number : " << overall_production_numbers++ << " " << " " << product_company
                      << catalog_vector_manufacturer[hello].substr(0, 3) << product_type_file
                      << std::setfill('0') << std::setw(5) << counter++ << "\n";
    }

    std::cout << "Products added to production line.\n";

    product_write.close();

}

/*
This vector reads from the Production Records text file and creates a substring from each line that is saved as a
string. Then a substring is created that is the last seven index values as its starting point and takes two index values
after that. Which in that place is the product type. If the substring matches to one of the four product types
then it is incremented by one each time that it is encountered in order to keep track of the number produced
of each product type.
*/
void starting_place_vectors(std::vector<std::string> &product_records, int &VIserial, int &AMserial, int &MMserial,
                            int &VMserial) {

    std::string line;
    std::ifstream startingplace("ProductionRecords.txt");

    if (startingplace.is_open()) {
        while (getline(startingplace, line)) {

            //product_records.push_back(line);

            if (line.substr(line.length() - 7, 2) == "VI") {
                VIserial++;
            } else if (line.substr(line.length() - 7, 2) == "AM") {
                AMserial++;

            } else if (line.substr(line.length() - 7, 2) == "MM") {
                MMserial++;

            } else if (line.substr(line.length() - 7, 2) == "VM") {
                VMserial++;
            }

        }
        startingplace.close();
    } else std::cout << "Unable to open file";


}

/*
This function finds a products production number according to its serial number which is ten digits
it is accepted as a string. The function proceeds to read from the ProductionRecords text file
and pushes each line into a vector which is the product_records_serial string vector. Each Element
string of that vector generates a substring that is the last ten index values, which is compared to the
user input, and if they match each other the size of the product_records_serial is given. which is equivalent
to the production number of that serial number.
*/

void find_production_number(std::vector<std::string> &product_records_serial) {


    std::ifstream getting_production_num("ProductionRecords.txt");
    std::string production_line_records_;

    std::cout << "Enter a serial number to retrieve the production number: " << std::endl;
    std::string serial_num_to_find;
    std::cin >> serial_num_to_find;


    if (getting_production_num.is_open()) {


        bool is_there = false;
        int counter = 0;

        while (is_there == false && counter < product_records_serial.size() + 1) {

            getline(getting_production_num, production_line_records_);
            product_records_serial.push_back(production_line_records_);

            if (production_line_records_.substr(production_line_records_.size() - 10, 10) == serial_num_to_find) {
                is_there = true;
            } else {
                counter += 1;
            }

        }

        if (is_there) {
            std::cout << "the production number of " << serial_num_to_find << " is " << counter
                      << std::endl;

        } else {
            std::cout << "That is not a valid serial number, please check and re-enter." << std::endl;
            find_production_number(product_records_serial);
        }

    }

}

/*
 * This function allows an employee to enter their first, and last name while also generating them a useranme that
 * has the fist name inital followed by the entire last name all in in lowercase, and saves the fist name, last name,
 * and username to a txt file.
 */

void creating_employee_account() {
    std::cout << "Enter your first name:\n";
    std::string first_name;
    std::cin >> first_name;
    std::cout << "Enter your last name:\n";
    std::string last_name;
    std::cin >> last_name;
    std::string employee_full_name = first_name + " " + last_name + "\n";
    std::string last_name_resized;
    std::string first_name_resized;
    last_name_resized.resize(last_name.size());
    std::transform(last_name.begin(), last_name.end(), last_name_resized.begin(), ::tolower);
    std::transform(first_name.begin(), first_name.end(), first_name_resized.begin(), ::tolower);
    std::string employee_user_name = first_name_resized[0] + last_name_resized;
    std::cout << "Your user name is: " + employee_user_name << "\n";
    std::ofstream employee_name_to_file;
    employee_name_to_file.open("Employee_passwords.txt", std::ios::app);
    employee_name_to_file << first_name << " " << last_name << " " << employee_user_name << " ";
}
/*
 * This function accepts a 30 char long password from an employee, encrypts the password using the ceaser cypher
 * and savese the employees password, and encrypted password to a txt file.
 */
void creating_employee_password() {
    std::cin.ignore();
    std::cout
            << "Enter a password with at least one of the following: lowercase letter, uppercase letter, a number, and no spaces:\n";
    const int employee_password_size = 30;
    char attempted_password[employee_password_size];
    int lower = 0;
    int upper = 0;
    int digit = 0;
    bool valid_password;

    std::cin.getline(attempted_password, employee_password_size);

    for (int i = 0; i < strlen(attempted_password); i++) {
        if (islower(attempted_password[i])) {
            lower += 1;
        } else if (isupper(attempted_password[i])) {
            upper += 1;
        } else if (isdigit(attempted_password[i])) {
            digit += 1;
        } else {
            valid_password = true;
        }
    }

    std::string password;
    std::stringstream convert;
    convert << attempted_password;
    convert >> password;

    if (lower > 0 && upper > 0 && digit > 0 && valid_password == false) {
        std::cout << "Congratulations your password is: " << password << "\n";
    } else {
        std::cout << "That was an invalid password, check and try again\n";
        creating_employee_password();
    }

    std::vector<char> encrypted_password;

    for (int i = 0; i < password.length(); i++) {
        int ascii_value = int(password[i]);
        char new_char_value = char(ascii_value + 3);
        encrypted_password.push_back(new_char_value);
    }

    std::string encrypted_password_string(encrypted_password.begin(), encrypted_password.end());
    std::cout << encrypted_password_string;
    std::ofstream encrypeted_password_to_file;
    encrypeted_password_to_file.open("Employee_passwords.txt", std::ios::app);
    encrypeted_password_to_file << password << " " << encrypted_password_string << "\n";
}
