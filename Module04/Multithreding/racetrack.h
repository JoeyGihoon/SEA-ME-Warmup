#ifndef RACETRACK_H
#define RACETRACK_H

class RaceTrack
{
private:
    int trackSize;
    int finishLine;

public:
    RaceTrack(int fin = 100); // 생성자 (기본 길이 100)

    int getTrackSize();
    int getFinishLine();

    void setTrackSize(int trk);
    void setFinishLine(int fin);
};

#endif // RACETRACK_H
