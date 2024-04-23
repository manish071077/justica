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
	Cases* get();
	unsigned int m_case_id;
	unsigned int m_case_type;
	unsigned int m_case_status;
	unsigned int m_case_priority;  // 0 - 1000
	unsigned int m_case_heard;
	unsigned long m_time_req; // just for simulation reason
private:
	std::vector<time_t> m_time;
	std::vector<Accused> m_petitioner, m_respondent;
	Judge m_judge;
	Lawyer m_forl, m_againstl;
	
	static unsigned int m_cnt;
};