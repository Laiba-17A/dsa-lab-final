#include <iostream>
#include <string>
#include <queue>
#include <cctype>
using namespace std;

// -------------------- Custom Stack --------------------
class Stack {
public:
    int *arr;
    int topIndex;
    int capacity;

    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex == capacity - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++topIndex] = x;
    }

    int pop() {
        if (topIndex == -1) {
            cout << "Stack underflow\n";
            return -1;
        }
        return arr[topIndex--];
    }

    int top() {
        if (topIndex == -1) return -1;
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

// -------------------- 1. Reverse a String --------------------
string reverseString(string str) {
    Stack s(str.size());
    for (char c : str) s.push(c);
    string rev = "";
    while (!s.isEmpty()) rev += s.pop();
    return rev;
}

// -------------------- 2. Balanced Parentheses --------------------
bool isBalanced(string expr) {
    Stack s(expr.size());
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') s.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (s.isEmpty()) return false;
            char top = s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) return false;
        }
    }
    return s.isEmpty();
}

// -------------------- 3. Evaluate Postfix Expression --------------------
int evaluatePostfix(string exp) {
    Stack s(exp.size());
    for (char c : exp) {
        if (isdigit(c)) s.push(c - '0');
        else {
            int b = s.pop();
            int a = s.pop();
            if (c == '+') s.push(a + b);
            else if (c == '-') s.push(a - b);
            else if (c == '*') s.push(a * b);
            else if (c == '/') s.push(a / b);
        }
    }
    return s.pop();
}

// -------------------- 4. Next Greater Element --------------------
void nextGreaterElement(int arr[], int n) {
    Stack s(n);
    int nge[n];
    for (int i = n-1; i >=0; i--) {
        while (!s.isEmpty() && s.top() <= arr[i]) s.pop();
        nge[i] = s.isEmpty() ? -1 : s.top();
        s.push(arr[i]);
    }
    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++) cout << nge[i] << " ";
    cout << endl;
}

// -------------------- 5. Sort Stack --------------------
void sortedInsert(Stack &s, int x) {
    if (s.isEmpty() || x > s.top()) { s.push(x); return; }
    int temp = s.pop();
    sortedInsert(s, x);
    s.push(temp);
}

void sortStack(Stack &s) {
    if (!s.isEmpty()) {
        int x = s.pop();
        sortStack(s);
        sortedInsert(s, x);
    }
}

// -------------------- 6. Stack Using 2 Queues --------------------
class StackUsingQueues {
public:
    queue<int> q1, q2;

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) { q2.push(q1.front()); q1.pop(); }
        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) return -1;
        int val = q1.front(); q1.pop();
        return val;
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    bool isEmpty() { return q1.empty(); }
};

// -------------------- 7. Infix to Postfix Conversion --------------------
string infixToPostfix(string exp) {
    Stack st(exp.size());
    string res = "";
    auto prec = [](char c) -> int {
        if (c == '^') return 3;
        else if (c == '*' || c == '/') return 2;
        else if (c == '+' || c == '-') return 1;
        return -1;
    };

    for (char c : exp) {
        if (isalnum(c)) res += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.isEmpty() && st.top() != '(') res += st.pop();
            if (!st.isEmpty()) st.pop();
        } else {
            while (!st.isEmpty() && prec(c) <= prec(st.top())) res += st.pop();
            st.push(c);
        }
    }
    while (!st.isEmpty()) res += st.pop();
    return res;
}

