#include "Country.h"
#include "CountryDatabase.h"
#include <iostream>
#include <string>

int main() {
    Country* countries = new Country[10];
    int size = 0;
    int capacity = 10;
    int choice;

    do {
        std::cout << "\nCountry Database Menu:\n";
        std::cout << "1. Add country\n";
        std::cout << "2. Remove country\n";
        std::cout << "3. Edit country\n";
        std::cout << "4. Search country\n";
        std::cout << "5. Print all countries\n";
        std::cout << "6. Save to file\n";
        std::cout << "7. Load from file\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the input buffer

        switch (choice) {
        case 1:
            std::cout << "Enter id,name,capital,population,area";
            CountryDatabase::addCountry(countries, size, capacity);
            break;
        case 2: {
            int id;
            std::cout << "Enter the ID of the country to remove: ";
            std::cin >> id;
            CountryDatabase::removeCountry(countries, size, id);
            break;
        }
        case 3: {
            int id;
            std::cout << "Enter the ID of the country to edit: ";
            std::cin >> id;
            CountryDatabase::editCountry(countries, size, id);
            break;
        }
        case 4: {
            std::string name;
            std::cout << "Enter the name of the country to search: ";
            std::getline(std::cin, name);
            CountryDatabase::searchCountry(countries, size, name);
            break;
        }
        case 5:
            CountryDatabase::printCountries(countries, size);
            break;
        case 6: {
            std::string filename;
            std::cout << "Enter the filename to save to: ";
            std::getline(std::cin, filename);
            CountryDatabase::saveToFile(countries, size, filename);
            break;
        }
        case 7: {
            std::string filename;
            std::cout << "Enter the filename to load from: ";
            std::getline(std::cin, filename);
            CountryDatabase::loadFromFile(countries, size, capacity, filename);
            break;
        }
        case 8:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    delete[] countries;
    return 0;
}