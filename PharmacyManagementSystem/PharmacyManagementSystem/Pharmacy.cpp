#include <iostream>
#include <string>
#include <fstream>
using namespace std;

///Function definitions before main

void main_menu();
void admin_login();
void admin_menu();
void admin_view();
void admin_search();
void admin_add();
void admin_edit();
void admin_delete();
void admin_expiry();
void admin_history();
void customer_select();
void customer_registration();
void customer_login();
void customer_menu(string username, string password);
void customer_check();
void customer_view();
void customer_purchase(string username, string password);
void customer_details(string username, string password);
void customer_history(string username, string password);


///Main program that calls the function for main menu

int main()
{
    main_menu();
    return 0;
}


///Function that displays the main menu of the program

void main_menu()
{
    int user, loop = 1;
    cout << " ------------------------------------\n";
    cout << "|     WELCOME TO FAIZAN PHARMACY     |\n";
    cout << " ------------------------------------\n";
    while (loop == 1)
    {
        cout << "\nMAIN MENU";
        cout << "\n1. Admin";
        cout << "\n2. Customer";
        cout << "\n3. Exit";
        cout << "\nPlease Select the Type of User You Are: ";
        cin >> user;
        switch (user)
        {
        case 1:
            admin_login();
            break;
        case 2:
            customer_select();
            break;
        case 3:
            cout << "Thank You";
            loop = 0;
            break;
        default:
            cout << "Invalid Input, Please Try Again\n";
            break;
        }
    }
}


///Function to verify the admin username and password that lets the person log in to the admin menu

void admin_login()
{
    int admin = 1, wrong;
    string admin_user, admin_pass;
    cout << "\nWelcome To The Admin Login\n";
    cout << "Enter Admin Username: ";
    cin >> admin_user;
    cout << "Enter Admin Password: ";
    cin >> admin_pass;
    while (admin_user != "admin" || admin_pass != "12345")      ///While loop that repeats if the admin username and password is incorrect
    {
        admin = 0;
        cout << "Incorrect Username or Password\nEnter 1 to Retry or 0 to Exit: ";
        cin >> wrong;
        while (wrong != 1 && wrong != 0)
        {
            cout << "Invalid Input, Please Try Again\n";
            cout << "Enter 1 to Retry or 0 to Exit: ";
            cin >> wrong;
        }
        if (wrong == 1)
        {
            cout << "Enter Admin Username: ";
            cin >> admin_user;
            cout << "Enter Admin Password: ";
            cin >> admin_pass;
            admin = 1;
        }
        else if (wrong == 0)
        {
            break;
        }
    }
    if (admin == 1)     ///If admin username and password are correct the function for admin menu is called
    {
        admin_menu();
    }
}


///Function that displays the menu with all the admin functionalities

void admin_menu()
{
    int admin, loop = 1;
    while (loop == 1)
    {
        cout << "\nADMIN MENU";
        cout << "\n1. View All Medicines";
        cout << "\n2. View Specific Medicine";
        cout << "\n3. Add New Medicine";
        cout << "\n4. Modifiy Existing Medicine";
        cout << "\n5. Delete Existing Medicine";
        cout << "\n6. View Expiry Dates Of All Medicines";
        cout << "\n7. View Transaction History";
        cout << "\n8. Exit";
        cout << "\nPlease Select One Of The Options : ";
        cin >> admin;
        switch (admin)
        {
        case 1:
            admin_view();
            break;
        case 2:
            admin_search();
            break;
        case 3:
            admin_add();
            break;
        case 4:
            admin_edit();
            break;
        case 5:
            admin_delete();
            break;
        case 6:
            admin_expiry();
            break;
        case 7:
            admin_history();
            break;
        case 8:
            loop = 0;
            break;
        default:
            cout << "Invalid Input, Please Try Again\n";
            break;
        }
    }
}


///Function to display all medicine details 

void admin_view()
{
    fstream med;
    string name, company, md1, md2, md3, ed1, ed2, ed3, price, stock;
    int count = 1, exit = 1;
    med.open("Medicine Details.txt", ios::in);
    if (med.is_open())
    {
        while (med >> name >> company >> md1 >> md2 >> md3 >> ed1 >> ed2 >> ed3 >> price >> stock)      ///While loop reads file and places string separated by whitespace into the variables repeatedly
        {
            cout << "\nSerial Number: " << count;
            cout << "\nMedicine Name: " << name;
            cout << "\nCompany: " << company;
            cout << "\nDate Of Manufacture: " << md1 << "/" << md2 << "/" << md3;
            cout << "\nDate Of Expiry: " << ed1 << "/" << ed2 << "/" << ed3;
            cout << "\nPrice: RM" << price;
            cout << "\nQuantity In Stock: " << stock << endl;
            count += 1;
        }
    }
    med.close();
    cout << "\n";
    while (exit != 0)
    {
        cout << "Enter 0 to Return to Menu: ";
        cin >> exit;
        if (exit != 0)
        {
            cout << "Invalid Input, Please Try Again\n";
        }
    }
}


///Function to display a sepcific medicine

