#include "Accused.h"

Accused::Accused()
{
	std::cout << "Enter accused id and name";
	unsigned int aid;
	std::string aname;
	std::cin >> aid;
	std::cin.ignore();
	std::getline(std::cin, aname);
	this->m_accused_id = aid;
	this->m_accused_name = aname.c_str();
}

Accused::~Accused()
{
}

void Accused::display()
{
	std::cout << m_accused_id << " " << m_accused_name << "\n";
}
