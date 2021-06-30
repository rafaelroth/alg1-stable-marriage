#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include "Person.h"
#include "Hospital.h"
#include "Coordinate.h"
#include "UtilsService.h"

std::vector<Hospital> Hospital::getHospitalVector()
{
    std::string line;
    std::getline(std::cin, line);
    int numberOfHospitals = std::stoi(line);
    std::vector<Hospital> hospitals;
    std::vector<std::string> hospitalInfo;
    for (int i = 0; i < numberOfHospitals; i++)
    {
        std::getline(std::cin, line);
        hospitalInfo = UtilsService::getLineInfo(line);
        hospitals.push_back(Hospital(i, std::stoi(hospitalInfo[0]), std::stoi(hospitalInfo[1]), std::stoi(hospitalInfo[2])));
    }
    return hospitals;
}

 Hospital::Hospital(int hospitalId, int hospitalCapacity, int localeX, int localeY) {
     id = hospitalId;
     capacity = hospitalCapacity;
     coordinate.setCoordinates(localeX, localeY);
 }

 void Hospital::checkIfIsFilled(){
     if(people.size() == capacity )
        isFilled = true;
 }

 void Hospital::addPerson(Person person) {
     people.push_back(person);
     checkIfIsFilled();
 }