void admin_search()
{
    fstream med1, med2;
    string sname, name, company, md1, md2, md3, ed1, ed2, ed3, price, stock;
    int count1 = 1, count2 = 1, exit = 1, found = 0, found2 = 0;
    med1.open("Medicine Details.txt", ios::in);
    if (med1.is_open())
    {
        cout << endl;
        while (med1 >> name >> company >> md1 >> md2 >> md3 >> ed1 >> ed2 >> ed3 >> price >> stock)
        {
            cout << count1 << ". " << name << endl;
            found = 1;
            count1 += 1;
        }
    }
    med1.close();
    if (found == 0)
    {
        cout << "No Record Found\n";
    }
    else
    {
        cout << "\nEnter the Name of the Medicine You Want to Search: ";        ///Takes name of medicine to search
        cin >> sname;
        med2.open("Medicine Details.txt", ios::in);
        if (med2.is_open())
        {
            while (med2 >> name >> company >> md1 >> md2 >> md3 >> ed1 >> ed2 >> ed3 >> price >> stock)         ///While loop that reads and places string separated by whitespace into the variables repeatedly
            {
                if (name == sname)          ///Matches the medicine name enterd by the customer to the details in the text file
                {
                    cout << "\nSerial Number: " << count2;
                    cout << "\nMedicine Name: " << name;
                    cout << "\nCompany: " << company;
                    cout << "\nDate Of Manufacture: " << md1 << "/" << md2 << "/" << md3;
                    cout << "\nDate Of Expiry: " << ed1 << "/" << ed2 << "/" << ed3;
                    cout << "\nPrice: RM" << price;
                    cout << "\nQuantity In Stock: " << stock << endl;
                    found2 = 1;
                }
                count2 += 1;
            }
        }
        med2.close();
        if (found2 == 0)        ///Error message if the name doesnt match
        {
            cout << "Medicine With Entered Name Not Found\n";
        }
        cout << "\n";
        while (exit != 0)
        {
            cout << "Enter 0 to Return to Menu: ";
            cin >> exit;
            if (exit != 0)
            {
                cout << "Invalid Input, Please Try Again\n";
            }
        }
    }
}


///Function to add the details for a new medicine to the text file

void admin_add()
{
    fstream med;
    string name, company, md1, md2, md3, ed1, ed2, ed3, price, stock;
    int ok = 0, confirm = 2, exit = 1;
    while (ok == 0)
    {
        cout << "\nPlease Enter The Details Of The Medicine\n";
        cout << "Medicine Name: ";
        cin >> name;
        cout << "Company Name: ";
        cin >> company;
        cout << "Date Of Manufacture (DD/MM/YYYY): \n";
        cout << "Day: ";
        cin >> md1;
        while (stoi(md1) <= 0 || stoi(md1) >= 32)           ///Checks if the day entered is valid or not 
        {
            cout << "Invalid Input, Please Try Again\n";
            cout << "Day: ";
            cin >> md1;
        }
        cout << "Month: ";
        cin >> md2;
        while (stoi(md2) <= 0 || stoi(md2) >= 13)           ///Checks if the month entered is valid or not
        {
            cout << "Invalid Input, Please Try Again\n";
            cout << "Month: ";
            cin >> md2;
        }
        cout << "Year: ";
        cin >> md3;
        cout << "Date Of Expiry (DD/MM/YYYY): \n";
        cout << "Day: ";
        cin >> ed1;
        while (stoi(ed1) <= 0 || stoi(ed1) >= 32)           ///Checks if the day entered is valid or not 
        {
            cout << "Invalid Input, Please Try Again\n";
            cout << "Day: ";
            cin >> ed1;
        }
        cout << "Month: ";
        cin >> ed2;
        while (stoi(ed2) <= 0 || stoi(ed2) >= 13)           ///Checks if the month entered is valid or not 
        {
            cout << "Invalid Input, Please Try Again\n";
            cout << "Month: ";
            cin >> ed2;
        }
        cout << "Year: ";
        cin >> ed3;
        if (stoi(ed3) < 2022)                                   ///Checks if the exipiry year is past the current year or not
        {
            cout << "Warning, Medicine is Past Expiry Date\n";
        }
        cout << "Price: ";
        cin >> price;
        cout << "Quantity Of Stock: ";
        cin >> stock;
        while (confirm != 1 && confirm != 0)
        {
            cout << "Enter 1 to Confirm or 0 to Cancel: ";
            cin >> confirm;
            if (confirm == 1)
            {
                ok = 1;
            }
            else if (confirm == 0)
            {
                ok = 2;
            }
            else
            {
                cout << "Invalid Input, Please Try Again\n";
            }
        }
    }
    if (ok == 1)            ///Adds the new details to the file if confirmed
    {
        med.open("Medicine Details.txt", ios::app);
        if (med.is_open())
        {
            med << name << "\t" << company << "\t" << md1 << " " << md2 << " " << md3 << "\t" << ed1 << " " << ed2 << " " << ed3 << "\t" << price << "\t" << stock << endl;
            cout << "\nMedicine Added Successfully\n";
            while (exit != 0)
            {
                cout << "Enter 0 to Return to Menu: ";
                cin >> exit;
                if (exit != 0)
                {
                    cout << "Invalid Input, Please Try Again\n";
                }
            }
        }
        med.close();
    }
}


