#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inches;

public:
   
    Distance()
    {
        feet = 0;
        inches = 0;
        cout << "Default constructor called" << endl;
    }

   
    Distance(int f, int i)
    {
        feet = f + i / 12; //if i is greater than 12,then there will be a real value and will be added to foot,if not a real value,then nothing extra will be added
        inches = i % 12;//if value greater than 12,the excess will be cut off,that way we get only value below 12

        cout << "Parameterized constructor called" << endl;
    }

    // Copy constructor
    Distance(Distance &d)
    {
        feet = d.feet;
        inches = d.inches;

        cout << "Copy constructor called" << endl;
    }

   
    Distance add(Distance d)
    {
        Distance temp;

        temp.feet = feet + d.feet;
        temp.inches = inches + d.inches;

        // Convert inches into feet if inches >= 12
        if (temp.inches >= 12)
        {
            temp.feet += temp.inches / 12;
            temp.inches %= 12;
        }

        return temp;
    }

    void display()
    {
        cout << feet << "' " << inches << "\"" << endl;
    }
};

int main()
{
    int feet1, inches1;
   

   
    cout << "Enter Distance 1:" << endl;
    cout << "Feet: ";
    cin >> feet1;
    cout << "Inches: ";
    cin >> inches1;

    cout << endl;    
    Distance d1(feet1, inches1);
    
    cout << endl;

    cout << "Distance 1: ";
    d1.display();

    
    Distance d2(d1);

    cout << "Distance 2: ";
    d2.display();

    cout << endl;

   
    cout << "Adding Distance 1 and Distance 2..." << endl;

    Distance sum = d1.add(d2);

    cout << "The sum is: ";
    sum.display();

    return 0;
}
