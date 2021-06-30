#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
    private:
        int x, y;
    public:
        Coordinate();
        Coordinate(int x, int y);
        void setCoordinates(int x, int y);
        float getDistance(Coordinate points);
};

#endif