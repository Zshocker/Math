#pragma once
namespace Algo {
	template <class T>
	class Stack
	{

	public:
		void push(T* E);
		void pop();
		bool empty() const;
		T* top() const;
		static Stack* creator();
		static void garbage(Stack* S);
		Stack();
		~Stack();
	private:
		class Node* head;
		
	};
};
namespace Algo {
	template<class T>
	class Node
	{
	private:
		T* data;
		Node* next;
	public:
		void push_front(T* E) {
			Node* newNode = new Node();
			assert(newNode != 0);
			newNode->data = E;
			newNode->next = this->head;
			this->head = newNode;
		};
		void push_back() 
		{
			Node* newNode = new Node();
			assert(newNode != 0);
			newNode->data = E;
			newNode->next = NULL;
			Node* cou =this;
			while (cou->next)cou = cou->next;
			cou->next = newNode;
		}
		T acces_Head() {

		}
	};
};

void Algo::Stack::pop()
{
	assert(!this->empty());
	Node* supp = this->head;
	this->head = this->head->next;
	delete supp;
	supp = 0;
}

bool Algo::Stack::empty() const
{
	bool res = (this->head == 0);
	return res;
}

T* Algo::Stack::top() const
{
	assert(!this->empty());
	return this->head->data;
}
Stack* Algo::Stack::creator()
{
	Stack* S = new Stack();
	assert(S);
	return S;
}
void Algo::Stack::garbage(Stack* S)
{
	if (S)
		delete S;
}
Stack::Stack()
{
	this->head = 0;
}

Algo::Stack::~Stack()
{
	while (this->head)
	{
		this->pop();
	}
	// delete this->head;
	// this->head = 0;
}
