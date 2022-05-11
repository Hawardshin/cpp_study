#include<iostream>
using std::cout;
using std::cin;
using std::endl;
void	change_data(int &year, int &month , int &day)
{
	if (month > 12)
	{
		year += month /12;
		month = month % 12;
		if (month == 0)
			month = 12;
	}
	if (month == 2)
	{
		if (day > 28)
		{
			month++;
			day = day - 28 + 1;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			month++;
			day = day - 30 + 1;
		}
	}
	else if (month <= 12)
	{
		if (day > 31)
		{
			month++; 
			day = day -31 + 1;
		}
	}
	if (month > 12)
		change_data(year, month, day);
	if (day > 31)
		change_data(year, month,day);
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			change_data(year, month, day);
	}
	if (month == 2)
		if (day > 28)
			change_data(year,month,day);
}

class Data
{
	private:
	 int year_;
	 int month_;//1 ~ 12
	 int day_;//1 ~ 31

	public:
	 void setData(int year, int month, int data)
	 {
		 year_ = year;
		 month_ = month;
		 day_ = data;
		 change_data(year_,month_,day_);
	 }
	 void AddDay(int inc)
	 {
		 day_ += inc;
		 change_data(year_,month_,day_);
	 }
	 void AddMonth(int inc)
	 {
		 month_ +=inc;
		 change_data(year_,month_,day_);
	 }
	 void AddYear(int inc)
	 {
		 year_+=inc;
	 }
	 void showData()
	 {
		 cout << "year: "<<year_;
		 cout <<"  month: "<< month_;
		 cout << "  day: :"<<day_ << endl;
	 }
};

int main()
{
	Data data;
	int day;
	int year;
	int month;
	cout<<"<input>\nyear, month, day"<<endl;
	cin >>year>>month>>day;
	data.setData(year,month,day);
	data.showData();
	cout<<"add day:";
	cin>>day;
	data.AddDay(day);
	data.showData();
	cout<<"add month:";
	cin>>month;
	data.AddMonth(month);
	data.showData();



}
