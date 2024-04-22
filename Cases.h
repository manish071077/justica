#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <ctime>

#include "Accused.h"
#include "Judge.h"
#include "Lawyer.h"


class Cases
{
public:
	Cases();
	~Cases();
	void input();
	void display() const;

private:
	unsigned int m_case_id;
	unsigned int m_case_type;
	unsigned int m_case_status;
	unsigned int m_case_priority;
	std::vector<time_t> m_time;
	std::vector<Accused> m_petitioner, m_respondent;
	Judge m_judge;
	Lawyer m_forl, m_againstl;
	
	static unsigned int m_cnt;
};