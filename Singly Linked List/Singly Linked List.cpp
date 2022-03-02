#include <iostream>
using namespace std;

template <typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	void push_front(T data);
	void pop_front(); //deleting first element
	void pop_back();
	void insert(T value, int index);
	void deleteAt(int index);
	int GetSize() { return Size; }
	void clear();

	T& operator[](const int index); //prototype of overloading[]
	

private:

	template<typename T>
	class Node 
	{
	public: 
		Node* pNext; //pointer on the next node
		T data;


		Node(T data = T(), Node* pNext = nullptr) //T() means that the value will be assigned to a default
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head; 

};


template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List()
{
	clear();


}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* temp = this->head;
		while (temp->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		temp->pNext = new Node<T>(data);


	}
	Size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	/*Node<T> *newNode = new Node<T>(data, head);
	head = newNode;*/
	//this part is just for understanding the line below
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head->pNext;
	delete head;
	head = temp;
	Size--;
}

template<typename T>
void List<T>::pop_back()
{
	deleteAt(Size - 1);
}

template<typename T>
void List<T>::insert(T value, int index)
{
	if (index == 0) push_front(value);
	else if (index >= Size) cout << "You cannot insert an element to an undeclared index(try to use push_back())" << endl;
	else
	{
		Node<T>* current = head;
		for (int i = 1; i < Size; i++)
		{
			if (i == index)
			{
				/*Node<T>* newNode= new Node<T>(value, current->pNext);
				current->pNext = newNode;*/
				//this part is just for understanding the line below

				current->pNext = new Node<T>(value, current->pNext);
				Size++;
				break;
			}
			current = current->pNext;
		}


	}

}

template<typename T>
void List<T>::deleteAt(int index)
{
	if (index == 0) pop_front();
	else if (index >= Size) cout << "Warning!!!Index is bigger than size of a list" << endl;
	else
	{
		Node<T>* prevoius = head;
		for (int i = 1; i < Size; i++)
		{
			if (i == index)
			{
				Node<T>* current = prevoius->pNext, * next = current->pNext;
				prevoius->pNext = next;
				delete current;
				Size--;
				break;
			}
			prevoius = prevoius->pNext;
		}
	}
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		//the same logic as in pop_front()
		/*Node* temp = head;
		head = head->pNext;
		delete temp;*/
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{

	Node<T>* temp = this->head;
	for (int i = 0; i < Size; i++)
	{
		if (i == index)
		{
			return temp->data;
		}
		temp = temp->pNext;
	}
	std::cout << "The index is bigger than the size of list" << std::endl;
}

int main()
{
	return 0;
}


