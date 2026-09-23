#include <iostream>
using namespace std;

class Student
{
protected:
    string name;
    int roll_no;
};

class Test : public Student
{
protected:
    int marks;

public:
    void read()
    {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Roll Number: ";
        cin >> roll_no;

        cout << "Enter Total Marks: ";
        cin >> marks;
    }
};

class Sport
{
protected:
    int score;

public:
    void read()
    {
        cout << "Enter Student Score: ";
        cin >> score;
    }
};

class Result : public Test, public Sport
{
private:
    int total_marks;

public:
    void calculate()
    {
        total_marks = marks + score;
    }

    void display_total()
    {
        cout << "Name: " << name << "\n";
        cout << "Roll No: " << roll_no << "\n";
        cout << "Total: " << total_marks << "\n";
    }
};

int main()
{
    Result r;
    r.Test::read();
    r.Sport::read();
    r.calculate();
    r.display_total();

    return 0;
}
