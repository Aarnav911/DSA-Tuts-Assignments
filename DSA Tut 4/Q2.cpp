#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue
{
  int arr[MAX];
  int front, rear;

public:
  CircularQueue()
  {
    front = -1;
    rear = -1;
  }

  bool isEmpty()
  {
    return front == -1;
  }

  bool isFull()
  {
    return (front == 0 && rear == MAX - 1) || (rear + 1 == front);
  }

  void enqueue(int x)
  {
    if (isFull())
    {
      cout << "Queue is full\n";
      return;
    }
    if (isEmpty())
      front = rear = 0;
    else
      rear = (rear + 1) % MAX;
    arr[rear] = x;
  }

  void dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue is empty\n";
      return;
    }
    cout << "Dequeued: " << arr[front] << endl;
    if (front == rear)
      front = rear = -1;
    else
      front = (front + 1) % MAX;
  }

  void peek()
  {
    if (isEmpty())
    {
      cout << "Queue is empty\n";
      return;
    }
    cout << "Front: " << arr[front] << endl;
  }

  void display()
  {
    if (isEmpty())
    {
      cout << "Queue is empty\n";
      return;
    }
    int i = front;
    while (true)
    {
      cout << arr[i] << " ";
      if (i == rear)
        break;
      i = (i + 1) % MAX;
    }
    cout << endl;
  }
};

int main()
{
  CircularQueue q;
  int choice, val;
  do
  {
    cout << "\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter value: ";
      cin >> val;
      q.enqueue(val);
      break;
    case 2:
      q.dequeue();
      break;
    case 3:
      q.peek();
      break;
    case 4:
      q.display();
      break;
    case 5:
      break;
    default:
      cout << "Invalid choice\n";
    }
  } while (choice != 5);
  return 0;
}
