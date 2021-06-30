#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include "Person.h"
#include "Hospital.h"
#include "StableMarriageService.h"

void printHospitalAndPeople(std::vector<Hospital> hospitals) {
    for (Hospital hospital : hospitals)
    {
        if (hospital.people.size())
        {
            std::cout << hospital.id << std::endl;
            for (Person person : hospital.people)
            {
                std::cout << person.id << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    std::vector<Hospital> hospitals = Hospital::getHospitalVector();
    StableMarriageService::addPeopleToClosestHospital(hospitals);
    printHospitalAndPeople(hospitals);
    return 0;
}
