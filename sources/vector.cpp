
#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
	elements_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

vector_t::vector_t(vector_t const & other)
{
	elements_ = new int[other.capacity_];
	size_ = other.size_;
	capacity_ = other.capacity_;
	for (int i = 0; i < size_; i++) {
		elements_[i] = other.elements_[i];
	}
}

vector_t & vector_t::operator =(vector_t const & other)
{
	if (other==*this) {
		return *this;
	}
	delete[] elements_;
	capacity_ = other.capacity_;
	size_ = other.size_;
	elements_ = new int[capacity_];
	for (int i = 0; i < size_; i++) {
		elements_[i] = other.elements_[i];
	}
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	bool equal = false;
	if (size_ == other.size_) {
		for (int i = 0; i < size_; i++) {
			if (elements_[i] != other.elements_[i]) {
				return false;
			}
		}
		equal = true;
	}
	return equal;
}

vector_t::~vector_t()
{
	if (elements_ != nullptr) {
		delete[] elements_;
	}
	size_ = 0;
	capacity_ = 0;
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
	if (size_==0) {
		elements_ = new int[1];
		elements_[0] = value;
		size_++;
		capacity_++;
		return;
	}
	else {
		if (size_==capacity_) {
			capacity_ *= 2;
			int *v_copy = new int[capacity_];
			for (int i = 0; i < size_; i++) {
				v_copy[i] = elements_[i];
			}
			v_copy[size_] = value;
			size_++;
			delete[] elements_;
			elements_ = v_copy;
			return;
		}
		elements_[size_] = value;
		size_++;
		return;
	}
}

void vector_t::pop_back()
{
	if (size_ == 0) {
		return;
	}
	if (size_==1) {
		size_ = 0;
		capacity_ = 1;
	}
	else {
		size_--;
		if (size_ == (capacity_/4)) {
			capacity_ /= 2;
			int *v_temp = new int[capacity_] {};
			for (int i = 0; i < size_; i++) {
				v_temp[i] = elements_[i];
			}
			delete[] elements_;
			elements_ = v_temp;
		}
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
	bool equal = true;
	if (lhs == rhs) {
		equal = false;
	}
	return equal;
}
