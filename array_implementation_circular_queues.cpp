//array implementation of circular queues
#include<iostream> 
using namespace std;

#define MAX 3

typedef struct
{
  int element[MAX];
  int front, rear;
} queue;
queue
init ()
{
  queue Q;
  Q.front = -1;
  Q.rear = -1;
  return Q;
}

int size (queue Q)
{
  return (Q.rear - Q.front + 1);
}

int isEmpty (queue Q)
{
  return ((Q.front == Q.rear) && (Q.rear == -1));
}

int isFull (queue Q)
{
  return (Q.front == (Q.rear + 1) % MAX);
}

void front (queue Q)
{
  if (isEmpty (Q))
    {
      cout << "the queue is empty\n";
    }
  else
    cout << Q.element[Q.front];
}

queue enqueue (queue Q, int x)
{
  if (isFull (Q))
    {
      cout << "Overflow" << endl;
    }
  else if (isEmpty (Q))
    {
      Q.front = 0;
      Q.rear = 0;
      Q.element[Q.rear] = x;
    }
  else
    {
      Q.rear = (Q.rear + 1) % MAX;
      Q.element[Q.rear] = x;
    }
  return Q;
}

queue dequeue (queue Q)
{
  if (isEmpty (Q))
    {
      cout << "Underflow";
    }
  else
    {
      Q.front = (Q.front + 1) % MAX;
    }
  return Q;
}

void print (queue Q)
{
  if (isEmpty (Q))
    {
      cout << "\nthe queue is empty";
    }
  else
    {
      int i;
      for (i = Q.front; i != Q.rear; i = (i + 1) % MAX)
	{
	  cout << Q.element[i] << " ";
	}
      cout << Q.element[i] << " ";

    }
  cout << "\nthe front is ";
  front (Q);
  cout << "\nThe size is: " << size (Q);
}

int main ()
{
  queue Q;
  Q = init ();
  int choice = 0;
  while (choice != 4)
    {
      cout <<
	"\nSelect a choice\n1. Enqueue\n2. Dequeue\n3. display\n4. Exit\n";
      cin >> choice;
      switch (choice)
	{
	case 1:
	  cout << "\nEnter the element: ";
	  int elem;
	  cin >> elem;
	  Q = enqueue (Q, elem);
	  break;
	case 2:
	  Q = dequeue (Q);
	  break;
	case 3:
	  print (Q);
	  break;
	default:
	  cout << "Invalid choice";
	}
    }
}
