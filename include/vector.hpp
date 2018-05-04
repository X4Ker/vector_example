#include <algorithm>
#include <cassert>
#include <iostream>

class vector_t
{
private:
	int * elements_;
	std::size_t size_;
	std::size_t capacity_;
public:
	vector_t();
	vector_t(vector_t const & other);
	vector_t & operator =(vector_t const & other);
	~vector_t();

	std::size_t size() const;
	std::size_t capacity() const;

	void push_back(int value);
	void pop_back();

	int & operator [](std::size_t index);
	int operator [](std::size_t index) const;

	bool operator ==(vector_t const & other) const;
};

bool operator !=(vector_t const & lhs, vector_t const & rhs);

vector_t::vector_t()
{
	elements_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

vector_t::vector_t(vector_t const & other)
{
	size_ = other.size_;
	capacity_ = other.capacity_;

	elements_ = new int[capacity_];
	for (std::size_t i = 0; i < size_; ++i) {
		elements_[i] = other.elements_[i];
	}
}

vector_t & vector_t::operator =(vector_t const & other)
{
	if (this != &other) {
		delete[] elements_;

	size_ = other.size_;
	capacity_ = other.capacity_;

	elements_ = new int[capacity_];
	for (std::size_t i = 0; i < size_; ++i) {
		elements_[i] = other.elements_[i];
	}
	}
	
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
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

vector_t::~vector_t()
{
	delete[] elements_;
}

std::size_t vector_t::size() const
{
	return size_;
}

std::size_t vector_t::capacity() const
{
	return capacity_;
}

void vector_t::push_back(int value)
{
	if (size_ == capacity_) {
		if (capacity_ == 0) capacity_ = 1;
		else capacity_ *= 2;
		int * p = new int[capacity_];
		for (std::size_t i = 0; i<size_; i++) {
			p[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = p;
	}

	elements_[size_++] = value;
}

void vector_t::pop_back()
{
	if (size_ == 0) return;
	size_--;
	if (size_ == capacity_ / 4) {
		capacity_ /= 2;
		int * p = new int[capacity_];
		for (std::size_t i = 0; i<size_; i++) {
			p[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = p;
	}
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
	return elements_[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	bool success = true;
	if (lhs == rhs) {
		return !success;
	}
	return success;
}
