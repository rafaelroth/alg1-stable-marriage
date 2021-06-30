#include <iostream>
#include<math.h>
#include "Coordinate.h"

Coordinate::Coordinate(){
    x = -1;
    y = -1;
}

Coordinate::Coordinate(int pointX, int pointY){
    x = pointX;
    y = pointY;
}

void Coordinate::setCoordinates(int pointX, int pointY){
    x = pointX;
    y = pointY;
}

float Coordinate::getDistance(Coordinate points){
    int newX = x - points.x;
    int newY = y - points.y;
    float dist = sqrt(pow(newX, 2) + pow(newY, 2));
    return dist;
}