#include <iostream>
using namespace std;

// 1. Factorial of n: n! = n * (n-1)!
int factorial(int n) {
    if(n <= 1) return 1; // base case
    return n * factorial(n-1);
}

// 2. Fibonacci series: F(n) = F(n-1) + F(n-2)
int fibonacci(int n) {
    if(n == 0) return 0; // base case
    if(n == 1) return 1; // base case
    return fibonacci(n-1) + fibonacci(n-2);
}

// 3. Sum of first n natural numbers
int sumNatural(int n) {
    if(n == 0) return 0; // base case
    return n + sumNatural(n-1);
}

// 4. Power of a number: x^n
int power(int x, int n) {
    if(n == 0) return 1; // base case
    return x * power(x, n-1);
}

// 5. Reverse a string recursively
void reverseString(string &s, int start, int end) {
    if(start >= end) return; // base case
    swap(s[start], s[end]);
    reverseString(s, start+1, end-1);
}

// 6. Greatest Common Divisor (GCD) using Euclidean algorithm
int gcd(int a, int b) {
    if(b == 0) return a; // base case
    return gcd(b, a % b);
}

// 7. Count digits of a number
int countDigits(int n) {
    if(n == 0) return 0; // base case
    return 1 + countDigits(n/10);
}

// 8. Check if array is sorted
bool isSorted(int arr[], int n) {
    if(n == 1 || n == 0) return true; // base case
    return (arr[0] <= arr[1] && isSorted(arr+1, n-1));
}

// 9. Print numbers from n to 1
void printDescending(int n) {
    if(n == 0) return; // base case
    cout << n << " ";
    printDescending(n-1);
}

// 10. Print numbers from 1 to n
void printAscending(int n) {
    if(n == 0) return; // base case
    printAscending(n-1);
    cout << n << " ";
}
