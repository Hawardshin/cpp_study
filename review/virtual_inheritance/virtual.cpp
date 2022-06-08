#include<iostream>
#include<string>
using namespace std;
class human
{
	int age;
	public :
		human() :age(30)
	{
		cout << "사람 생성자 생성, 나이: " << age << "\n";
	}

		void print_age()
		{
			cout << age <<age;
		}
};

class handsomehuman :public virtual human
{
	private :
		string face;
	public :
		handsomehuman()  { 
			face = "handsome";
			cout << "face 생성자 생성" << face << "\n";
		}
};

class smartsomehuman :public virtual human
{
	private :
		string smart;
	public :
		smartsomehuman()
		{
			smart = "smart";
			cout << "smart 생성자 생성 " << smart << "\n";
		}
};

class me : public handsomehuman, public smartsomehuman
{
	private :
		string name;
	public : 
		me () 
		{
			name = "joung";
			cout << "name생성자 생성 " << name << "\n";
		}
};

int main()
{
	me a;
}

