#include<iostream>
#include<string>
class Vector
{
	std::string* data;
	int capacity;
	int length;

	public:
	 Vector(int n=1);
	 std ::string operator[](int i);
	 void remove(int x);
	 int size();
	 void show_length(){ std::cout << length << "\n"; }
	 void show_capacity(){std :: cout << capacity << "\n";}
	 //~Vector();
};

Vector :: Vector(int n) : data(new std::string[n]),capacity(n),length(0){}

int main()
{
	Vector a; 
	a.show_length();
	a.show_capacity();
}
