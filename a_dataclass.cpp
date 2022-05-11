#include<iostream>

class Data
{
	int year_;
	int month_;
	int day_;

	public:
	void set_data(int year, int month, int data);
	void add_day(int inc);
	void add_month(int inc);
	void add_year(int inc);

	Data(int year,int month,int day)
	{
		year_ = year;
		month_= month;
		day_=day;
	}
	int get_current_month_to_total_day(int year, int month);
	void show_data();
};

void Data::set_data(int year,int month,int day)
{
	year_ = year;
	month_= month;
	day_=day;
}

int Data::get_current_month_to_total_day(int year, int month)
{
	static int month_day[12] = {31, 28,31,30,31,30,31,31,30,31,30,31};
	if (month!=2)
		return(month_day[month-1]);
	else if(year % 4 == 0 && year % 100 != 0)
		return(29);
	else
		return(28);
}

void Data::add_day(int inc)
{
	while (true)
	{
		int current_month_total_days = get_current_month_to_total_day(year_, month_);
		if (day_ +inc <=current_month_total_days)
		{
			day_+=inc;
			return;
		}
		else
		{//다음달로 넘어간다.
			inc-=(current_month_total_days -day_+1);
			day_ =1;
			add_month(1);
		}
	}
}

void Data::add_month(int inc)
{
	add_year((inc + month_ -1) /12);
	month_ = month_ + inc % 12;
	month_ = (month_ == 12 ? 12 :month_ % 12);
}

void	Data::add_year(int inc)
{
	year_ +=inc;
}

void	Data::show_data()
{
	std::cout << "todayis::" << year_ << " year " << month_<<" month "<<day_<<" day "<<std::endl;
}

int main()
{
	Data day(2000,3,25);
	day.show_data();
	day.add_day(30);
	day.show_data();
	day.add_day(2000);
	day.show_data();
}
