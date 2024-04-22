#pragma once

#include <iostream>
#include <vector>

#include "Judge.h"
#include "Accused.h"
#include "Lawyer.h"

class Judgement
{
public:
	Judgement(Judge, std::vector<Accused>& arr, Lawyer, Lawyer);
	~Judgement();
private:
	Judge m_judge;
	std::vector<Accused> m_accused;
	Lawyer m_for, m_against;
};