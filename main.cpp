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

struct Producing_Products {
    std::string Products_From_Catalog;
};

struct Product_Records_From_Production {
    std::string Product_Records_;
};

struct Employee_Login_Process {
    int User_Name_Input = -1;
    int User_Password_Input = -1;
};

void Show_Menu();

void Menu_Input(std::vector<Producing_Products> &,
                std::vector<Product_Records_From_Production> &);

void Loading_Production_Vector(std::vector<Producing_Products> &);

void Adding_New_Products_To_Catalog(std::vector<Producing_Products> &);

void Producing_Products_Menu_Stub(std::vector<Producing_Products> &, std::vector<Product_Records_From_Production> &);

void getting_percentage_of_product_types();

void find_production_number();

void creating_employee_account();

void creating_employee_password();

void getting_program_started(Employee_Login_Process &Login_Inputs);

void Employee_Username_Login(Employee_Login_Process &Login_Inputs);

void Employee_Password_Login(Employee_Login_Process &Login_Inputs);

void employee_login(Employee_Login_Process &Login_Inputs);

void Printing_Production_Log();

int main() {
    std::vector<Producing_Products> Products;
    std::vector<Product_Records_From_Production> Product_Records_Vector;
    Employee_Login_Process Login_Inputs;
    Loading_Production_Vector(Products);
    getting_program_started(Login_Inputs);

    do {
        Show_Menu();
        Menu_Input(Products, Product_Records_Vector);
    } while (true);
}

// This function displays the main menu of the program.
void Show_Menu() {
    std::cout << "\n";
    std::cout << "1. Produce items\n";
    std::cout << "2. Add Employee Account\n";
    std::cout << "3. Add Product To Catalog\n";
    std::cout << "4. Display Production Statistics\n";
    std::cout << "5. Exit\n";
    std::cout << "\n";
}

/*
This function takes in an integer value as an input to direct the user into the proper subsection
of the display menu function.
 */
void Menu_Input(std::vector<Producing_Products> &Products,
                std::vector<Product_Records_From_Production> &Product_Records_Vector) {
    std::cout << "Enter the number for a menu option to get started:" << "\n";

    int menu_option_input;
    std::cin >> menu_option_input;

    switch (menu_option_input) {
        case 1:
            Producing_Products_Menu_Stub(Products, Product_Records_Vector);
            break;
        case 2:
            creating_employee_account();
            creating_employee_password();
            break;
        case 3:
            Adding_New_Products_To_Catalog(Products);
            break;
        case 4:
            std::cout << "Enter The Number Option:\n";
            std::cout << "1.) Find Production Number By Serial Number\n";
            std::cout << "2.) Product Type Statistics\n";
            std::cout << "3.) Print Production Log\n";
            int Product_Type_Stats;
            std::cin >> Product_Type_Stats;
            switch (Product_Type_Stats) {
                case 1:
                    find_production_number();
                    break;
                case 2:
                    getting_percentage_of_product_types();
                    break;
                case 3:
                    Printing_Production_Log();
                    break;
            }
            break;
        case 5:
            exit(-1);
    }

}

/*
This function displays the product options that are able to be produced it reads from a catalog text fil
that has this information stored.
*/
void Loading_Production_Vector(std::vector<Producing_Products> &Products) {
    Producing_Products Product;
    std::ifstream myfile("Catalog.txt");
    std::string Products_For_Catalog;
    int i = 0;
    while (getline(myfile, Products_For_Catalog)) {
        Products.push_back(Product);
        Products[i++].Products_From_Catalog = Products_For_Catalog;
    }

    myfile.close();
}

/*
 * Adds New Products to a catalog.txt file. The user is asked to input the product manufacturer, product, and product type.
 */
