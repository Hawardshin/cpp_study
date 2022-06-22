#include<iostream>
#include<array>

int main()
{
	std:: array<int,5> arr = {1,2,3,4,5};
	std ::cout << arr[2] << "\n";
	std :: cout << arr.size()<< "\n";
	for (int a : arr)
		std :: cout << a << "\n";
	arr.fill(2);
	for (int a : arr)
		std :: cout << a << "\n";
}
