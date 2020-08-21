#pragma once

template<class T>
class Myforward_list
{
	class node {
	public:
		T data;
		node *ptrNext;
		node(T data = T(), node *ptr = nullptr): data(data), ptrNext(ptr) {}
	};

	node* head;
	size_t size;

	node* search_data(const size_t index) {
		if (index >= size) {
			throw std::exception("Incorrect index value");
		}

		node *ptr = head;
		size_t iter = 0;

		while (iter != index) {
			ptr = ptr->ptrNext;
			iter++;
		}
		return ptr;
	}

public:
	Myforward_list();
	~Myforward_list();

	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void clear();
	void insert_after(T data, const size_t index);
	void erase_after(const size_t index, const size_t range = 1);
	size_t GetSize();
	T& operator [](const size_t index);
};


template<class T>
Myforward_list<T>::Myforward_list() : head(nullptr), size(0) {}

template<class T>
Myforward_list<T>::~Myforward_list() { clear(); }

template<class T>
void Myforward_list<T>::push_back(T data) 
{	
	size++;
	if (head == nullptr) {
		head = new node(data);
		return;
	}
	node *ptr = head;
	while (ptr->ptrNext != nullptr) {
		ptr = ptr->ptrNext;
	}
	ptr->ptrNext = new node(data);
	return;
}

template<class T>
inline void Myforward_list<T>::push_front(T data)
{
	head = new node(data, head);
}

template<class T>
inline void Myforward_list<T>::pop_front() 
{
	node *ptr = head;
	head = head->ptrNext;
	delete ptr;
	size--;
}

template<class T>
void Myforward_list<T>::clear()
{
	while (head != nullptr) {
		pop_front();
	}
}


template<class T>
inline void Myforward_list<T>::insert_after(T data, const size_t index)
{
	node * ptr = search_data(index);
	ptr->ptrNext = new node(data, ptr->ptrNext);
	size++;
}

template<class T>
inline void Myforward_list<T>::erase_after(const size_t index, const size_t range)
{
	node *ptr = search_data(index);
	ptr = ptr->ptrNext;
	node *tmp;
	size_t iter = index + 1;

	while (iter < iter + range) {
		tmp = ptr;
		ptr = ptr->ptrNext;
		delete tmp;
		iter++;
	}
}

template<class T>
inline size_t Myforward_list<T>::GetSize()
{
	return size;
}

template<class T>
inline T & Myforward_list<T>::operator[](const size_t index)
{	
	
	return (search_data(index))->data;
}