void Adding_New_Products_To_Catalog(std::vector<Producing_Products> &Products) {
    Producing_Products New_Product;
    std::ifstream file("Catalog.txt");
    std::string reading_file;

    std::cout << "\n";
    std::cout << "Enter a Manufacturer" << "\n";
    std::string new_manufacturer;
    std::cin >>
             new_manufacturer;

    std::cout << "Enter a new product" << "\n";
    std::string new_product;
    std::cin >>
             new_product;

    std::cout << "Enter a new product type" << "\n";
    std::cout << "\n";
    std::cout << "1.) VI\n";
    std::cout << "2.) AM\n";
    std::cout << "3.) MM\n";
    std::cout << "4.) VM\n";
    std::cout << "\n";

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

    std::ofstream new_product_to_catalog;
    new_product_to_catalog.open("Catalog.txt", std::ios::app);


    new_product_to_catalog << new_manufacturer << " " << new_product << " " << product_type <<
                           std::endl;

    Products.push_back(New_Product);
    Products[Products.size() - 1].Products_From_Catalog = new_manufacturer + " " + new_product + " " + product_type;
    std::ofstream Production_Line;
    Production_Line.open("ProductLine.csv", std::ios::app);
    Production_Line << new_manufacturer << "," << new_product << "," << product_type << "\n";
    std::cout << "New product added to the production line.\n";

}

//The user can pick from the product line to produce products.
void Producing_Products_Menu_Stub(std::vector<Producing_Products> &Products,
                                  std::vector<Product_Records_From_Production> &Product_Records_Vector) {
    Product_Records_From_Production Production;
    std::ifstream production_numbers("ProductionRecords.txt");
    std::string Production_Line;
    int i = 0;
    if (getline(production_numbers, Production_Line).fail()) {
        Adding_New_Products_To_Catalog(Products);
    } else {
        if (production_numbers.is_open()) {
            while (getline(production_numbers, Production_Line)) {
                Product_Records_Vector.push_back(Production);
                Product_Records_Vector[i++].Product_Records_ = Production_Line;
            }
        }
    }
    std::cout << "Select the number related to a product: " << "\n";


    for (int i = 0; i < Products.size(); i++) {
        std::cout << i + 1 << ".) " + Products[i].Products_From_Catalog << "\n";
    }

    int Producing_Products_Input;
    std::cin >> Producing_Products_Input;

    std::string number;
    std::ofstream product_write;
    std::ifstream Read_Product_Records("ProductionRecords.txt");
    product_write.open("ProductionRecords.txt", std::ios::app);

    int Production_Number_Record = 0;
    int VI = 0;
    int AM = 0;
    int MM = 0;
    int VM = 0;

    if (product_write.is_open()) {
        while (getline(Read_Product_Records, number)) {
            Production_Number_Record += 1;

            if (number.substr(number.length() - 7, 2) == "VI") {
                VI++;
            } else if (number.substr(number.length() - 7, 2) == "AM") {
                AM++;

            } else if (number.substr(number.length() - 7, 2) == "MM") {
                MM++;

            } else if (number.substr(number.length() - 7, 2) == "VM") {
                VM++;
            }
        }
    }
    int Production_Log_Record = Production_Number_Record;
    int VI_Log = VI;
    int AM_Log = AM;
    int MM_Log = MM;
    int VM_Log = VM;

    int hello = Producing_Products_Input - 1;

    std::string product_type_file = Products[hello].Products_From_Catalog.substr(
            Products[hello].Products_From_Catalog.size() - 2, 2);

    std::string product_company = Products[hello].Products_From_Catalog.substr(
            0, Products[hello].Products_From_Catalog.size() - 2);
    int counter = 0;
    int Counter_Log = 0;

    if (product_type_file == "VI") {
        counter = VI;
        Counter_Log = VI_Log;
    } else if (product_type_file == "AM") {
        counter = AM;
        Counter_Log = AM_Log;
    } else if (product_type_file == "MM") {
        counter = MM;
        Counter_Log = MM_Log;
    } else if (product_type_file == "VM") {
        counter = VM;
        Counter_Log = VM_Log;
    }

    std::cout << "Enter the number to be produced: " << "\n";

    int number_to_produce;
    std::cin >> number_to_produce;

    std::ofstream Production_Log;
    Production_Log.open("ProductLog.csv", std::ios::app);

    for (int i = 1; i <= number_to_produce; i++) {
        product_write << "Production number : " << Production_Number_Record++ << " " << product_company
                      << Products[hello].Products_From_Catalog.substr(0, 3) << product_type_file
                      << std::setfill('0') << std::setw(5) << counter++ << "\n";
        Production_Log << "Production number :," << Production_Log_Record++ << "," << product_company
                       << Products[hello].Products_From_Catalog.substr(0, 3) << product_type_file << ","
                       << std::setfill('0') << std::setw(5) << Counter_Log++ << "\n";
    }

    std::cout << "Products added to production line.\n";

    product_write.close();

}

