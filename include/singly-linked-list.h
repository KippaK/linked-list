#include <cstddef>

template <typename T>
class Linked_list {
public:
	Linked_list();
	Linked_list(T aData);
	Linked_list(T aData, Linked_list<T> *aNext);
	~Linked_list();

	T& at(size_t idx) const;
	T& front() const;
	T& back() const;
	
	void push_back(T aData);
	void insert(T aData, size_t idx);
	void pop(size_t idx);

	bool empty() const;
	size_t size() const;

private:
	size_t size(size_t count) const;

protected:
	T data;
	Linked_list<T>* next;
};

template <typename T>
Linked_list<T>::Linked_list()
{
	data = NULL;
	next = nullptr;
}

template <typename T>
Linked_list<T>::Linked_list(T aData)
{
	data = aData;
	next = nullptr;
}

template <typename T>
Linked_list<T>::Linked_list(T aData, Linked_list<T>* aNext)
{
	data = aData;
	next = aNext;
}

template <typename T>
Linked_list<T>::~Linked_list() 
{
	delete next;
}

template <typename T>
T& Linked_list<T>::at(size_t idx) const 
{
	if (idx == 0) {
		return data;
	}
	if (next == nullptr) {
		return NULL;
	}
	return next->at(idx - 1);
}

template <typename T>
T& Linked_list<T>::front() const
{
	return data;
}

template <typename T>
T& Linked_list<T>::back() const
{
	if (next == nullptr) {
		return data;
	}
	return next->back();
}

template <typename T>
void Linked_list<T>::push_back(T aData)
{
	if (next == nullptr) {
		next = new Linked_list<T>(aData);
		return;
	}
	next->push_back(aData);
}

template <typename T>
void Linked_list<T>::insert(T aData, size_t idx)
{
	if (idx == 0) {
		Linked_list<T>* node_cpy = new Linked_list<T>(data, next);
		next = node_cpy;
		data = aData;
		return;
	}
	if (idx > 1) {
		next->insert(aData, idx - 1);
		return;
	}
	next = new Linked_list<T>(aData, next); 
}

template <typename T>
void Linked_list<T>::pop(size_t idx)
{
	if (idx == 0 && next == nullptr) {
		data = NULL;
		return;
	}
	if (idx == 0) {
		Linked_list<T>* old_next = next;
		data = next->data;
		next = next->next;
		old_next->next = nullptr;
		delete old_next;
		return;
	}
	if (idx > 1) {
		next->pop(idx - 1);
		return;
	}
	if (next->next == nullptr) {
		delete next;
		next = nullptr;
		return;
	}
	Linked_list<T>* old_next = next;
	next = next->next;
	old_next->next = nullptr;
	delete old_next;
	return;
}

template <typename T>
bool Linked_list<T>::empty() const
{
	return (data == NULL && next == nullptr);
}

template <typename T>
size_t Linked_list<T>::size(size_t count) const
{
	if (next == nullptr) {
		return count;
	}
	return next->size(count + 1);
}

template <typename T>
size_t Linked_list<T>::size() const
{
	if (data == NULL && next == nullptr) {
		return 0;
	}
	if (next == nullptr) {
		return 1;
	}
	return next->size(2);
}
