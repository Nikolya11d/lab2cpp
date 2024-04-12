#ifndef COUNTRYDATABASE_H
#define COUNTRYDATABASE_H

#include "Country.h"
#include <fstream>

namespace CountryDatabase {
    void addCountry(Country*& countries, int& size, int& capacity);
    void removeCountry(Country*& countries, int& size, int id);
    void editCountry(Country* countries, int size, int id);
    void searchCountry(Country* countries, int size, const std::string& name);
    void printCountries(Country* countries, int size);
    void saveToFile(Country* countries, int size, const std::string& filename);
    void loadFromFile(Country*& countries, int& size, int& capacity, const std::string& filename);
}

#endif // COUNTRYDATABASE_H
