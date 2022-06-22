#include<iostream>

void a(int a = 1)
{
	std :: cout << a << "\n";
}

int main()
{
	a();
	a(3);
}
