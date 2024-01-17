#include <cstddef>

template <typename T>
class Linked_list {
public:
	Linked_list();
	Linked_list(T aData);
	~Linked_list();

	T& at(size_t idx);
	T& front();
	T& back();
	
	void push_back(T aData);
	void pop_back();
	void insert(T aData, size_t idx);

	bool empty();
	size_t size();

private:
	void push_back(T aData, size_t idx);

protected:
	T data;
	Linked_list<T>* next;
};

template <typename T>
Linked_list<T>::Linked_list()
{
	data = NULL;
	next = NULL;
}

template <typename T>
Linked_list<T>::Linked_list(T aData)
{
	data = aData;
	next = NULL;
}

template <typename T>
Linked_list<T>::~Linked_list() 
{
	delete next;
}

template <typename T>
T& Linked_list<T>::at(size_t idx) 
{
	if (idx == 0) {
		return data;
	}
	if (next == nullptr) {
		return NULL;
	}
	return next.at(idx - 1);
}

template <typename T>
T& Linked_list<T>::front()
{
	return data;
}

template <typename T>
T& Linked_list<T>::back()
{
	if (next == nullptr) {
		return data;
	}
	return next.back();
}

template <typename T>
void Linked_list<T>::push_back(T aData, size_t idx)
{
	if (next == nullptr) {
		next = new Linked_list<T>(aData);
		return;
	}
	push_back(aData, idx++);
}

template <typename T>
void Linked_list<T>::push_back(T aData)
{
	push_back(aData, 0);
}
