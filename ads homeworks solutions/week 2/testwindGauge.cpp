#include "windGauge.h"
#include <iostream>
#include <deque>

int main(){

    WindGauge gauge(12);
    gauge.currentWindSpeed(15);
    gauge.currentWindSpeed(16);
    gauge.currentWindSpeed(12);
    gauge.currentWindSpeed(15);
    gauge.currentWindSpeed(15);

    std::cout << "The highest wind speed is: " << gauge.highest() << std::endl;
    std::cout << "The lowest wind speed is: " << gauge.lowest() << std::endl;
    std::cout << "The average wind speed is: " << gauge.average() << std::endl;

    gauge.currentWindSpeed(16);
    gauge.currentWindSpeed(17);
    gauge.currentWindSpeed(16);
    gauge.currentWindSpeed(16);
    gauge.currentWindSpeed(20);
    gauge.currentWindSpeed(17);
    gauge.currentWindSpeed(16);
    gauge.currentWindSpeed(15);
    gauge.currentWindSpeed(16);
    gauge.currentWindSpeed(20);

    std::cout << "The highest wind speed is: " << gauge.highest() << std::endl;
    std::cout << "The lowest wind speed is: " << gauge.lowest() << std::endl;
    std::cout << "The average wind speed is: " << gauge.average() << std::endl;

    return 0;
}