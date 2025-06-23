#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *next;
};

// Queue class
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    // Constructor to initialize the queue
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

     // 1. Allocate memory for the new node.
    // 2. Assign value to the data field of the new node.
    // 3. Make the next field of the new node point to NULL.
    // 4. If the queue is empty, execute the following steps:
    // a. Make FRONT point to the new node
    // b. Make REAR  point to the new node
    // d. Exit
    // 5. Make the next field of REAR point to the new node.
    // 6. Make REAR point to the new node.
    // Fungsi insert sesuai algoritma
    void insert()
    {
        int value;
        cout << "Enter value to enqueue: ";
        cin >> value;

        // 1. Allocate memory for the new node.
        Node *newNode = new Node;

        // 2. Assign value to the data field of the new node.
        newNode->data = value;

        // 3. Make the next field of the new node point to NULL.
        newNode->next = NULL;

        // 4. If the queue is empty
        if (isEmpty())
        {
            // a. Make FRONT point to the new node
            front = newNode;

            // b. Make REAR point to the new node
            rear = newNode;
        }
        else
        {
            // 5. Make the next field of REAR point to the new node.
            rear->next = newNode;

            // 6. Make REAR point to the new node.
            rear = newNode;
        }

        cout << "Enqueued " << value << " successfully.\n";
    }

       //1. If the queue is empty: // FRONT = NULL
        // a. Display “Queue empty”
        // b. Exit
    //2. Mark the node marked FRONT as current
    //3. Make FRONT point to the next node in its sequence
    //4. Release the memory for the node marked as current

    // Fungsi delete sesuai algoritma
    void deleteQueue()
    {
        // 1. If the queue is empty
        if (isEmpty())
        {
            // a. Display “Queue empty”
            cout << "Queue is empty, cannot dequeue.\n";
            return;
        }

        // 2. Mark the node marked FRONT as current
        Node *temp = front;

    }

    // Function to display all elements of the queue
    void display()
    {
        if (isEmpty()) // step 1
        { 
            cout << "Queue is empty\n";
            return;
        }

        Node *temp = front;
        cout << "Queue elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == NULL && rear == NULL;
    }
};

int main()
{
    Queue q;
    int choice;

    do
    {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.insert();
            break;
        case 2:
            q.deleteQueue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again\n";
        }
    } while (choice != 4); // sebelumnya salah, harusnya while sampai 4 (Exit)

    return 0;
}