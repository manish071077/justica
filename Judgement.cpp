#include "Judgement.h"

Judgement::Judgement(Judge judge, std::vector<Accused>& arr, Lawyer lawyer_for, Lawyer lawyer_against)
{
	std::cout << "Jugement constructor\n";
	this->m_judge = judge;
	this->m_accused = arr;
	this->m_for = lawyer_for;
	this->m_against = lawyer_against;
}

Judgement::~Judgement()
{
	std::cout << "Jugement destrucotr\n";
}
