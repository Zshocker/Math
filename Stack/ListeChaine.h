#pragma once
#include<assert.h>
#include<iostream>
using namespace std;
namespace Algo {
	template<class T>
	class Node
	{
	private:
		T data;
		Node* next;
	public:
		Node(T data) 
		{
			this->data = data;
			this->next = NULL;
		}
		Node* push_front(T E) 
		{
			Node* newNode = new Node(E);
			assert(newNode != 0);
			newNode->next = this;
			return newNode;
		};
		void push_back(T E)
		{
			Node* newNode = new Node(E);
			assert(newNode != 0);
			Node* cou = this;
			while (cou->next)cou = cou->next;
			cou->next = newNode;
		}
		T acces_Head() 
		{
			return data;
		}
		int size(){
			Node* Cour = this;
			int i = 0;
			if (!Cour)return 0;
			while (Cour) {
				i++;
				Cour = Cour->next;
			}
			return i;
		}
		Node* Delete_front() {
			Node* E = this->next;
			this->next = NULL;
			delete this;
			return E;
		}
		Node* Delete_Back() 
		{
			Node* Cour=this;
			if (size()<2) 
			{
				return Delete_front();
			}
			while (Cour->next->next)
			{
				Cour = Cour->next;
			}
			delete Cour->next;
			Cour->next = NULL;
			return this;
		}
		T& operator[](int a) {
			assert(a >= -1 && a < size());
			Node* Cour=this;
			if (a == -1)a = size() - 1;
			for (int i = 0; i < a; i++)
			{
				Cour = Cour->next;
			}
			return Cour->data;
		}
		void print_all() 
		{
			Node* Courant=this;
			while (Courant) 
			{
				cout << Courant->data << " -- ";
				Courant = Courant->next;
			}
			cout << endl;
		}
		~Node()
		{
			while (size()>1)
			{
				Delete_Back();
			}
		}
	};
	template<class T>
	class Liste 
	{
	private:
		Node<T>* Head;
	public:
		Liste() 
		{
			this->Head = NULL;
		}
		bool isEmpty()const {
			return Head == NULL;
		}
		void Delete_front() 
		{
			if (!isEmpty()) {
				Head=Head->Delete_front();
			}
		}
		void Delete_Back() {
			if (!isEmpty()) {
				Head = Head->Delete_Back();
			}
		}
		void push_back(T var) 
		{
			if (isEmpty()) {
				Head = new Node<T>(var);
				return;
			}
			Head->push_back(var);
		}
		void push_front(T var) 
		{
			if (isEmpty()) {
				Head = new Node<T>(var);
				return;
			}
			Head=Head->push_front(var);
		}
		T& operator[](int a)const
		{
			assert(!isEmpty());
			return Head[a];
		}
		~Liste()
		{
			if (!isEmpty()) {
				delete Head;
			}
		}
		int size()const{
			if (isEmpty())return 0;
			return Head->size();
		}
		void Print() const
		{
			if (!isEmpty())
			{
				Head->print_all();
			}
		}
	};
};

