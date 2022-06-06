#include<iostream>

namespace
{
	void only_this_file()
	{
		std ::cout << "only\n";
	}
	int only = 0;
}
void t()
{
	static int a;
	std ::cout <<a<< "\n";
	a++;
}
int main()
{
	only_this_file();
	std ::cout << "only" << only<< "\n";
	only = 1;
	std ::cout << "only" << only<<"\n";
	t();
}
