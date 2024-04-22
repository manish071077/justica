#include "Judgement.h"

unsigned int Judgement::m_cnt = 0;

Judgement::Judgement()
{
	std::cout << "Enter case verdict : ";
	std::cin.getline(verdict, 200);
	this->m_judgement_id = ++m_cnt;
}

Judgement::~Judgement()
{
	// std::cout << "Jugement destrucotr\n";
}

void Judgement::display() const
{
	std::cout << m_judgement_id << " " << verdict << "\n";
}