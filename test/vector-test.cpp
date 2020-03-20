#include <iostream>
#include "../include/vector.h"

int main(){
	using sigcpp::vector;

	vector<int> v;

	const unsigned inSize = 50;
	
	for (int i = 0; i < inSize; i++)
		v.push_back(i);
	
	for (int i = 0; i < inSize; i++) {
		std::cout << v[i] << std::endl;
	}

	
}