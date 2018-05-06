#include <algorithm>
#include <cassert>
#include <iostream>

template <typename T>
class vector_t
{
private:
	T * elements_;
	std::size_t size_;
	std::size_t capacity_;
public:
	vector_t();
	vector_t(vector_t<T> const & other);
	vector_t<T> & operator =(vector_t<T> const & other);
	~vector_t();

	std::size_t size() const;
	std::size_t capacity() const;

	void push_back(T value);
	void pop_back();

	T & operator [](std::size_t index);
	T operator [](std::size_t index) const;
	T & at (std::size_t index);

	bool operator ==(vector_t const & other) const;
};

bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs);

template <typename T>
vector_t<T>::vector_t()
{
	elements_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

template <typename T>
vector_t<T>::vector_t(vector_t<T> const & other)
{
	size_ = other.size_;
	capacity_ = other.capacity_;

	elements_ = new T[capacity_];
	for (std::size_t i = 0; i < size_; ++i) {
		elements_[i] = other.elements_[i];
	}
}

template <typename T>
vector_t<T> & vector_t<T>::operator =(vector_t<T> const & other)
{
	if (this != &other) {
		delete[] elements_;

	size_ = other.size_;
	capacity_ = other.capacity_;

	elements_ = new T[capacity_];
	for (std::size_t i = 0; i < size_; ++i) {
		elements_[i] = other.elements_[i];
	}
	}
	
	return *this;
}

template <typename T>
bool vector_t<T>::operator ==(vector_t<T> const & other) const
{
	bool success = false;
	if (size_ == other.size_ && capacity_ == other.capacity_) {
		for (size_t i = 0; i < size_; i++) {
			if (elements_[i] == other.elements_[i]) {
				success = true;
				break;
			}
			else {
				success = false;
			}
		}
	}
	if (success) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
vector_t<T>::~vector_t()
{
	delete[] elements_;
}

template <typename T>
std::size_t vector_t<T>::size() const
{
	return size_;
}

template <typename T>
std::size_t vector_t<T>::capacity() const
{
	return capacity_;
}

template <typename T>
void vector_t<T>::push_back(T value)
{
	if (size_ == capacity_) {
		if (capacity_ == 0) capacity_ = 1;
		else capacity_ *= 2;
		int * p = new T[capacity_];
		for (std::size_t i = 0; i<size_; i++) {
			p[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = p;
	}

	elements_[size_++] = value;
}

template <typename T>
void vector_t<T>::pop_back()
{
	if (size_ == 0) return;
	size_--;
	if (size_ == capacity_ / 4) {
		capacity_ /= 2;
		T * p = new T[capacity_];
		for (std::size_t i = 0; i<size_; i++) {
			p[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = p;
	}
}

template <typename T>
T & vector_t<T>::operator [](std::size_t index)
{
	return elements_[index];
}

template <typename T>
T vector_t<T>::operator [](std::size_t index) const
{
	return elements_[index];
}

template <typename T>
T & vector_t<T>::at (std::size_t index)
{
	if ( index >= size_ ) {
		throw std::out_of_range( "Error range" );
	}
	return elements_[index];
}

template <typename T>
bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs)
{
	bool success = true;
	if (lhs == rhs) {
		return !success;
	}
	return success;
}
