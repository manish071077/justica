#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>

#include "Accused.h"
#include "Judge.h"
#include "Lawyer.h"

struct Time
{
	int year, month, day, hour, minute, second;
	Time(int, int, int, int, int, int);
	Time();
};

class Cases
{
public:
	Cases();
	~Cases();
	void inputCase();

private:
	unsigned int m_case_number;
	unsigned int m_case_type;
	unsigned int m_case_status;
	unsigned int m_case_priority;
	std::vector<Time> m_time;
	std::vector<Accused> m_for, m_against;
	Judge judge;
	Lawyer m_forl, m_againstl;
	char verdict[100];
	static int number;
};