#include <iostream>
#include <vector>
#include <deque>
#include <climits> // For INT_MIN and INT_MAX (chatgpt)

class WindGauge {
public:
    WindGauge(int period = 12) : period(period) {}

    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;

private:
    int period;
    std::deque<int> windspeeds;
};