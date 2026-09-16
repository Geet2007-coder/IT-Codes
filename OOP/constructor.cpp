#include <iostream>
using namespace std;

class Student {
    int rollNo;
    string name;

public:
    // Constructor
    Student() {
        rollNo = 1;
        name = "Rahul";
    }

    void display() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

int main() {
    Student s;   // Constructor is called automatically
    s.display();

    return 0;
}