///Function the edit the details of a specific medicine

void admin_edit()
{
    fstream med1, med2, med3;
    string name, name2, company, company2, md1, md2, md3, m1, m2, m3, ed1, ed2, ed3, e1, e2, e3, price, price2, stock, stock2;
    int count1 = 1, count2 = 1, exit, found = 0, retry = 1, select = 0, loop = 0, edit, exit2 = 1;
    med1.open("Medicine Details.txt", ios::in);
    if (med1.is_open())
    {
        while (med1 >> name >> company >> md1 >> md2 >> md3 >> ed1 >> ed2 >> ed3 >> price >> stock)
        {
            cout << count1 << ". " << name << endl;
            found = 1;
            count1 += 1;
        }
    }
    med1.close();
    if (found == 0)
    {
        cout << "No Record Found\n";
    }
    else
    {
        while (retry == 1)
        {
            exit = 2;
            cout << "Enter the Name of the Medicine You Want to Edit: ";        ///Receives the name of medicine to edit
            cin >> name2;
            med2.open("Medicine Details.txt", ios::in);
            med3.open("temp.txt", ios::app);
            if (med2.is_open() && med3.is_open())
            {
                while (med2 >> name >> company >> md1 >> md2 >> md3 >> ed1 >> ed2 >> ed3 >> price >> stock)
                {
                    if (name == name2)          ///If name matches the file, shows details of medicine
                    {
                        cout << "\nSerial Number: " << count2;
                        cout << "\nMedicine Name: " << name;
                        cout << "\nCompany: " << company;
                        cout << "\nDate Of Manufacture: " << md1 << "/" << md2 << "/" << md3;
                        cout << "\nDate Of Expiry: " << ed1 << "/" << ed2 << "/" << ed3;
                        cout << "\nPrice: RM" << price;
                        cout << "\nQuantity In Stock: " << stock << endl;
                        name2 = name;
                        company2 = company;
                        m1 = md1;
                        m2 = md2;
                        m3 = md3;
                        e1 = ed1;
                        e2 = ed2;
                        e3 = ed3;
                        price2 = price;
                        stock2 = stock;
                        while (loop == 0)
                        {
                            cout << "\n1. Medicne Name";                                ///Options for which detail to edit
                            cout << "\n2. Company Name";
                            cout << "\n3. Date Of Manufacture";
                            cout << "\n4. Date Of Expiry";
                            cout << "\n5. Price";
                            cout << "\n6. Stock";
                            cout << "\n7. Confirm";
                            cout << "\n8. Cancel";
                            cout << "\nSelect the Detail You Would Like to Edit : ";
                            cin >> edit;
                            switch (edit)               ///Switch case to change the details of the medicine
                            {
                            case 1:
                                cout << "\nCurrent Name: " << name2 << "\nNew Name: ";
                                cin >> name2;
                                cout << "\nContinue Editing or Confirm To Save Changes";
                                break;
                            case 2:
                                cout << "\nCurrent Company Name: " << company2 << "\nNew Company Name: ";
                                cin >> company2;
                                cout << "\nContinue Editing or Confirm To Save Changes";
                                break;
                            case 3:
                                cout << "\nCurrent Date Of Manufacture: " << m1 << "/" << m2 << "/" << m3 << "\nNew Date Of Manufacture (DD/MM/YYYY):\n";
                                cout << "Day: ";
                                cin >> m1;
                                while (stoi(m1) <= 0 || stoi(m1) >= 32)             ///Day validation
                                {
                                    cout << "Invalid Input, Please Try Again\n";
                                    cout << "Day: ";
                                    cin >> md1;
                                }
                                cout << "Month: ";
                                cin >> m2;
                                while (stoi(m2) <= 0 || stoi(m2) >= 13)             ///Month validation
                                {
                                    cout << "Invalid Input, Please Try Again\n";
                                    cout << "Month: ";
                                    cin >> m2;
                                }
                                cout << "Year: ";
                                cin >> m3;
                                cout << "New Date Of Manufacture: " << m1 << "/" << m2 << "/" << m3 << endl;
                                cout << "\nContinue Editing or Confirm To Save Changes";
                                break;
                            case 4:
                                cout << "\nCurrent Date Of Expiry: " << e1 << "/" << e2 << "/" << e3 << "\nNew Date Of Expiry (DD/MM/YYYY):\n";
                                cout << "Day: ";
                                cin >> e1;
                                while (stoi(e1) <= 0 || stoi(e1) >= 32)             ///Day validation
                                {
                                    cout << "Invalid Input, Please Try Again\n";
                                    cout << "Day: ";
                                    cin >> e1;
                                }
                                cout << "Month: ";
                                cin >> e2;
                                while (stoi(e2) <= 0 || stoi(e2) >= 13)             ///Month validation
                                {
                                    cout << "Invalid Input, Please Try Again\n";
                                    cout << "Month: ";
                                    cin >> e2;
                                }
                                cout << "Year: ";
                                cin >> e3;
                                if (stoi(e3) < 2022)                                    ///Checks if the year of expiry is past current year or not
                                {
                                    cout << "Warning, Medicine is Past Expiry Date\n";
                                }
                                cout << "New Date Of Expiry: " << e1 << "/" << e2 << "/" << e3 << endl;
                                cout << "\nContinue Editing or Confirm To Save Changes";
                                break;
                            case 5:
                                cout << "\nCurrent Price: RM" << price2 << "\nNew Price: RM";
                                cin >> price2;
                                cout << "\nContinue Editing or Confirm To Save Changes";
                                break;
                            case 6:
                                cout << "\nCurrent Quantity In Stock: " << stock2 << "\nNew Quantity In Stock: ";
                                cin >> stock2;
                                cout << "\nContinue Editing or Confirm To Save Changes";
                                break;
                            case 7:         ///Saves changes if the option to confirm is selected
                                med3 << name2 << "\t" << company2 << "\t" << m1 << " " << m2 << " " << m3 << "\t" << e1 << " " << e2 << " " << e3 << "\t" << price2 << "\t" << stock2 << endl;
                                cout << "\nChanges Have Been Saved\n";
                                while (exit2 != 0)
                                {
                                    cout << "Enter 0 to Return to Menu: ";
                                    cin >> exit2;
                                    if (exit2 != 0)
                                    {
                                        cout << "Invalid Input, Please Try Again\n";
                                    }
                                }
                                loop = 1;
                                break;
                            case 8:
                                med3 << name << "\t" << company << "\t" << md1 << " " << md2 << " " << md3 << "\t" << ed1 << " " << ed2 << " " << ed3 << "\t" << price << "\t" << stock << endl;
                                loop = 1;
                                break;
                            default:
                                cout << "Invalid Input, Please Try Again\n";
                                break;
                            }
                        }
                        retry = 0;
                    }
                    else
                    {
                        med3 << name << "\t" << company << "\t" << md1 << " " << md2 << " " << md3 << "\t" << ed1 << " " << ed2 << " " << ed3 << "\t" << price << "\t" << stock << endl;
                    }
                    count2 += 1;
                }
            }
            if (retry == 1)
            {
                cout << "No Record Found\n";
                count2 = 1;
                while (exit != 1 && exit != 0)
                {
                    cout << "Enter 1 to Retry or 0 to Exit: ";
                    cin >> exit;
                    if (exit != 1 && exit != 0)
                    {
                        cout << "Invalid Input, Please Try Again\n";
                    }
                    else if (exit == 0)
                    {
                        retry = 0;
                    }
                }
            }
            med2.close();
            med3.close();
            remove("Medicine Details.txt");                             ///Deletes the original file with old details
            rename("temp.txt", "Medicine Details.txt");    ///Changes temp file to original file with new details
        }
    }
}


