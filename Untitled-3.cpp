#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int frontIdx = 0;   
int rear = -1;      
bool isEmpty() { return rear < frontIdx; }
bool isFull()  { return rear == MAX - 1; }


void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Tidak bisa menambah " << value << "." << endl;
        return;
    }
    queueArr[++rear] = value;
    cout << value << " inserted successfully." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue kosong." << endl;
        return;
    }
    cout << queueArr[frontIdx] << " removed successfully." << endl;
    frontIdx++;
    if (isEmpty()) {
        frontIdx = 0;
        rear = -1;
    }
}
void front() {
    if (isEmpty()) {
        cout << "Queue kosong." << endl;
        return;
    }
    cout << "Front element: " << queueArr[frontIdx] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Queue: (kosong)" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = frontIdx; i <= rear; i++) cout << queueArr[i] << " ";
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue" << endl;
        cout << "3. Front  4. Display  5. Exit" << endl;
        display();
        cout << "Choose operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2: dequeue(); break;
            case 3: front(); break;
            case 4: display(); break;
            case 5: cout << "Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 5);
    return 0;
}