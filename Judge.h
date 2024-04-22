#pragma once

#include <iostream>
#include <string>

class Judge
{
public:
	Judge();
	~Judge();
	void display() const;
	static int m_cnt;
private:
	unsigned int m_judge_id;
	char m_judge_name[50];
};