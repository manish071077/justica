#include "Lawyer.h"

int Lawyer::m_cnt = 0;

Lawyer::Lawyer()
{
	std::cout << "Enter Lawyer name : ";
	std::cin.getline(this->m_lawyer_name, 50);
	this->m_lawyer_id = ++m_cnt;
}

Lawyer::~Lawyer()
{
	// std::cout << "Layer Destrucotor\n";
}

void Lawyer::display() const
{
	std::cout << this->m_lawyer_id << " " << this->m_lawyer_name << "\n";
}
