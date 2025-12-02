#include <iostream>
using namespace std;

class hashtable {
public:
    int size;
    int *arr;

    hashtable(int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = -1;  // empty slot
    }

    int hash1(int key) {
        return key % size;
    }

    int hash2(int key) {
        return 7 - (key % 7);  // second hash must NOT be zero
    }

    // ---------------- INSERT ----------------
    void insert(int key) {
        int idx = hash1(key);
        int step = hash2(key);

        for (int i = 0; i < size; i++) {
            int newidx = (idx + i * step) % size;

            if (arr[newidx] == -1 || arr[newidx] == -2) {
                arr[newidx] = key;
                return;
            }
        }
        cout << "Table full " << key << endl;
    }

    bool search(int key) {
        int idx = hash1(key);
        int step = hash2(key);

        for (int i = 0; i < size; i++) {
            int newidx = (idx + i * step) % size;

            if (arr[newidx] == key) {
                cout << "Value found: " << key << endl;
                return true;
            }

            if (arr[newidx] == -1)
                break;
        }
        cout << "Value not found: " << key << endl;
        return false;
    }

    bool remove(int key) {
        int idx = hash1(key);
        int step = hash2(key);

        for (int i = 0; i < size; i++) {
            int newidx = (idx + i * step) % size;

            if (arr[newidx] == key) {
                arr[newidx] = -2;
                cout << "Value deleted: " << key << endl;
                return true;
            }

            if (arr[newidx] == -1)
                break;
        }
        cout << "Value to be deleted not found: " << key << endl;
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << endl;
    }
};

int main() {
    hashtable t(10);

    t.insert(10);
    t.insert(20);
    t.insert(33);
    t.insert(45);
    t.insert(50);

    t.display();

    t.search(33);
    t.remove(33);
    t.search(33);
    t.display();

    return 0;
}
