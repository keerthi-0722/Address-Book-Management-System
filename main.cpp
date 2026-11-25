#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structure to store contact details
struct Contact
{
    string name;
    string phone;
    string email;
    string address;
};

// Maximum number of contacts
const int MAX_CONTACTS = 100;

Contact contacts[MAX_CONTACTS];
int contactCount = 0;

// Function to add a contact
void addContact()
{
    if (contactCount >= MAX_CONTACTS)
    {
        cout << "\nAddress Book is full!\n";
        return;
    }

    cout << "\n----- Add Contact -----\n";

    cin.ignore();

    cout << "Enter Name    : ";
    getline(cin, contacts[contactCount].name);

    cout << "Enter Phone   : ";
    getline(cin, contacts[contactCount].phone);

    cout << "Enter Email   : ";
    getline(cin, contacts[contactCount].email);

    cout << "Enter Address : ";
    getline(cin, contacts[contactCount].address);

    contactCount++;

    cout << "\nContact added successfully!\n";
}

// Function to display all contacts
void displayContacts()
{
    if (contactCount == 0)
    {
        cout << "\nNo contacts available.\n";
        return;
    }

    cout << "\n========== All Contacts ==========\n";

    for (int i = 0; i < contactCount; i++)
    {
        cout << "\nContact " << i + 1 << endl;
        cout << "Name    : " << contacts[i].name << endl;
        cout << "Phone   : " << contacts[i].phone << endl;
        cout << "Email   : " << contacts[i].email << endl;
        cout << "Address : " << contacts[i].address << endl;
    }
}

// Function to search for a contact
void searchContact()
{
    if (contactCount == 0)
    {
        cout << "\nNo contacts available.\n";
        return;
    }

    string searchName;
    bool found = false;

    cin.ignore();

    cout << "\nEnter name to search: ";
    getline(cin, searchName);

    for (int i = 0; i < contactCount; i++)
    {
        // String handling using find()
        if (contacts[i].name.find(searchName) != string::npos)
        {
            cout << "\nContact Found!\n";
            cout << "Name    : " << contacts[i].name << endl;
            cout << "Phone   : " << contacts[i].phone << endl;
            cout << "Email   : " << contacts[i].email << endl;
            cout << "Address : " << contacts[i].address << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "\nContact not found.\n";
    }
}

// Function to delete a contact
void deleteContact()
{
    if (contactCount == 0)
    {
        cout << "\nNo contacts available.\n";
        return;
    }

    string deleteName;
    bool found = false;

    cin.ignore();

    cout << "\nEnter name to delete: ";
    getline(cin, deleteName);

    for (int i = 0; i < contactCount; i++)
    {
        if (contacts[i].name == deleteName)
        {
            // Shift remaining contacts
            for (int j = i; j < contactCount - 1; j++)
            {
                contacts[j] = contacts[j + 1];
            }

            contactCount--;
            found = true;

            cout << "\nContact deleted successfully!\n";
            break;
        }
    }

    if (!found)
    {
        cout << "\nContact not found.\n";
    }
}

// Main function - Menu Driven System
int main()
{
    int choice;

    do
    {
        cout << "\n\n====================================";
        cout << "\n       ADDRESS BOOK SYSTEM";
        cout << "\n====================================";
        cout << "\n1. Add Contact";
        cout << "\n2. Display Contacts";
        cout << "\n3. Search Contact";
        cout << "\n4. Delete Contact";
        cout << "\n5. Exit";
        cout << "\n====================================";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addContact();
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                deleteContact();
                break;

            case 5:
                cout << "\nThank you for using Address Book System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
