#include "Judge.h"

int Judge::m_cnt = 0;

Judge::Judge()
{
	std::cout << "Enter Judge name : ";
	std::cin.getline(this->m_judge_name, 50);
	this->m_judge_id = ++m_cnt;
}

Judge::~Judge()
{
	// std::cout << "judge destrucotr\n";
}

void Judge::display() const
{
	std::cout << m_judge_id << " " << m_judge_name << "\n";
}
