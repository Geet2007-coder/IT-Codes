#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    int admno;
    char sname[20];
    float math, science, total;
    float ctotal(float m, float s)
    {
        math = m;
        science = s;
        total = math + science;
        return total;
    }

public:

    void takedata()
    {
        cout << "Enter the marks of Maths and Science" << endl;
        cin >> math >> science;
    }

    void show()
    {
        cout << "Maths: " << math << endl;
        cout << "Science: " << science << endl;
        cout << "Total: " << ctotal(math, science) << endl;
    }
};

int main()
{
    Student s1;
    s1.ctotal();
    s1.show();
    return 0;
}
