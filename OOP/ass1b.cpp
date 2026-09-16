#include <iostream>
using namespace std;

class Batsman
{
private:
    int bcode;
    char bname[20];
    int innings, notout, runs;
    float batavg;

    void calcavg()
    {
        batavg = (float)runs/(innings - notout);
    }
public:
    void readdata()
    {
        cout << "Enter the code, name, innings, notouts and runs of the batsman..." << endl;
        cin >> bcode >> bname >> innings >> notout >> runs;
        calcavg();
    }
    void displaydata()
    {
        cout << "Name: " << bname << endl;
        cout << "Code: " << bcode << endl;
        cout << "Innings Played: " << innings << endl;
        cout << "Total Runs Scored: " << runs << endl;
        cout << "Batting Average: " << batavg << endl;
    }
};


int main()
{
    Batsman b1;
    b1.readdata();
    b1.displaydata();
    return 0;
}
