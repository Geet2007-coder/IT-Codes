#include <iostream>
using namespace std;

class Box;

class Spy {
public:
    void showSecret(const Box& b);
};

class Box {
private:
    int secretCode;

public:
    Box() {
        secretCode = 2026;
    }

    friend class Spy;
};

void Spy::showSecret(const Box& b) {
    cout << "The secret code is: " << b.secretCode << endl;
}

int main() {
    Box myBox;
    Spy mySpy;
    
    mySpy.showSecret(myBox); 
    
    return 0;
}
