// Operations on Complex Numbers
#include <iostream>
using namespace std;

class Complex
{
private:
    float real, imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    }

    Complex(float r, float i)
    {
        real = r;
        imag = i;
    }

    Complex(const Complex &c)
    {
        real = c.real;
        imag = c.imag;
    }

    friend Complex add(Complex c1, Complex c2);
    friend Complex subtract(Complex c1, Complex c2);
    friend Complex multiply(Complex c1, Complex c2);
    friend Complex divide(Complex c1, Complex c2);

    void display()
    {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

Complex add(Complex c1, Complex c2)
{
    return Complex(c1.real + c2.real,
                   c1.imag + c2.imag);
}

Complex subtract(Complex c1, Complex c2)
{
    return Complex(c1.real - c2.real,
                   c1.imag - c2.imag);
}

Complex multiply(Complex c1, Complex c2)
{
    return Complex(
        c1.real * c2.real - c1.imag * c2.imag,
        c1.real * c2.imag + c1.imag * c2.real
    );
}

Complex divide(Complex c1, Complex c2)
{
    float denominator = c2.real * c2.real +
                        c2.imag * c2.imag;

    return Complex(
        (c1.real * c2.real + c1.imag * c2.imag) / denominator,
        (c1.imag * c2.real - c1.real * c2.imag) / denominator
    );
}

int main()
{
    float r1, i1, r2, i2;

    cout << "Enter real and imaginary parts of first complex number: ";
    cin >> r1 >> i1;

    cout << "Enter real and imaginary parts of second complex number: ";
    cin >> r2 >> i2;

    Complex c1(r1, i1);
    Complex c2(r2, i2);

    Complex c0;

    Complex c3(c1);

    cout << "\nFirst complex number: ";
    c1.display();

    cout << "Second complex number: ";
    c2.display();

    cout << "Default complex number: ";
    c0.display();

    cout << "Copied complex number: ";: 8 + 34i
Division: 1.6 + 0.7i
    c3.display();

    Complex sum = add(c1, c2);
    Complex diff = subtract(c1, c2);
    Complex product = multiply(c1, c2);
    Complex quotient = divide(c1, c2);

    cout << "\nAddition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    cout << "Multiplication: ";
    product.display();

    cout << "Division: ";
    quotient.display();

    return 0;
}
