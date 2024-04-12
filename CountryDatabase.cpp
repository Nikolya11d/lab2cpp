#include "CountryDatabase.h"

namespace CountryDatabase {
    void addCountry(Country*& countries, int& size, int& capacity) {
        if (size == capacity) {
            capacity *= 2;
            Country* newCountries = new Country[capacity];
            for (int i = 0; i < size; ++i) {
                newCountries[i] = countries[i];
            }
            delete[] countries;
            countries = newCountries;
        }
        Country newCountry;
        std::cin >> newCountry;
        countries[size++] = newCountry;
    }

    void removeCountry(Country*& countries, int& size, int id) {
        for (int i = 0; i < size; ++i) {
            if (countries[i].getId() == id) {
                for (int j = i; j < size - 1; ++j) {
                    countries[j] = countries[j + 1];
                }
                --size;
                return;
            }
        }
    }

    void editCountry(Country* countries, int size, int id) {
        for (int i = 0; i < size; ++i) {
            if (countries[i].getId() == id) {
                std::cout << "Enter new data for the country (id, name, capital, population, area): ";
                std::cin >> countries[i];
                return;
            }
        }
    }

    void searchCountry(Country* countries, int size, const std::string& name) {
        for (int i = 0; i < size; ++i) {
            if (countries[i].getName() == name) {
                std::cout << countries[i] << std::endl;
                return;
            }
        }
    }

    void printCountries(Country* countries, int size) {
        for (int i = 0; i < size; ++i) {
            std::cout << countries[i] << std::endl;
        }
    }

    void saveToFile(Country* countries, int size, const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < size; ++i) {
                file << countries[i] << std::endl;
            }
            file.close();
        }
    }

    void loadFromFile(Country*& countries, int& size, int& capacity, const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            delete[] countries;
            size = 0;
            capacity = 10;
            countries = new Country[capacity];
            Country country;
            while (file >> country) {
                if (size == capacity) {
                    capacity *= 2;
                    Country* newCountries = new Country[capacity];
                    for (int i = 0; i < size; ++i) {
                        newCountries[i] = countries[i];
                    }
                    delete[] countries;
                    countries = newCountries;
                }
                countries[size++] = country;
            }
            file.close();
        }
    }
}