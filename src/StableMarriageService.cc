#include <iostream>
#include <vector>
#include <queue>
#include "Person.h"
#include "Hospital.h"
#include "StableMarriageService.h"
#include "UtilsService.h"

struct StableMarriageService::CompareAgeAndId
{
    float operator()(Person p1, Person p2)
    {
        return p1.age == p2.age ? p1.id > p2.id : p1.age < p2.age;
    };
};

void StableMarriageService::addPersonToClosestHospital(Person person, std::vector<Hospital> &hospitals)
{
    auto compare = [person](Hospital *a, Hospital *b) -> bool
    {
        return a->coordinate.getDistance(person.coordinate) > b->coordinate.getDistance(person.coordinate);
    };
    std::priority_queue<Hospital *, std::vector<Hospital *>, decltype(compare)> hospitalsByDistance(compare);
    bool allHospitalsFilled = true;
    for (Hospital &hospital : hospitals)
    {
        if (!hospital.isFilled)
        {
            allHospitalsFilled = false;
            hospitalsByDistance.push(&hospital);
        }
    }
    if (!allHospitalsFilled)
        hospitalsByDistance.top()->addPerson(person);
}

std::priority_queue<Person, std::vector<Person>, StableMarriageService::CompareAgeAndId> StableMarriageService::getPeoplePriorityQueue()
{
    std::string line;
    std::getline(std::cin, line);
    int numberOfPeople = std::stoi(line);
    std::priority_queue<Person, std::vector<Person>, CompareAgeAndId> people;
    std::vector<std::string> personInfo;
    for (int i = 0; i < numberOfPeople; i++)
    {
        std::getline(std::cin, line);
        personInfo = UtilsService::getLineInfo(line);
        people.push(Person(i, std::stoi(personInfo[0]), std::stoi(personInfo[1]), std::stoi(personInfo[2])));
    }

    return people;
}

void StableMarriageService::addPeopleToClosestHospital(std::vector<Hospital> &hospitals)
{
    std::priority_queue<Person, std::vector<Person>, CompareAgeAndId> people = getPeoplePriorityQueue();
    while (!people.empty())
    {
        addPersonToClosestHospital(people.top(), hospitals);
        people.pop();
    }
}