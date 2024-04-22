#include "Accused.h"

int Accused::m_cnt = 0;

Accused::Accused()
{
	std::cout << "Enter accused name : ";
	std::cin.getline(this->m_accused_name, 50);
	this->m_accused_id = ++m_cnt;
}

Accused::~Accused()
{
	// std::cout << "Accused Destructor\n";
}

void Accused::display() const
{
	std::cout << m_accused_id << " " << m_accused_name << "\n";
}
