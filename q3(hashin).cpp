#include <iostream>
using namespace std;

// Structure to store hash information
struct HashInfo {
    int hash;
    int frequency;
    int* studentIDs;      // Dynamic array to store student IDs
    int studentCount;     // Number of students stored
    int capacity;         // Capacity of array
    
    HashInfo() {
        hash = 0;
        frequency = 0;
        studentIDs = NULL;
        studentCount = 0;
        capacity = 0;
    }
};

// Structure for suspicious records
struct Record {
    int hash;
    int f;  // frequency
    int d;  // distinct student count
};

// Check if student already exists in the array
bool studentExists(int* arr, int size, int studentID) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == studentID) {
            return true;
        }
    }
    return false;
}

// Add student to the array (if not already present)
void addStudent(HashInfo& info, int studentID) {
    // Check if student already exists
    if (studentExists(info.studentIDs, info.studentCount, studentID)) {
        return;  // Don't add duplicate
    }
    
    // Need to expand array
    if (info.studentCount >= info.capacity) {
        int newCapacity = (info.capacity == 0) ? 2 : info.capacity * 2;
        int* newArr = new int[newCapacity];
        
        // Copy old data
        for (int i = 0; i < info.studentCount; i++) {
            newArr[i] = info.studentIDs[i];
        }
        
        // Delete old array
        if (info.studentIDs != NULL) {
            delete[] info.studentIDs;
        }
        
        info.studentIDs = newArr;
        info.capacity = newCapacity;
    }
    
    // Add new student
    info.studentIDs[info.studentCount] = studentID;
    info.studentCount++;
}

// Simple hash table using array (assuming hash values are reasonable)
class HashTable {
public:
    HashInfo* table;
    int size;
    int capacity;
    
    HashTable(int cap) {
        capacity = cap;
        size = 0;
        table = new HashInfo[capacity];
    }
    
    ~HashTable() {
        for (int i = 0; i < size; i++) {
            if (table[i].studentIDs != NULL) {
                delete[] table[i].studentIDs;
            }
        }
        delete[] table;
    }
    
    // Find index of hash in table (-1 if not found)
    int findHash(int hash) {
        for (int i = 0; i < size; i++) {
            if (table[i].hash == hash) {
                return i;
            }
        }
        return -1;
    }
    
    // Insert or update hash
    void insert(int hash, int studentID) {
        int index = findHash(hash);
        
        if (index == -1) {
            // New hash
            if (size >= capacity) {
                // Expand table (not shown for simplicity)
                return;
            }
            table[size].hash = hash;
            table[size].frequency = 1;
            table[size].studentIDs = NULL;
            table[size].studentCount = 0;
            table[size].capacity = 0;
            addStudent(table[size], studentID);
            size++;
        } else {
            // Existing hash
            table[index].frequency++;
            addStudent(table[index], studentID);
        }
    }
    
    // Get all suspicious hashes
    int getSuspicious(Record*& records, int K) {
        int count = 0;
        
        // Count suspicious hashes first
        for (int i = 0; i < size; i++) {
            int f = table[i].frequency;
            int d = table[i].studentCount;
            
            if (f >= K && d >= 2) {
                count++;
            }
        }
        
        if (count == 0) {
            return 0;
        }
        
        // Allocate array for suspicious records
        records = new Record[count];
        int idx = 0;
        
        // Fill suspicious records
        for (int i = 0; i < size; i++) {
            int f = table[i].frequency;
            int d = table[i].studentCount;
            
            if (f >= K && d >= 2) {
                records[idx].hash = table[i].hash;
                records[idx].f = f;
                records[idx].d = d;
                idx++;
            }
        }
        
        return count;
    }
};

// Merge function for merge sort
void merge(Record arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temp arrays
    Record* L = new Record[n1];
    Record* R = new Record[n2];
    
    // Copy data
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    // Merge back
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        bool takeLeft = false;
        
        // Primary: Descending order of f (higher frequency first)
        if (L[i].f != R[j].f) {
            takeLeft = (L[i].f > R[j].f);
        }
        // Secondary: Descending order of d (more students first)
        else if (L[i].d != R[j].d) {
            takeLeft = (L[i].d > R[j].d);
        }
        // Tertiary: Ascending order of hash (smaller hash first)
        else {
            takeLeft = (L[i].hash < R[j].hash);
        }
        
        if (takeLeft) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    delete[] L;
    delete[] R;
}

// Merge sort
void mergeSort(Record arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    // Input
    int n, K;
    cout << "Enter number of submissions: ";
    cin >> n;
    
    cout << "Enter plagiarism threshold K: ";
    cin >> K;
    
    int* H = new int[n];
    int* ID = new int[n];
    
    cout << "Enter hash values:\n";
    for (int i = 0; i < n; i++) {
        cin >> H[i];
    }
    
    cout << "Enter student IDs:\n";
    for (int i = 0; i < n; i++) {
        cin >> ID[i];
    }
    
    // Build hash table
    HashTable table(n);
    
    for (int i = 0; i < n; i++) {
        table.insert(H[i], ID[i]);
    }
    
    // Get suspicious hashes
    Record* suspicious = NULL;
    int count = table.getSuspicious(suspicious, K);
    
    if (count == 0) {
        cout << "NO SUSPICIOUS HASHES" << endl;
    } else {
        // Sort using merge sort
        mergeSort(suspicious, 0, count - 1);
        
        // Output
        for (int i = 0; i < count; i++) {
            cout << suspicious[i].hash << " " 
                 << suspicious[i].f << " " 
                 << suspicious[i].d << endl;
        }
        
        delete[] suspicious;
    }
    
    // Cleanup
    delete[] H;
    delete[] ID;
    
    return 0;
}