//This displays how many of each product type are made and overall production numbers.
void getting_percentage_of_product_types() {
    int VIserial_Statistic = 0;
    int AMserial_Statistic = 0;
    int MMserial_Statistic = 0;
    int VMserial_Statistic = 0;

    std::string line;
    std::ifstream startingplace("ProductionRecords.txt");

    if (startingplace.is_open()) {
        while (getline(startingplace, line)) {

            if (line.substr(line.length() - 7, 2) == "VI") {
                VIserial_Statistic++;
            } else if (line.substr(line.length() - 7, 2) == "AM") {
                AMserial_Statistic++;

            } else if (line.substr(line.length() - 7, 2) == "MM") {
                MMserial_Statistic++;

            } else if (line.substr(line.length() - 7, 2) == "VM") {
                VMserial_Statistic++;
            }

        }
        startingplace.close();
    } else std::cout << "Unable to open file";
    std::cout << "Total Products Produced: "
              << VIserial_Statistic + AMserial_Statistic + MMserial_Statistic + VIserial_Statistic;
    std::cout << "VI productu types produced: " << VIserial_Statistic << "\n";
    std::cout << "AM productu types produced: " << AMserial_Statistic << "\n";
    std::cout << "MM productu types produced: " << MMserial_Statistic << "\n";
    std::cout << "VM productu types produced: " << VMserial_Statistic << "\n";
}

/*
This function finds a products production number according to its serial number which is ten digits
it is accepted as a string. The function proceeds to read from the ProductionRecords text file
and pushes each line into a vector which is the product_records_serial string vector. Each Element
string of that vector generates a substring that is the last ten index values, which is compared to the
user input, and if they match each other the size of the product_records_serial is given. which is equivalent
to the production number of that serial number.
*/
void find_production_number() {

    std::vector<std::string> Product_Record_Serial_Number;
    std::ifstream getting_production_num("ProductionRecords.txt");
    std::string production_line_records_;

    std::cout << "Enter a serial number to retrieve the production number: " << std::endl;
    std::string serial_num_to_find;
    std::cin >> serial_num_to_find;


    if (getting_production_num.is_open()) {

        bool is_there = false;
        int counter = 0;

        while (is_there == false && counter < Product_Record_Serial_Number.size() + 1) {

            getline(getting_production_num, production_line_records_);
            Product_Record_Serial_Number.push_back(production_line_records_);

            if (production_line_records_.substr(production_line_records_.size() - 10, 10) == serial_num_to_find) {
                is_there = true;
            } else {
                counter += 1;
            }

        }

        if (is_there) {
            std::cout << Product_Record_Serial_Number[counter].substr(0,
                                                                      Product_Record_Serial_Number[counter].size() - 11)
                      << "\n";

        } else {
            std::cout << "That is not a valid serial number, please check and re-enter." << std::endl;
            find_production_number();
        }

    }

}

