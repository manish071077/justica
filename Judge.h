#pragma once

#include <iostream>

class Judge
{
public:
	Judge();
	~Judge();
private:
	unsigned int m_judge_id;
	char* m_judge_name[50];
};