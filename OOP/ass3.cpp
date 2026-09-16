#include<iostream>
using namespace std;

class Complex
{
    private:
        float real,imag;

    public:
        void getData()
        {
            cout<<"Enter real part";
            cin>>real;

            cout<<"Enter imaginary part";
            cin>>imag;
        }

        void display()
        {
            cout<<real<<"+"<<imag<<"i"<<endl;
        }

        //opr overload
        Complex operator+(Complex c)
        {
            Complex temp;

            temp.real=real+c.real;
            temp.imag=imag+c.imag;

            return temp;
        }
};

int main()
{
    Complex c1,c2,c3;

    cout<<"Enter first complex number:"<<endl;
    c1.getData();

    cout<<"\n Enter second complex number:"<<endl;
    c2.getData();

    c3=c1+c2;

    cout<<"\nFirst Complex number:";
    c1.display();

    cout<<"\nSecond Complex number:";
    c2.display();

    cout<<"\nAddition:";
    c3.display();

    return 0;
}
