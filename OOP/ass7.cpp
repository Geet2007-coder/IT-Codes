#include<iostream>
using namespace std;
class Shape
{
	protected:
		float x,y;
	public:
		void getData(float a,float b=0)
		{
			x=a;
			y=b;
		}
};

class Triangle:public Shape
{
	public:
		void display_area()
		{
			cout<<"Area of triangle="<<0.5*x*y<<endl;
		}
};
class Circle:public Shape
{
	public:
		void display_area()
		{
			cout<<"Area of circle="<<3.14159*x*x<<endl;
		}
};
int main()
{
	Triangle t;
	Circle c;
	t.getData(10,20);
	t.display_area();
	
	c.getData(7);
	c.display_area();
	return 0;
}
