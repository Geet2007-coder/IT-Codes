#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
    char str[100];

public:
    
    MyString(const char s[] = "")
    {
        strcpy(str, s);
    }

    
    MyString(const MyString &s)
    {
        strcpy(str, s.str);
    }

    
    MyString operator+(MyString s)
    {
        MyString temp;
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    
    void display()
    {
        cout << str << endl;
    }
};

int main()
{
    char a[100], b[100];

    cout << "Enter first string: ";
    cin>>a;

    cout << "Enter second string: ";
    cin>>b;

    MyString s1(a);
    MyString s2(b);

    cout << "\n First String: ";
    s1.display();

    cout << "Second String: ";
    s2.display();

    
    MyString s3(s1);

    cout << "\nCopied String: ";
    s3.display();

    
    MyString s4 = s1 + s2;

    cout << "Concatenated String: ";
    s4.display();

    return 0;
}
