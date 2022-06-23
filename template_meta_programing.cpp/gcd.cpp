#include<iostream>

int gcd (int a, int b)
{
	if (b == 0)
		return (a);
	return gcd (b, a % b);
}

template <int a, int b>
struct gcd1
{
	static const int value = gcd1<b, a%b> :: value;
};

template <int x>
struct gcd1 <x, 0>
{
	static const int value = x;
};


int main()	
{
	 std::cout << "gcd (36, 24) :: " << gcd1<36, 24>::value << std::endl;
}
