/* 1. 문자 char로부터의 문자열 생성, char *로 부터 생성
   2. 문자열의 길이를 구하는 함수
   3. 문자열 뒤에 다른 문자열 붙히기 
   4. 문자열 내에 포함되어 있는 문자열 구하기
   5. 문자열이 같은지 비교
   6. 문자열의 크기비교 (사전순)
 */

#include<iostream>
using namespace std;
class mystr
{
	private :
		char *str;
		int len;
	public :
		mystr(char a);
		mystr(char a, int slen);
		mystr(const char *istr);
		void print_str();
		int my_strlen();

};

mystr :: mystr(char a)
{
	str = new char [2];
	len = 1;
	str[0] = a;
	str[1] = '\0';
}
mystr ::mystr(char a, int slen)
{
	str = new char [slen+1];
	len = slen;
	for (int i = 0; i < slen; i++)
		str[i] = a;
	str[slen] = '\0';
}

mystr:: mystr(const char *istr)
{
	int ilen = 0;;
	while (istr[ilen])
		ilen++;
	len = ilen;
	str = new char[ilen + 1];
	for (int i = 0; i < ilen; i++)
		str[i] = istr[i];
	str[ilen] = '\0';
}

void mystr :: print_str()
{
	cout << "str is:: " <<str<<"\n";
	cout << "len is ::" << len << "\n";
}

int mystr :: my_strlen()
{
	int stlen = 0;
	while (str[stlen])
		stlen++;
	return (stlen);
}
int main()
{
	mystr joushin("joushin");
	mystr j('j');
	mystr a10('a', 10);
	joushin.print_str();
	j.print_str();
	a10.print_str();
}
