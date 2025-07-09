#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Car{
private:
    int position;
    int speed;
    int direction;

public:
    Car(int pos, int sp, int dir) : position(pos), speed(sp), direction(dir){}

    int getPosition() {return position;}
    int getSpeed() {return speed;}
    int getDirection() {return direction;};

    void setPosition(int pos) {position = pos;}
    void setSpeed(int sp) {speed = sp;}
    void setDirection(int dir) {direction = dir;}
};

class RaceTrack{
private:
    int trackSize;
    int finishLine;

public:
    RaceTrack(int trk, int fin) : trackSize(trk), finishLine(fin){}

    int getTrackSize() {return trackSize;}
    int getFinishLine() {return finishLine;}

    void setTrackSize(int trk) {trackSize = trk;}
    void setFinishLine(int fin) {finishLine = fin;}


}