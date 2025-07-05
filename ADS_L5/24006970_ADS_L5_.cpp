/*
Name: Arissya Zahiera Binti Zulazman
Group: G1
Topic: Stack
*/
#include <iostream>
#include <string>
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

class Stack {
private:
    Node* head;
    Node* tail;
public:
    Stack() {
        head = nullptr;
    }

    void Push(string val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void Peek() {
        if (tail = nullptr) {
            cout << "Stack underflow";
        }
        Node* temp = head;
        cout << "Last Element of the stack: " << temp->data << endl;
    }

    void Pop() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

int main() {
    Stack stack;
    int choice;
    string value;

    do {
        cout << "Stack Menu" << endl;
        cout << "1. Push node" << endl;
        cout << "2. Peek Stack" << endl;
        cout << "3. Pop Stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            stack.Push(value);
            break;
        case 2:
            stack.Peek();
            break;
        case 3:
            cout << "Deleting ";
            stack.Peek();
            stack.Pop();
            cout << "Deleted" << endl;
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