#include<iostream>
#include<string>
using namespace std;

/*define a class student with the following specification 
admission number,student name,marks of 3 subjects and total 
take data from user calculate total and display all the data */
class student
{
    private:
        int admno;
        char sname[20];
        float eng,math,sci;
        float total;

        float ctotal()
        {
            return eng+math+sci;
        }

    public:
        void Take()
        {
            cout<<"Enter Admission number:";
            cin>>admno;

            cout<<"Enter Student Name:";
            cin>>sname;

            cout<<"Enter English Marks:";
            cin>>eng;

            cout<<"Enter Maths Marks:";
            cin>>math;

            cout<<"Enter Science Marks:";
            cin>>sci;

            total=ctotal();
        }

        void Show()
        {
            cout<<"\n student details"<<endl;
            cout<<"Admission Number"<<admno<<endl;
            cout<<"student name"<<sname <<endl;
            cout<<"English"<<eng<<endl;
            cout<<"Maths"<<math <<endl;
            cout<<"Science"<<sci <<endl;
            cout<<"Total"<<total<<endl;
        }
};

int main()
{
    student s;
    s.Take();
    s.Show();

    return 0;
}