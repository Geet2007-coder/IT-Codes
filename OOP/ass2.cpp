#include<iostream>
using namespace std;

class Complex
{
    private:
        float real,imag;

    public:
        Complex()
        {
            real=0;
            imag=0;
        }

        Complex(float r,float i)
        {
            real=r;
            imag=i;
        }

        Complex(const Complex &c)
        {
            real=c.real;
            imag=c.imag;
        }

        friend Complex add(Complex c1,Complex c2);

        void display()
        {
            cout<<real<<"+"<<imag<<"i"<<endl;
        }
        
        
};

Complex add(Complex c1,Complex c2)
{
    Complex temp;
    temp.real=c1.real+c2.real;
    temp.imag=c1.imag+c2.imag;

    return temp;
}

int main()
{
    Complex c1;

    Complex c2(5,3);

    Complex c3(c2);

    Complex c4=add(c2,c3);

    cout<<"default constructor";
    c1.display();

    cout<<"parametrized constructor";
    c2.display();

    cout<<"copy constructor";
    c3.display();

    cout<<"Addition";
    c4.display();

    return 0;
}
