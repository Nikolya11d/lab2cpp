#include "Country.h"

Country::Country(int id, const std::string& name, const std::string& capital, int population, double area)
    : id(id), name(name), capital(capital), population(population), area(area) {}

std::ostream& operator<<(std::ostream& os, const Country& country) {
    os << country.id << " " << country.name << " " << country.capital << " " << country.population << " " << country.area;
    return os;
}

std::istream& operator>>(std::istream& is, Country& country) {
    is >> country.id >> country.name >> country.capital >> country.population >> country.area;
    return is;
}

int Country::getId() const {
    return id;
}

void Country::setId(int id) {
    this->id = id;
}

std::string Country::getName() const {
    return name;
}

void Country::setName(const std::string& name) {
    this->name = name;
}

std::string Country::getCapital() const {
    return capital;
}

void Country::setCapital(const std::string& capital) {
    this->capital = capital;
}

int Country::getPopulation() const {
    return population;
}

void Country::setPopulation(int population) {
    this->population = population;
}

double Country::getArea() const {
    return area;
}

void Country::setArea(double area) {
    this->area = area;
}