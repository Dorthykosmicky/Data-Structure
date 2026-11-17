#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int frontIdx = 0;   
int rear = -1;      
int count = 0;      

bool isEmpty() { return count == 0; }
bool isFull()  { return count == MAX; }

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Tidak bisa menambah " << value << "." << endl;
        return;
    }
    rear = (rear + 1) % MAX;     
    queueArr[rear] = value;
    count++;
    cout << value << " inserted successfully." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue kosong." << endl;
        return;
    }
    cout << queueArr[frontIdx] << " removed successfully." << endl;
    frontIdx = (frontIdx + 1) % MAX;   
    count--;
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
    for (int i = 0; i < count; i++) {
        cout << queueArr[(frontIdx + i) % MAX] << " ";
    }
    cout << endl;
}


void mandatoryTest() {
    cout << "=== MANDATORY TEST ===" << endl;
    enqueue(10); enqueue(20); enqueue(30); enqueue(40); enqueue(50); 
    dequeue(); dequeue();                                            
    enqueue(60); enqueue(70);                                       
    display();                                                       
    cout << "======================" << endl;
}

int main() {
    mandatoryTest();

    int choice, value;
    do {
        cout << "\n===== CIRCULAR QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue" << endl;
        cout << "3. Front  4. Display  5. Exit" << endl;
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
