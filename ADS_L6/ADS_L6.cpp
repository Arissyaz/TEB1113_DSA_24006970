/*
ID : 24006970
Name: Arissya Zahiera Binti Zulazman
Group: G1
Queue
*/
#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;

public:
    Queue() {
        front = nullptr;
    }

    void Enqueue(string val) {
        Node* newNode = new Node(val);
        if (front == nullptr) {
            front = newNode;
        }
        else {
            Node* temp = front;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void Peek() {
        Node* temp = front;
        cout << "Queue: ";
        if (temp == nullptr) {
            cout << "Queue is Empty" << endl;
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void Dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        else {
            Node* toDelete = front;
            front = front->next;
            delete toDelete;
            cout << "Deleted successfully" << endl;
            return;
        }
    }



};
int main() {
    Queue queue;
    int choice;
    string value;

    do {
        cout << "Queue Menu" << endl;
        cout << "1. Enqueque" << endl;
        cout << "2. Display" << endl;
        cout << "3. Dequeue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            queue.Enqueue(value);
            break;
        case 2:
            queue.Peek();
            break;
        case 3:
            queue.Dequeue();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 4);

    return 0;
}