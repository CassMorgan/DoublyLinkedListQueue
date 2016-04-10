//Cass Morgan II
//CSC 375 Homework 03
//Date 04/09/16

#include <iostream>
using namespace std;

struct Profile{
    string name;
    string state;
};

template <class T>
struct Node {
	T info;
	Node<T> *next;
	Node<T> *prev;
};

template <class T>
class Queue
{
public:
	Queue();
	virtual ~Queue();
	void enqueue(const T & element);
	bool dequeue(T & deqElement);
	void print_forward();
	void print_backward();
	void make_empty();
	bool is_empty() const;

private:
	Node<T> *head;
	Node<T> *tail;
	inline void deepCopy(const Queue<T> & original);
};

ostream& operator<<(ostream &out, Profile &user){
out<< user.name;
out<< user.state;
return out;
}

template <class T>
Queue<T>::Queue()
{
	head = tail = NULL;
}

template <class T>
Queue<T>::~Queue()
{
//	make_empty();
}

template <class T>
void Queue<T>::enqueue(const T & element)
{
	Node<T> *ptr = new Node<T>;
	ptr->info = element;
    ptr->next = NULL;

    if(head == NULL){
        head = ptr;
        tail = ptr;
        ptr->prev = NULL;
    }

    else {
        ptr->prev = tail;
        tail->next = ptr;
        tail = ptr;
    }
}

template <class T>
bool Queue<T>::dequeue(T & deqElement)
{
	if (head == tail)
        return false;

    Node<T> *ptr = head;
    head = ptr->next;
	delete ptr;

	return true;
}

template <class T>
void Queue<T>::print_forward()
{
	if (head == tail)
		cout<< "The queue is empty" <<endl;

    Node<T> *ptr = head;
    while(ptr != NULL){
        cout<< ptr->info.name << ", " << ptr->info.state <<endl;
        ptr = ptr->next;
    }
}


template <class T>
void Queue<T>::print_backward()
{
	if (head == tail)
        cout<< "The queue is empty" <<endl;

    Node<T> *ptr = tail;
    while(ptr->prev != NULL){
        cout<< ptr->info.name << ", " << ptr->info.state <<endl;
        ptr = ptr->prev;
    }
}

template <class T>
void Queue<T>::make_empty()
{
   	T temp;
	while(dequeue(temp));
}

template <class T>
bool Queue<T>::is_empty() const
{
   	 if(head == tail){
        cout<< "\nThe list is empty!" <<endl;
        return true;
   	 }
     else {
        cout<< "\nThe list is not empty!" <<endl;
        return false;
     }
}
