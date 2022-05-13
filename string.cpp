#include<iostream>

class string {
  char *str;
  int len;

 public:
  string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
  string(const char *s);
  string(const string &s);
  ~string();

  void add_string(const string &s);   // str 뒤에 s 를 붙인다.
  void copy_string(const string &s);  // str 에 s 를 복사한다.
  int strlen();// 문자열 길이 리턴
  void Print();
};

string::~string()
{
	if(str)
	{
		delete []str;
	}
}

void string::Print()
{
	std::cout << str<<std::endl;
}

string :: string(char c, int n)
{
	str = new char[n +1];
	for (int i = 0; i < n; i++)
		str[i] = 'c';
	len = n;
	str[n] = '\0';
}

string :: string(const char *s)
{
	int tmp = 0;
	while (s[tmp])
		tmp++;
	str = new char[tmp + 1];
	for (int i= 0; i < tmp; i++)
		str[i] = s[i];
	str[tmp] = 0;//0과 \0이 관계가 없는지.
	len = tmp;
}

string :: string (const string &s)
{
	int tmp = s.len; // 같은 클래스에 있는 함수는 따로 이름공간 명시를 해주지 않아도 사용이 가능한건가?
	str = new char[tmp + 1];
	for (int i= 0; i < tmp; i++)
		str[i] = s.str[i];
	str[tmp] = '\0';
}
void string::add_string(const string &s)
{
	len = len+ s.len;
	char *tmp = new char [len + s.len];
	int i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	int j = 0;
	while(s.str[j])
		tmp[i++] = s.str[j++];
	tmp[i] = '\0';
	delete []str;
	str = new char [i + 1];
	i = 0;
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';
}

void string::copy_string(const string &s)
{
	if (str != 0)
		str = new char [s.len];
	int i = 0;
	while(s.str[i])
	{
		str[i] = s.str[i];
		i++;
	}
	str[i] = '\0';
}

int string::strlen()
{
	int i =0;
	while (str[i])
		i++;
	return (i);
}

int main()
{
	string hi("hi");
	string hello("hello");
	hi.add_string(hello);
	hi.Print();
	hello.Print();
}
