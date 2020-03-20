/*
* vector.h
* Ty Doris
* Caleb Garrick
* Adam Jeniski
* (c) 2020 sigcpp https://sigcpp.github.io. See LICENSE.MD
*
* Attribution and copyright notice shown on lines 3 and 4 must be retained.
* That info may be relocated but it must be conspicuous in all derived work.
* 
* Define a class template for vectors
* - see C++17 [vector.overview], [vector.syn]
* - https://timsong-cpp.github.io/cppwp/n4659/vector
* - https://timsong-cpp.github.io/cppwp/n4659/vector.syn
*/

#include <memory>
#include <algorithm>

#ifndef SIGCPP_VECTOR_H
#define SIGCPP_VECTOR_H

namespace sigcpp{
	template <class T, class Allocator = std::allocator<T>>
	class vector {
	public:
		// types:
		using value_type = T;
		using allocator_type = Allocator;
		using pointer = typename std::allocator_traits<Allocator>::pointer;
		using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
		using reference = value_type&;
		using const_reference = const value_type&;
		using size_type = size_t;
		using difference_type = std::ptrdiff_t;
		

		//unchecked iterators: not standards-compliant; implementing for demo
		using iterator = T*; 
		using const_iterator = const T*;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;
	

	private:
		// fields:
		allocator_type allocator;
		pointer arr;
		size_type capacity = 10;
		size_type size=0;

	public:
		//construct/copy/destruct
		
		vector() {
			arr = allocator.allocate(capacity, 0);
		}
    	
		//iterators:
		
		//capacity:

		//element access:
		reference operator[](size_type n){return arr[n];}

		const_reference operator[](size_type n) const {return arr[n];}

		void push_back(const_reference val) {
			if (size == capacity) {
				capacity *= 2;
				pointer tempArr = arr;
				arr = allocator.allocate(capacity, arr);
				std::copy(tempArr, tempArr + size, arr);
				allocator.deallocate(tempArr, size);
			}
			arr[size] = val;
			size++;
		};
	};
}

#endif