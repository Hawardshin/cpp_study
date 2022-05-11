#include<iostream>

using std::cout;
using std::cin;
using std::endl;
void print(int x) {cout<<"int : "<< x <<endl;}
void print(char x) {cout<<"char : " << x << endl;}
void print(double x) {cout << "double : " << x <<endl;}

int main()
{
	int a =1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	print(b);
	print(c);
	return (0);
}
