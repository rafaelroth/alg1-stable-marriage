#ifndef STABLE_MARRIAGE_SERVICE_H
#define STABLE_MARRIAGE_SERVICE_H
#include <iostream>
#include <vector>
#include <queue>
#include "Person.h"
#include "Hospital.h"

class StableMarriageService {
    private: 
        struct CompareAgeAndId;
        static void addPersonToClosestHospital(Person, std::vector<Hospital>&);
        static std::priority_queue<Person, std::vector<Person>, CompareAgeAndId> getPeoplePriorityQueue();
    public:
        static void addPeopleToClosestHospital(std::vector<Hospital>&);
};

#endif