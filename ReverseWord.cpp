// Q2_ReverseWord.cpp - Reverse a word using a stack (LIFO), no STL
#include <iostream>
using namespace std;

const int MAX = 100;
char stackArr[MAX];     // character stack
int top = -1;           // -1 means the stack is empty

void push(char c) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    stackArr[++top] = c;
}

char pop() {
    if (top == -1) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    return stackArr[top--];
}

int main() {
    char word[MAX];
    cout << "Enter a word: ";
    cin >> word;

    // 1. Push each character from left to right
    for (int i = 0; word[i] != '\0'; i++) {
        push(word[i]);
    }

    // 2. Pop all characters; they come out in reverse order (LIFO)
    char reversed[MAX];
    int idx = 0;
    while (top != -1) {
        reversed[idx++] = pop();
    }
    reversed[idx] = '\0';

    cout << "\nOriginal word: " << word << endl;
    cout << "Reversed word: " << reversed << endl;
    return 0;
}
