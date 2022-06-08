#include<iostream>
#include<string>

int main()
{
	std :: string s;
	std :: cin >> s;

	std::basic_streambuf<char>* rd =std :: cin.rdbuf();
	char peek =std ::cin.rdbuf()->snextc();
	//std ::cout << rd;
	std ::cout << rd << "rd \n";
	std ::cout << peek << "peek\n";
}
