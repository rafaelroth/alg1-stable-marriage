#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <iostream>
#include <vector>
#include "Person.h"
#include "Coordinate.h"

class Hospital {
    private:
        void checkIfIsFilled();
        unsigned int capacity;
    public:
        Hospital(int id, int capacity, int x, int y);
        static std::vector<Hospital> getHospitalVector();
        Coordinate coordinate;
        int id;
        std::vector<Person> people;
        void addPerson(Person person);
        bool isFilled = false;
};

#endif