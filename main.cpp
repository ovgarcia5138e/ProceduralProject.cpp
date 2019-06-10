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


    return 0;
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

    //int producing_products_input;
    std::cin >> producing_products_input;


    switch (producing_products_input) {
        case 1:
            product_types_menu(catalog_vector_prod_type);
            selecting_item_type(catalog_vector_prod_type, product_production_num, VIserial, AMserial, MMserial,
                                VMserial, product_records, catalog_vector_manufacturer, producing_products_input);
            break;
        case 2:
            product_types_menu(catalog_vector_prod_type);
            selecting_item_type(catalog_vector_prod_type, product_production_num, VIserial, AMserial, MMserial,
                                VMserial, product_records, catalog_vector_manufacturer, producing_products_input);
            break;
        case 3:
            product_types_menu(catalog_vector_prod_type);
            selecting_item_type(catalog_vector_prod_type, product_production_num, VIserial, AMserial, MMserial,
                                VMserial, product_records, catalog_vector_manufacturer, producing_products_input);
            break;
        case 4:
            product_types_menu(catalog_vector_prod_type);
            selecting_item_type(catalog_vector_prod_type, product_production_num, VIserial, AMserial, MMserial,
                                VMserial, product_records, catalog_vector_manufacturer, producing_products_input);
            break;
        case 5:
            product_types_menu(catalog_vector_prod_type);
            selecting_item_type(catalog_vector_prod_type, product_production_num, VIserial, AMserial, MMserial,
                                VMserial, product_records, catalog_vector_manufacturer, producing_products_input);
            break;
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
    std::cout << "Enter a Manufactuer" << "\n";
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
    std::string new_product_type;
    std::cin >> new_product_type;

    catalog_vector_type.push_back(new_product_type);

    std::ofstream new_product_to_catalog;
    new_product_to_catalog.open("manufacturer.txt", std::ios::app);


    new_product_to_catalog << new_manufacturer << " " << new_product << " " << new_product_type <<
                           std::endl;

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


    int item_type_input;
    std::cin >> item_type_input;

    int counter = 0;
    std::string type = "he";

    switch (item_type_input) {
        case 1:
            counter = VIserial++;
            type = "VI";
            break;
        case 2:
            counter = AMserial++;
            type = "AM";
            break;
        case 3:
            counter = MMserial++;
            type = "MM";
            break;
        case 4:
            counter = VMserial++;
            type = "VM";
            break;
    }

    std::cout << "Enter the number to be produced: " << "\n";

    int number_to_produce;
    std::cin >> number_to_produce;

    int overall_production_numbers = product_records.size();

    int hello = producing_products_input - 1;
    for (int i = 1; i <= number_to_produce; i++) {
        product_write << "Production number : " << overall_production_numbers++ << " " << " "
                      << " " << catalog_vector_manufacturer[hello] << " "
                      << catalog_vector_manufacturer[hello].substr(0, 3) <<
                      type << std::setfill('0') << std::setw(5) << counter++ << "\n";
    }

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
it is accepted as a string. The function procedes to read from the ProductionRecords text file 
and pushes each line into a vector which is the product_records_serial string vector. Each Element
string of that vector generates a substring that is the last ten index values, which is compared to the
user input, and if they match each other the size of the product_records_serial is given. which is equivielent
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
 
