#ifndef PESSOA_H
#define PESSOA_H
#include <vector>
#include <queue>
#include "Coordinate.h"

class Person {
    public:
        Coordinate coordinate;
        int id, age;
        Person(int id, int age, int x, int y);
};

#endif