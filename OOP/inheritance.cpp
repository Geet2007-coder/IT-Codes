#include<iostream>
using namespace std;

class Student
{
    protected: 
        string name;
        int roll_no;

    public:
        void getStud()
        {
            cout << "Name: ";
            cin >> name;
            cout << "Roll no: ";
            cin >> roll_no;
        }
        
};

class Test :virtual public Student
{
    protected:
        float marks;

    public:
        void read(int m)
        {
            marks = m;
        };
};

class Sport :virtual public Student
{
    protected:
        int score;

    public: 
        void read(int s)
        {
            score = s;
        };
};

class Result : public Test, public Sport
{
    private: 
        float t;

    public:
       int total()
       {
            t = score + marks;
            return t;
       }
       void display()
       {
            cout << "Name: " << name << endl;
            cout << "Roll no: " << roll_no << endl;
            cout << "Total: " << total() << endl;
            cout << "Marks: " << marks << endl;
            cout << "Score: " << score << endl;
       }
};

int main(int argc, char const *argv[])
{
    Result r;
    r.getStud();
    r.Test::read(85);
    r.Sport::read(100);
    r.display();
    return 0;
}

