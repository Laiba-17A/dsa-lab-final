#include <iostream>
using namespace std;

class Demo {
    int* data;   // dynamic memory

public:
    // Constructor
    Demo(int value) {
        data = new int(value);
    }

    // 1️⃣ Destructor
    ~Demo() {
        delete data;
    }

    // 2️⃣ Copy Constructor
    Demo(const Demo& obj) {
        data = new int(*obj.data);
    }

    // 3️⃣ Copy Assignment Operator
    Demo& operator=(const Demo& obj) {
        if (this != &obj) {
            delete data;
            data = new int(*obj.data);
        }
        return *this;
    }

    void show() {
        cout << *data << endl;
    }
};

int main() {
    Demo a(10);
    Demo b = a;      // copy constructor
    Demo c(5);
    c = a;           // copy assignment

    a.show();
    b.show();
    c.show();

    return 0;
}
