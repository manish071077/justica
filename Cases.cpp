#include "Cases.h"


int Cases::number = 0;

Cases::Cases()
{
	std::cout << "Cases classes contructor\n";
	number++;
	this->m_case_number = number;
	std::cout << "Enter case type : ";
	std::cin >> this->m_case_type;
	this->m_case_status = 3;
	std::cout << "Enter case priority : ";
	std::cin >> this->m_case_priority;
	unsigned int y, mo, d, h, m, s;
	std::cout << "Enter time in YYYY:MM:DD:HH:MM:SS format seprated by space : ";
	std::cin >> y >> mo >> d >> h >> m >> s;
	Time temp(y, mo, d, h, m, s);
	this->m_time.push_back(temp);
	int n;
	std::cout << "Enter number of people in case : ";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		Accused temp;
		this->m_for.push_back(temp);
	}


}

Cases::~Cases()
{
	std::cout << "Cases classes destructor\n";
}

void Cases::inputCase()
{

}

Time::Time(int y, int mo, int d, int h, int m, int s)
{
	this->year = y;
	this->month = mo;
	this->day = d;
	this->hour = h;
	this->minute = m;
	this->second = s;
}

Time::Time()
{
	this->year = 0;
	this->month = 0;
	this->day = 0;
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}