///Function to delete a record form the text file

void admin_delete()
{
    fstream med1, med2, med3;
    string name, name2, company, md1, md2, md3, ed1, ed2, ed3, price, stock;
    int count = 1, count2 = 1, exit, found = 0, retry = 1, select = 0, loop = 0, confirm, exit2 = 1;
    med1.open("Medicine Details.txt", ios::in);
    if (med1.is_open())
    {
        while (med1 >> name >> company >> md1 >> md2 >> md3 >> ed1 >> ed2 >> ed3 >> price >> stock)
        {
            cout << count << ". " << name << endl;
            count += 1;
            found = 1;
        }

    }
    med1.close();
    if (found == 0)
    {
        cout << "No Record Found\n";
    }
    else
    {
        while (retry == 1)
        {
            exit = 2;
            cout << "Enter the Name of the Medicine You Want to Delete: ";          ///Receives name of medicine to delete
            cin >> name2;
            med2.open("Medicine Details.txt", ios::in);
            med3.open("temp.txt", ios::app);
            if (med2.is_open() && med3.is_open())
            {
                while (med2 >> name >> company >> md1 >> md2 >> md3 >> ed1 >> ed2 >> ed3 >> price >> stock)
                {
                    if (name == name2)          ///If case to check if the name matches in text file 
                    {
                        cout << "\nSerial Number: " << count2;
                        cout << "\nMedicine Name: " << name;
                        cout << "\nCompany: " << company;
                        cout << "\nDate Of Manufacture: " << md1 << "/" << md2 << "/" << md3;
                        cout << "\nDate Of Expiry: " << ed1 << "/" << ed2 << "/" << ed3;
                        cout << "\nPrice: RM" << price;
                        cout << "\nQuantity In Stock: " << stock << endl;
                        cout << "\nAre You Sure You Want to Delete This Record?\nEnter 1 to Confirm or 0 to Exit: ";
                        cin >> confirm;
                        while (confirm != 1 && confirm != 0)
                        {
                            cout << "Invalid Input, Please Try Again\n";
                            cout << "Enter 1 to Confirm or 0 to Exit: ";
                            cin >> confirm;
                        }
                        if (confirm == 0)
                        {
                            med3 << name << "\t" << company << "\t" << md1 << " " << md2 << " " << md3 << "\t" << ed1 << " " << ed2 << " " << ed3 << "\t" << price << "\t" << stock << endl;
                        }
                        else
                        {
                            cout << "\nRecord Has Been Deleted Successfully\n";
                            while (exit != 0)
                            {
                                cout << "Enter 0 to Return to Menu: ";
                                cin >> exit;
                                if (exit != 0)
                                {
                                    cout << "Invalid Input, Please Try Again\n";
                                }
                            }
                        }
                        retry = 0;
                    }
                    else
                    {
                        med3 << name << "\t" << company << "\t" << md1 << " " << md2 << " " << md3 << "\t" << ed1 << " " << ed2 << " " << ed3 << "\t" << price << "\t" << stock << endl;
                    }
                    count2 += 1;
                }
            }
            if (retry == 1)
            {
                cout << "No Record Found\n";
                count2 = 1;
                while (exit != 1 && exit != 0)
                {
                    cout << "Enter 1 to Retry or 0 to Exit: ";
                    cin >> exit;
                    if (exit != 1 && exit != 0)
                    {
                        cout << "Invalid Input, Please Try Again\n";
                    }
                    else if (exit == 0)
                    {
                        retry = 0;
                    }
                }
            }
            med2.close();
            med3.close();
            remove("Medicine Details.txt");                             ///Deletes original file
            rename("temp.txt", "Medicine Details.txt");    ///Replaces temp file to original file
        }
    }
}


