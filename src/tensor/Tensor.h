#ifndef _TENSOR_H_
#define _TENSOR_H_

#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

template<typename ValueType>
struct TensorIterator;

template<typename T>
class Tensor {
public:

    typedef TensorIterator<T> iterator;
    typedef TensorIterator<const T> const_iterator;

    Tensor(std::vector<std::size_t> _dims, T value = T()) : 
        data(std::accumulate(_dims.begin(), _dims.end(), 1u, std::multiplies<std::size_t>())), dims(_dims)
    {
    }

    Tensor(const Tensor& other) : data(other.data), dims(other.dims)
    {
    }

    iterator begin() {
        return iterator(data.get());
    }

    iterator end() {
        return iterator(data.get() + data.size());
    }

    const_iterator cbegin() const {
        return const_iterator(data.get());
    }

    const_iterator cend() const {
        return const_iterator(data.get() + data.size());
    }

private:
    std::vector<T> data;
    std::vector<std::size_t> dims;
};

template<typename ValueType>
struct TensorIterator {

    using iterator_category = std::random_access_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = ValueType;
    using pointer = ValueType*;
    using reference = ValueType&;

    TensorIterator(pointer _ptr) : ptr(_ptr)
    {
    }

    TensorIterator() = default;
    TensorIterator(const TensorIterator&) = default;
    TensorIterator& operator=(const TensorIterator&) = default;
    ~TensorIterator() = default;

    reference operator*() const { return *ptr; }
    pointer operator->() const { return ptr; }

    TensorIterator& operator++() { ptr++; return *this; }
    TensorIterator operator++(int) { auto tmp = *this; ++(*this); return tmp; }
    TensorIterator& operator--() { ptr--; return *this; }
    TensorIterator operator--(int) { auto old = *this; --(*this); return old; }

    TensorIterator& operator+=(difference_type n) { ptr += n; return *this; }
    TensorIterator& operator-=(difference_type n) { return *this += -n; }

    reference operator[](difference_type n) { return *(ptr + n); }
    const reference operator[](difference_type n) const { return *(ptr + n); }

    bool operator== (const TensorIterator& other) const { return ptr == other.ptr; };
    bool operator!= (const TensorIterator& other) const { return *this != other; };

    bool operator<(const TensorIterator& other) const { return distance(ptr, other.ptr) > 0; }
    bool operator>(const TensorIterator& other) const { return distance(ptr, other.ptr) < 0; }
    bool operator<=(const TensorIterator& other) const { return !(*this > other); }
    bool operator>=(const TensorIterator& other) const { return !(*this < other); }
    TensorIterator operator+(difference_type n) const { auto it = *this; it += n; return it; }
    TensorIterator operator-(difference_type n) const { auto it = *this; it -= n; return it; }
    difference_type operator-(const TensorIterator& other) { return std::distance(ptr, other.ptr); }

private:
    pointer ptr;
};

#endif // _TENSOR_H_
