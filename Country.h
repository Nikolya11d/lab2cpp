#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <string>

class Country {
private:
    int id;
    std::string name;
    std::string capital;
    int population;
    double area;

public:
    Country(int id = 0, const std::string& name = "", const std::string& capital = "", int population = 0, double area = 0.0);
    friend std::ostream& operator<<(std::ostream& os, const Country& country);
    friend std::istream& operator>>(std::istream& is, Country& country);
    int getId() const;
    void setId(int id);
    std::string getName() const;
    void setName(const std::string& name);
    std::string getCapital() const;
    void setCapital(const std::string& capital);
    int getPopulation() const;
    void setPopulation(int population);
    double getArea() const;
    void setArea(double area);
};

#endif // COUNTRY_H