///Function to display expiry dates of all medicines in months

void admin_expiry()
{
    fstream med;
    string name, company, md1, md2, md3, ed1, ed2, ed3, price, stock;
    int count, exit = 1, e1, e2, e3, e4;
    med.open("Medicine Details.txt", ios::in);
    if (med.is_open())
    {
        count = 1;
        cout << endl;
        while (med >> name >> company >> md1 >> md2 >> md3 >> ed1 >> ed2 >> ed3 >> price >> stock)
        {
            e1 = stoi(ed3);         ///Calculates months remaining tillexpiry dates August 2022
            e2 = e1 - 2022;
            e3 = stoi(ed2);
            e4 = (e3 - 8) + (e2 * 12);
            if (e4 < 0)                 ///Cheks if it is expired already or not
            {
                cout << count << ". " << name << ": Already Expired" << endl << endl;
            }
            else
            {
                cout << count << ". " << name << ": Expiring in " << e4 << " months" << endl << endl;
            }
            count += 1;
        }
        while (exit != 0)
        {
            cout << "Enter 0 to Return to Menu: ";
            cin >> exit;
            if (exit != 0)
            {
                cout << "Invalid Input, Please Try Again\n";
            }
        }
    }
    med.close();
}


///Function to view the history of all the transactions taken place using the website

void admin_history()
{
    fstream transac;
    string username, fname, lname, phone, mname, price, qnt, total, card;
    int count = 1, found = 0, exit = 1;
    transac.open("Transaction Details.txt", ios::in);
    if (transac.is_open())
    {
        while (transac >> username >> fname >> lname >> phone >> mname >> price >> qnt >> total >> card)        ///Displays records from the transaction file
        {
            cout << "\nSerial Number: " << count;
            cout << "\nUsername: " << username;
            cout << "\nName: " << fname << " " << lname;
            cout << "\nPhone Number: " << phone;
            cout << "\nMedicine Purchased: " << mname;
            cout << "\nPrice: " << price;
            cout << "\nQuantity: " << qnt;
            cout << "\nTotal Amount: " << total << endl;
            found = 1;
            count += 1;
        }
    }
    if (found == 0)
    {
        cout << "No Record Found\n";
    }
    while (exit != 0)
    {
        cout << "\nEnter 0 to Return to Menu: ";
        cin >> exit;
        if (exit != 0)
        {
            cout << "Invalid Input, Please Try Again\n";
        }
    }
}


///Function to let the customer choose between new customer and a registered one

void customer_select()
{
    int customer, loop = 1;
    while (loop == 1)
    {
        cout << "\nCUSTOMER SELECTION MENU";
        cout << "\n1. New Customer";
        cout << "\n2. Registered Customer";
        cout << "\n3. Exit";
        cout << "\nPlease Select One of the Options : ";
        cin >> customer;
        switch (customer)
        {
        case 1:
            customer_registration();
            break;
        case 2:
            customer_login();
            break;
        case 3:
            loop = 0;
            break;
        default:
            cout << "Invalid Input, Please Try Again\n";
        }
    }

}


///Function to let the customer register if new customer

