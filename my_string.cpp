#include<iostream>
#include<string.h>
class my_string {
  char *str;
  int len;

 public:
  my_string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
  my_string(const char *s);
  my_string(const my_string &s);
  ~my_string();

  my_string &assign(const my_string &s);
  my_string &assign(const char *mstr);
  void add_my_string(const my_string &s);   // str 뒤에 s 를 붙인다.
  void copy_my_string(const my_string &s);  // str 에 s 를 복사한다.
  void my_strcmp(my_string &a1, my_string &a2);
  int mstrlen();// 문자열 길이 리턴
  void Print();
};

my_string::~my_string()
{
	if(str)
	{
		len = 0;
		delete []str;
	}
}

void my_string::Print()
{
	std::cout << str<<std::endl;
}

my_string :: my_string(char c, int n)
{
	str = new char[n +1];
	for (int i = 0; i < n; i++)
		str[i] = 'c';
	len = n;
	str[n] = '\0';
}

my_string :: my_string(const char *s)
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

my_string :: my_string (const my_string &s)
{
	int tmp = s.len; // 같은 클래스에 있는 함수는 따로 이름공간 명시를 해주지 않아도 사용이 가능한건가?
	str = new char[tmp + 1];
	for (int i= 0; i < tmp; i++)
		str[i] = s.str[i];
	str[tmp] = '\0';
}
void my_string::add_my_string(const my_string &s)
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

void my_string::copy_my_string(const my_string &s)
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

int my_string::mstrlen()
{
	int i =0;
	while (str[i])
		i++;
	return (i);
}

void my_string :: my_strcmp(my_string &a1, my_string &a2)
{
	int i = 0;
	while (a1.str[i] == a2.str[i] && a1.str[i] && a2.str[i])
		i++;
	int result = a1.str[i] - a2.str[i];
	if (result==0)
		std::cout << "same" << std::endl;
	else if (result > 0)
		std ::cout << "first is bigger than second" << std::endl;
	else
		std ::cout << "second is bigger than first" << std ::endl;
}
my_string& my_string::assign(const my_string &s)
{
	if (s.len >len)
	{
		delete []str;
		str =new char [s.len];
	}
	for (int i = 0; i  < s.len; i++)
		str[i] = s.str[i];
	len = s.len;
	return *this;
}

my_string& my_string::assign(const char *mstr)
{
	int mylen= strlen(mstr);
	if (mylen > len)
	{
		delete []str;
		str =new char [mylen];
	}
	for (int i = 0; i <mylen; i++)
		str[i] = mstr[i];
	len = mylen;
	return *this;
}
int main()
{
	my_string hi("hi");
	my_string hello("hello");
	hi.add_my_string(hello);
	std::cout<<" hi :: len::" <<hi.mstrlen()<<std::endl;
	hi.my_strcmp(hi,hello);
	hi.Print();
	hello.Print();
}