//Prints the production records by reading from the Production Records text file.
void Printing_Production_Log() {
    std::ifstream Reading_Production_Log("ProductionRecords.txt");
    std::string Production_Log_Line;
    if (Reading_Production_Log.is_open()) {
        while (getline(Reading_Production_Log, Production_Log_Line)) {
            std::cout << Production_Log_Line << "\n";
        }
    }

}

//Creates an employee accout by asking the user for their first name, last name, and assigns them a user name.
void creating_employee_account() {
    std::cin.ignore();
    std::string First_Name_Employee;
    std::string Last_Name_Employee;
    std::cout << "Lets Create An Account\n";
    std::cout << "Enter your first name:\n";
    getline(std::cin, First_Name_Employee);
    std::cout << "Enter your last name:\n";
    std::cin.ignore();
    getline(std::cin, Last_Name_Employee);
    std::string Employee_Full_Name = First_Name_Employee + " " + Last_Name_Employee;
    std::string Last_Name_Re;
    std::string First_Name_Re;
    Last_Name_Re.resize(Last_Name_Employee.size());
    std::transform(Last_Name_Employee.begin(), Last_Name_Employee.end(), Last_Name_Re.begin(), ::tolower);
    std::transform(First_Name_Employee.begin(), First_Name_Employee.end(), First_Name_Re.begin(), ::tolower);
    std::string Employee_User_Name = First_Name_Re[0] + Last_Name_Re;
    std::cout << "Your usere name is : " + Employee_User_Name << "\n";
    std::ofstream employee_name_to_file;
    employee_name_to_file.open("Employee_passwords.txt", std::ios::app);
    employee_name_to_file << First_Name_Employee << " " << Last_Name_Employee << " " << Employee_User_Name << " ";
    std::ofstream User_Name_File;
    User_Name_File.open("Users.txt", std::ios::app);
    User_Name_File << Employee_User_Name << " ";
    std::cout << "Press Enter To Continue\n";
    //std::cin.ignore();
}

/*
 * This function accepts a 30 char long password from an employee, encrypts the password using the ceaser cypher
 * and saves the employees password, and encrypted password to a txt file.
 */
void creating_employee_password() {
    //std::cin.ignore();
    std::cout
            << "Enter a password with at least one of the following: lowercase letter, uppercase letter, a number, and no spaces:\n";
    const int employee_password_size = 30;
    char attempted_password[employee_password_size];
    int lower = 0;
    int upper = 0;
    int digit = 0;
    //bool valid_password;
    int spacer = 0;

    std::cin.getline(attempted_password, employee_password_size);

    for (int i = 0; i < strlen(attempted_password); i++) {
        if (islower(attempted_password[i])) {
            lower += 1;
        } else if (isupper(attempted_password[i])) {
            upper += 1;
        } else if (isdigit(attempted_password[i])) {
            digit += 1;
        } else if (isspace(attempted_password[i])) {
            //valid_password = true;
            spacer += 1;
        }
    }

    std::string password;
    std::stringstream convert;
    convert << attempted_password;
    convert >> password;

    std::vector<char> encrypted_password;

    if (lower > 0 && upper > 0 && digit > 0 && spacer == 0) {
        std::cout << "Congratulations your password is: " << password << "\n";
        for (int i = 0; i < password.length(); i++) {
            int ascii_value = int(password[i]);
            char new_char_value = char(ascii_value + 3);
            encrypted_password.push_back(new_char_value);
        }

        std::string encrypted_password_string(encrypted_password.begin(), encrypted_password.end());
        std::ofstream encrypeted_password_to_file;
        encrypeted_password_to_file.open("Employee_passwords.txt", std::ios::app);
        encrypeted_password_to_file << password << " " << encrypted_password_string << "\n";
        std::ofstream Encrypted_Password_File;
        Encrypted_Password_File.open("Users.txt", std::ios::app);
        Encrypted_Password_File << encrypted_password_string << "\n";
    } else {
        std::cout << "That was an invalid password, check and try again\n";
        creating_employee_password();
    }
}