void customer_registration()
{
    fstream usercheck, registration;
    string username, u1, p1, p2, password, fname, lname, gender, email, number;
    int age, ok1 = 0, ok2 = 0, retry1 = 1, retry2 = 1, exit = 1;
    cout << "\nWelcome To Customer Registration\nPlease Enter the Following Details:\n";
    while (retry1 == 1)
    {
        cout << "Enter a Username: ";
        cin >> username;
        usercheck.open("Customer Details.txt", ios::in);
        if (usercheck.is_open())
        {
            while (usercheck >> u1)
            {
                if (username == u1)         ///Checks if the username is already taken or not
                {
                    cout << "Username Already Exists\nEnter 1 to Retry or 0 to Exit: ";     ///Error message if it isnt unique
                    cin >> retry1;
                    while (retry1 != 1 && retry1 != 0)
                    {
                        cout << "Invalid Input, Please Try Again\n";
                        cout << "Enter 1 to Retry or 0 to Exit: ";
                        cin >> retry1;
                    }
                    if (retry1 == 0)
                    {
                        ok1 = 0;
                    }
                    break;
                }
                else
                {
                    retry1 = 0;
                    ok1 = 1;
                }
            }
        }
        else
        {
            retry1 = 0;
            ok1 = 1;
        }
        usercheck.close();
    }

    if (ok1 == 1)
    {
        while (retry2 == 1)
        {
            cout << "Enter a Password: ";
            cin >> p1;
            cout << "Re-enter the Password: ";
            cin >> p2;
            if (p1 == p2)           ///Checks if the passwords entered 2 times match or not
            {
                password = p1;
                retry2 = 0;
                ok2 = 1;
            }
            else
            {
                cout << "The Passwords Don't Match\nEnter 1 to Retry or 0 to Exit: ";
                cin >> retry2;
                while (retry2 != 1 && retry2 != 0)
                {
                    cout << "Invalid Input, Please Try Again\n";
                    cout << "Enter 1 to Retry or 0 to Exit: ";
                    cin >> retry2;
                }
                if (retry2 == 0)
                {
                    ok2 = 0;
                }
            }
        }
    }

    if (ok2 == 1)
    {
        cout << "First Name: ";         ///Receive registration details
        cin >> fname;
        cout << "Last Name: ";
        cin >> lname;
        cout << "Age: ";
        cin >> age;
        cout << "Gender: ";
        cin >> gender;
        cout << "Email ID: ";
        cin >> email;
        cout << "Phone Number: ";
        cin >> number;
        registration.open("Customer Details.txt", ios::app);
        if (registration.is_open())
        {
            registration << username << "\t" << password << "\t" << fname << " " << lname << "\t" << age << "\t" << gender << "\t" << email << "\t" << number << endl;
            cout << "Registration Successfully Completed\n";
            while (exit != 0)
            {
                cout << "Enter 0 to Return to Menu: ";
                cin >> exit;
                if (exit != 0)
                {
                    cout << "Invalid Input, Please Try Again\n";
                }
            }
        }
        registration.close();
    }
}


///Function to let the customer log in to the menu

void customer_login()
{
    fstream check;
    string username, u2, password, p2;
    int ok = 0, retry = 2;
    cout << "\nWelcome To The Customer Login\n";
    while (ok == 0)
    {
        cout << "Enter Your Username: ";
        cin >> username;
        cout << "Enter Your Password: ";
        cin >> password;
        check.open("Customer Details.txt", ios::in);
        if (check.is_open())
        {
            while (check >> u2 >> p2)
            {
                if (username == u2 && password == p2)       ///Checks if username and password match the file
                {
                    customer_menu(username, password);
                    ok = 1;
                    break;
                }
            }
            if (ok == 0)
            {
                cout << "Incorrect Username or Password\n";
                while (retry != 1 && retry != 0)
                {
                    cout << "Enter 1 to Retry or 0 to Exit: ";
                    cin >> retry;
                    if (retry != 1 && retry != 0)
                    {
                        cout << "Invalid Input, Please Try Again\n";
                    }
                    if (retry == 0)
                    {
                        ok = 1;
                    }
                }
            }
        }
        check.close();
    }
}


///Function the view the customer menu for registerd customers

void customer_menu(string username, string password)        ///Carries username and password entered by customer when logging in
{
    int customer, loop = 1;
    while (loop == 1)
    {
        cout << "\nCUSTOMER MENU";
        cout << "\n1. Check Availability of Medicine";
        cout << "\n2. View Details";
        cout << "\n3. Purchase Medicine";
        cout << "\n4. View Account Details";
        cout << "\n5. View Purchase History";
        cout << "\n6. Exit";
        cout << "\nPlease Select One Of The Options: ";
        cin >> customer;
        switch (customer)
        {
        case 1:
            customer_check();
            break;
        case 2:
            customer_view();
            break;
        case 3:
            customer_purchase(username, password);
            break;
        case 4:
            customer_details(username, password);
            break;
        case 5:
            customer_history(username, password);
            break;
        case 6:
            loop = 0;
            break;
        default:
            cout << "Invalid Input, Please Try Again\n";
            break;
        }
    }
}


///Function to let the customer check if a medicine is available or not

void customer_check()
{
    fstream med;
    string name, company, md1, md2, md3, ed1, ed2, ed3, price, stock;
    int count, stock2, exit = 1;
    med.open("Medicine Details.txt", ios::in);
    if (med.is_open())
    {
        count = 1;
        cout << endl;
        while (med >> name >> company >> md1 >> md2 >> md3 >> ed1 >> ed2 >> ed3 >> price >> stock)
        {
            stock2 = stoi(stock);
            if (stock2 <= 0)
            {
                cout << count << ". " << name << ": Unavailable" << endl << endl;
            }
            else
            {
                cout << count << ". " << name << ": Available" << endl << endl;
            }
            count += 1;
        }
        while (exit != 0)
        {
            cout << "Enter 0 to Return to Menu: ";
            cin >> exit;
            if (exit != 0)
            {
                cout << "Invalid Input, Please Try Again\n";
            }
        }
    }
    med.close();
}


///Functions to let customers view details for specific medicines

