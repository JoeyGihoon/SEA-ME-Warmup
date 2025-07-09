#include "racetrack.h"

RaceTrack::RaceTrack(int fin) : finishLine(fin) {}

int RaceTrack::getTrackSize() {return trackSize;}
int RaceTrack::getFinishLine() {return finishLine;}

void RaceTrack::setTrackSize(int trk) {trackSize = trk;}
void RaceTrack::setFinishLine(int fin) {finishLine = fin;}
