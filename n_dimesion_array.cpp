/*N 차원 배열을 제공하는 클래스를 만들어보세요. 이는 여러분이 여태까지 배운 내용을 시험할 것입니다. 참고로, 원소에 접근하기 위해서는 a[1][2][3] 과 같은 방법으로 접근하겠지요. 다만 N 차원 배열이기 때문에 (N은 객체 생성시에 사용자가 입력합니다) 2 차원 배열은 a[1][2], 3 차원 배열은 a[1][2][3] 과 같은 방식으로 접근할 것입니다. (난이도 : 最上)*/

#include<iostream>

int ft_strlen(const char *arr)
{
	int i=0;
	while (arr[i])
		i++;
	return (i);
}

class array
{
	char *arr1;
//	void **arr2;
//	void ***arr3;
//	void ****arr4;
//	void *****arr5;
	int a1_len;
//	int a2_len;

	public :
	array() { arr1 = new char[5]; a1_len =0;}
	array(const int index) 
	{ 
		arr1 = new char[index]; 
		a1_len = index;
	}
	array(const char c)
	{
		arr1 = new char[1];
		arr1[0] = c;
	}
	array(const char *str)
	{

		arr1 = new char [ft_strlen(str)];
		for (int i= 0; i < ft_strlen(str); i++)
			arr1[i] = str[i];
		a1_len = ft_strlen(str);

	}
///	int array : array(const int index) { (int *)arr1 = new int[index]};
	char &operator[] (const int index);
///	int &operator[] (const int index);
//	char &operator[][] (const int index1, const int index2);
//	int &operator[][] (const int index, const int index2);
	char*& operator[] (array &a1);
	friend std :: ostream& operator <<(std :: ostream& os, const array &c);
///	friend int operator[] (array &a1);
};

std :: ostream &operator <<(std :: ostream & os,const array &c)
{
	for (int i=0; i <c.a1_len; i++)
		os << c.arr1[i] <<"\n";
	return os;
}

char & array :: operator[] (const int index)
{ return (arr1[index]); }


char*& array :: operator[](array &a1)
{
	a1_len =a1.a1_len;
	arr1 = new char[a1_len+1];
	for (int i= 0; i < a1_len; i++)
		arr1[i] = a1.arr1[i];
	return (arr1);
}

int main()
{
	array test = "cc";
	test = "a";
	std ::cout <<test[1];
	for(int i= 0; i < 10; i++)
		std :: cout << test[i]<<"\n";
}