void customer_view()
{
    fstream med1, med2;
    string sname, name, company, md1, md2, md3, ed1, ed2, ed3, price, stock;
    int count1 = 1, count2 = 1, exit = 1, found = 0, found2 = 0;
    med1.open("Medicine Details.txt", ios::in);
    if (med1.is_open())
    {
        cout << endl;
        while (med1 >> name >> company >> md1 >> md2 >> md3 >> ed1 >> ed2 >> ed3 >> price >> stock)
        {
            cout << count1 << ". " << name << endl;
            found = 1;
            count1 += 1;
        }
    }
    med1.close();
    if (found == 0)
    {
        cout << "No Record Found\n";
    }
    else
    {
        cout << "\nEnter the Name of the Medicine You Want to View Details For: ";
        cin >> sname;
        med2.open("Medicine Details.txt", ios::in);
        if (med2.is_open())
        {
            while (med2 >> name >> company >> md1 >> md2 >> md3 >> ed1 >> ed2 >> ed3 >> price >> stock)
            {
                if (name == sname)          ///Matches the medicine name enterd by the customer to the details in the text file
                {
                    cout << "\nSerial Number: " << count2;
                    cout << "\nMedicine Name: " << name;
                    cout << "\nCompany: " << company;
                    cout << "\nDate Of Manufacture: " << md1 << "/" << md2 << "/" << md3;
                    cout << "\nDate Of Expiry: " << ed1 << "/" << ed2 << "/" << ed3;
                    cout << "\nPrice: RM" << price << endl;
                    found2 = 1;
                }
                count2 += 1;
            }
        }
        med2.close();
        if (found2 == 0)
        {
            cout << "Medicine With Entered Name Not Found\n";
        }
        cout << "\n";
        while (exit != 0)
        {
            cout << "Enter 0 to Return to Menu: ";
            cin >> exit;
            if (exit != 0)
            {
                cout << "Invalid Input, Please Try Again\n";
            }
        }
    }
}


///Function to let the customer purchase a medicine from the website

void customer_purchase(string username, string password)
{
    fstream med1, med2, med3, customer, transac;
    string sname, name, company, md1, md2, md3, ed1, ed2, ed3, price, stock, card, cvv, exp1, exp2, exp3, cuser, cpass, cfname, cfname2, clname, clname2, cage, cgender, cemail, cphone;
    int count1 = 1, found = 0, found2 = 0, retry = 1, quantity, total, confirm = 2, newstock, exit = 0;
    med1.open("Medicine Details.txt", ios::in);
    if (med1.is_open())
    {
        cout << endl;
        while (med1 >> name >> company >> md1 >> md2 >> md3 >> ed1 >> ed2 >> ed3 >> price >> stock)         ///Displays the options to the customer
        {
            cout << count1 << ". " << name << endl;
            found = 1;
            count1 += 1;
        }
    }
    med1.close();
    if (found == 0)
    {
        cout << "No Record Found\n";
        exit = 1;
    }
    else
    {
        while (retry == 1)
        {
            cout << "\nEnter the Name of the Medicine You Want to Buy: ";           ///Customer enters name of the medicine they want to buy
            cin >> sname;

            med2.open("Medicine Details.txt", ios::in);
            med3.open("temp.txt", ios::app);
            if (med2.is_open())
            {
                while (med2 >> name >> company >> md1 >> md2 >> md3 >> ed1 >> ed2 >> ed3 >> price >> stock)
                {
                    if (name == sname)          ///Checks if the name exists in the file
                    {
                        found2 = 1;
                        cout << "Price: RM" << price << endl;
                        cout << "Enter the Quantity You Want to Buy: ";
                        cin >> quantity;
                        if (quantity > stoi(stock))     ///Checks if the amount they want exists in the stock or not
                        {
                            med3 << name << "\t" << company << "\t" << md1 << " " << md2 << " " << md3 << "\t" << ed1 << " " << ed2 << " " << ed3 << "\t" << price << "\t" << stock << endl;
                            cout << "Not Enough In Stock\n";            ///Displays error message if not enugh in stock
                            retry = 0;
                            exit = 1;
                        }
                        else
                        {
                            total = stoi(price) * quantity;                         ///Calculates price of total quantity
                            cout << "Total Amount Is: RM" << total << endl;
                            cout << "Enter Your Credit Card Number: ";                  ///Receives payment details from the customer
                            cin >> card;
                            cout << "Enter Your CVV: ";
                            cin >> cvv;
                            cout << "Enter Your Credit Card Expiry Date (DD/MM/YYYY):\n";
                            cout << "Day: ";
                            cin >> exp1;
                            cout << "Month: ";
                            cin >> exp2;
                            cout << "Year: ";
                            cin >> exp3;
                            while (confirm != 1 && confirm != 0)
                            {
                                cout << "\nPurchase Confirmation\nEnter 1 to Confirm or 0 to Cancel: ";
                                cin >> confirm;
                                if (confirm != 1 && confirm != 0)
                                {
                                    cout << "Invalid Input, Please Try Again\n";
                                }
                            }
                            if (confirm == 1)       ///If the transaction is confirmed the details are recorded in a transaction file
                            {
                                customer.open("Customer Details.txt", ios::in);
                                transac.open("Transaction Details.txt", ios::app);
                                if (customer.is_open() && transac.is_open())
                                {
                                    while (customer >> cuser >> cpass >> cfname >> clname >> cage >> cgender >> cemail >> cphone)
                                    {
                                        if (username == cuser && password == cpass)
                                        {
                                            cfname2 = cfname;
                                            clname2 = clname;
                                            transac << cuser << "\t" << cfname << " " << clname << "\t" << cphone << "\t" << name << "\t" << price << "\t" << quantity << "\t" << total << "\t" << card << endl;
                                        }
                                    }
                                }
                                customer.close();
                                transac.close();
                                newstock = stoi(stock) - quantity;
                                med3 << name << "\t" << company << "\t" << md1 << " " << md2 << " " << md3 << "\t" << ed1 << " " << ed2 << " " << ed3 << "\t" << price << "\t" << newstock << endl;
                                cout << "Purchase Completed Successfully\n";
                                cout << "\n ---------------------------------------";           ///Displays rececipt to the customer
                                cout << "\n|                RECEIPT                |";
                                cout << "\n ---------------------------------------";
                                cout << "\n  Customer Name: " << cfname2 << " " << clname2;
                                cout << "\n  Purchased Medicine: " << name;
                                cout << "\n  Price: RM" << price;
                                cout << "\n  Quantity: " << quantity;
                                cout << "\n  Total Amount: RM" << total;
                                cout << "\n ---------------------------------------";
                                cout << "\n|    Thank You For Shopping With Us!    |";
                                cout << "\n ---------------------------------------";
                                cout << endl << endl;
                                retry = 0;
                                exit = 1;
                            }
                            else
                            {
                                med3 << name << "\t" << company << "\t" << md1 << " " << md2 << " " << md3 << "\t" << ed1 << " " << ed2 << " " << ed3 << "\t" << price << "\t" << stock << endl;
                                exit = 0;
                                retry = 0;
                            }
                        }
                    }
                    else
                    {
                        med3 << name << "\t" << company << "\t" << md1 << " " << md2 << " " << md3 << "\t" << ed1 << " " << ed2 << " " << ed3 << "\t" << price << "\t" << stock << endl;
                    }
                }
            }
            med2.close();
            med3.close();
            remove("Medicine Details.txt");
            rename("temp.txt", "Medicine Details.txt");
            if (found2 == 0)
            {
                cout << "No Record Found\n";
                cout << "Enter 1 to Retry or 0 to Exit: ";
                cin >> retry;
                while (retry != 1 && retry != 0)
                {
                    cout << "Invalid Input, Please Try Again\n";
                    cout << "Enter 1 to Retry or 0 to Exit: ";
                    cin >> retry;
                }
                if (retry == 0)
                {
                    exit = 0;
                }
            }
        }
    }
    while (exit != 0)
    {
        cout << "Enter 0 to Return to Menu: ";
        cin >> exit;
        if (exit != 0)
        {
            cout << "Invalid Input, Please Try Again\n";
        }
    }
}


