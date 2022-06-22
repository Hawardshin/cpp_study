
#include<iostream>
#include<cstring>
//void kk[](std::string *a)
//{
//	std :: cout << "abc\n";
//}안되는구나 delete가 어떤걸 오버로딩한지 궁금하다.

template<typename t>  // templete <class t> 와 동일하다. 
class Vector
{
	t* data;
	int capacity;
	int length;
	public : 
	Vector(int n = 1) : data (new t[n]), capacity(n),length(0) {}
	void push_back(t s) 
	{
		if (capacity <= length) 
		{
			t* temp = new t[capacity * 2];
			for (int i = 0; i < length; i++) 
			{
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
			capacity *= 2;
		}
		data[length] = s;
		length++;
	}			
	void show_data() { std :: cout << data; }
	t operator[](int i) { return data[i]; }
};

int main()
{
	Vector <int >a;
	int a = 1;
	std :: cout << a<< "\n";


}
