#include<iostream>

template<int n>
struct factorial{
	static const int result = n * factorial<n-1> :: result;
};

template<>
struct factorial<1>{
	static const int result = 1;
};


int main()
{
	std :: cout << "6! = 1 * 2* 3 * 4 * 5 *6 = " << factorial<10> :: result << "\n";
}

