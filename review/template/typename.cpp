#include<iostream>

template <typename T>
void print(T arg)
{
	std :: cout << arg << "hi" << std :: endl;
}

template<typename T, typename... Types>
void print(T arg, Types... args)
{
	std :: cout << "sizeof :::: " << sizeof...(args) << "\n";
	std :: cout << arg << ", ";
	print(args...);
}

int main()
{
	print(1,3.1,"abc");
	print(1, 2, 3, 4, 5, 6, 7);
}
