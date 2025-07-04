#include "windGauge.h"
#include <iostream>
#include <deque>

void WindGauge::currentWindSpeed(int speed) {
    if (windspeeds.size() >= period) {
        windspeeds.pop_back();
    }
    windspeeds.push_front(speed);
}

int WindGauge::highest() const {
    int x = INT_MIN;
    for (int val : windspeeds) {
        if (x < val) {
            x = val;
        }
    }
    return x;
}

int WindGauge::lowest() const {
    int x = INT_MAX;
    for (int val : windspeeds) {
        if (x > val) {
            x = val;
        }
    }
    return x;
}

int WindGauge::average() const {
    if (windspeeds.empty()) return 0;
    int sum = 0;
    for (int val : windspeeds) {
        sum += val;
    }
    return sum / windspeeds.size();
}