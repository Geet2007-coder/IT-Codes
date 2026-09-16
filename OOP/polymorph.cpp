#include <iostream>
using namespace std; 

class Animal {
public:
    void sound() {
        cout << "Animal makes a generic sound\n";
    }
};

class Dog : public Animal {
public:
    void sound()  {
        cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void sound() {
        cout << "Cat meows\n";
    }
};

void make_sound(Animal* animal) {
    animal->sound();
}

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    make_sound(a1);
    make_sound(a2);

    return 0;
}