///Function to let the customer view their account details

void customer_details(string username, string password)
{
    fstream customer;
    string user, pass, fname, lname, age, gender, email, phone;
    int exit = 1;
    customer.open("Customer Details.txt", ios::in);
    if (customer.is_open())
    {
        while (customer >> user >> pass >> fname >> lname >> age >> gender >> email >> phone)
        {
            if (username == user && password == pass)       ///Matches the username and password enterd by the customer while loggin in to the customer details file
            {
                cout << "\nUsername: " << user;
                cout << "\nName: " << fname << " " << lname;
                cout << "\nAge: " << age;
                cout << "\nGender: " << gender;
                cout << "\nEmail ID: " << email;
                cout << "\nPhone Number: " << phone << endl;
            }
        }
    }
    customer.close();
    cout << "\n";
    while (exit != 0)
    {
        cout << "Enter 0 to Return to Menu: ";
        cin >> exit;
        if (exit != 0)
        {
            cout << "Invalid Input, Please Try Again\n";
        }
    }
}


///Function to let the customer view their purchase history with the website

void customer_history(string username, string password)
{
    fstream transac;
    string user, fname, lname, phone, mname, price, qnt, total, card;
    int count = 1, found = 0, exit = 1;
    transac.open("Transaction Details.txt", ios::in);
    if (transac.is_open())
    {
        while (transac >> user >> fname >> lname >> phone >> mname >> price >> qnt >> total >> card)
        {
            if (user == username)           ///Checks if the username of the customer matches a username in the transaction file
            {
                cout << "\nSerial Number: " << count;
                cout << "\nUsername: " << username;
                cout << "\nName: " << fname << " " << lname;
                cout << "\nPhone Number: " << phone;
                cout << "\nMedicine Purchased: " << mname;
                cout << "\nPrice: " << price;
                cout << "\nQuantity: " << qnt;
                cout << "\nTotal Amount: " << total << endl;
                found = 1;
                count += 1;
            }
        }
    }
    if (found == 0)
    {
        cout << "No Record Found\n";
    }
    while (exit != 0)
    {
        cout << "\nEnter 0 to Return to Menu: ";
        cin >> exit;
        if (exit != 0)
        {
            cout << "Invalid Input, Please Try Again\n";
        }
    }
}