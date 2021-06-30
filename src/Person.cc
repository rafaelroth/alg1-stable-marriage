#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <string>
#include "Person.h"
#include "Coordinate.h"

 Person::Person(int personId, int personAge, int localeX, int localeY) {
     id = personId;
     age = personAge;
     coordinate.setCoordinates(localeX, localeY);
 }