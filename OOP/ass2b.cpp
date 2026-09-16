#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:

    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    Time operator + (const Time& t) const {
        Time temp;
        
        temp.seconds = seconds + t.seconds;
        int minuteCarry = temp.seconds / 60;
        temp.seconds %= 60;

        temp.minutes = minutes + t.minutes + minuteCarry;
        int hourCarry = temp.minutes / 60;
        temp.minutes %= 60;

        temp.hours = hours + t.hours + hourCarry;

        return temp;
    }


    void display() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main() {

    Time t1(5, 45, 40);
    Time t2(2, 20, 35);
    Time t3;


    t3 = t1 + t2;


    cout << "Time 1: ";
    t1.display();

    cout << "Time 2: ";
    t2.display();

    cout << "Result (t1 + t2): ";
    t3.display();

    return 0;
}