/*
 * This function accpets two strings which are the employee username, and the employee password. These strings
 * are checked to see if they are inside of a txt file that has all of the current employee information stored
 * if it is in the txt file then the employee can login, and rack production, produce new products, and new products to
 * the production line. While also gathering company statistics, and getting production numbers from a products
 * serial number.
 */
void employee_login(Employee_Login_Process &Login_Inputs) {
    std::cin.ignore();
    std::string first_employee;
    std::ifstream making_first_employee("Employee_passwords.txt");
    if (getline(making_first_employee, first_employee).fail()) {
        creating_employee_account();
        creating_employee_password();
    } else {
        std::cout << "Welcome back: \n";
    }

    Employee_Username_Login(Login_Inputs);


    if (Login_Inputs.User_Name_Input == Login_Inputs.User_Password_Input) {
        std::cout << "Welcome back: \n";
    } else {
        std::cout << "Invalid Username or Password. Check and try again.\n";
        employee_login(Login_Inputs);
    }
}

void Employee_Username_Login(Employee_Login_Process &Login_Inputs) {
    std::cout << "Please enter your employee username: \n";
    std::string Attempted_Username_Login;
    getline(std::cin, Attempted_Username_Login);
    std::string employee_information;
    std::ifstream employee_attempted_login("Employee_passwords.txt");
    std::vector<std::string> Checking_Username;

    std::string test_attempted_username = " " + Attempted_Username_Login + " ";

    if (employee_attempted_login.is_open()) {
        while (getline(employee_attempted_login, employee_information)) {
            Checking_Username.push_back(employee_information);
        }
        employee_attempted_login.close();
    }

    for (int i = 0; i < Checking_Username.size(); i++) {
        if (Checking_Username[i].find(test_attempted_username) != std::string::npos) {
            Login_Inputs.User_Name_Input = i;
        }
    }

    if (Login_Inputs.User_Name_Input == -1) {
        std::cout << "Incorrect Username: Try Again:\n";
        Employee_Username_Login(Login_Inputs);
    } else {
        Employee_Password_Login(Login_Inputs);
    }
    //std::cin.ignore();
}

void Employee_Password_Login(Employee_Login_Process &Login_Inputs) {
    std::cout << "Please enter your employee password:\n";
    std::string Attempted_Password_Login;
    getline(std::cin, Attempted_Password_Login);

    std::string employee_information;
    std::ifstream employee_attempted_login("Employee_passwords.txt");
    std::vector<std::string> checking_password;
    std::string test_attempted_password = " " + Attempted_Password_Login + " ";

    if (employee_attempted_login.is_open()) {
        while (getline(employee_attempted_login, employee_information)) {
            checking_password.push_back(employee_information);
        }
        employee_attempted_login.close();
    }


    for (int i = 0; i < checking_password.size(); i++) {

        if (checking_password[i].find(test_attempted_password) != std::string::npos) {
            Login_Inputs.User_Password_Input = i;
        }
    }

    if (Login_Inputs.User_Password_Input == -1 || Login_Inputs.User_Password_Input != Login_Inputs.User_Name_Input) {
        std::cout << "Invalid Password: Try Again:\n";
        Employee_Password_Login(Login_Inputs);
    } else {
        std::cout << "\n";
    }
    //std::cin.ignore();
}

//If the program has no current employees login in. This method prompts the user to create an employee account.
void getting_program_started(Employee_Login_Process &Login_Inputs) {
    std::cout << "Type the number For Your Desired Option.\n";
    std::cout << "1.) Login\n";
    std::cout << "2.) Create Employee Account.\n";
    int Getting_Started_Input;
    std::cin >> Getting_Started_Input;

    switch (Getting_Started_Input) {
        case 1:
            employee_login(Login_Inputs);
            break;
        case 2:
            creating_employee_account();
            creating_employee_password();
            break;
    }
}
