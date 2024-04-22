#pragma once

#include <string>
#include <iostream>

class Lawyer
{
public:
	Lawyer();
	~Lawyer();
	void display() const;
private:
	unsigned int m_lawyer_id;
	char m_lawyer_name[50];
	static int m_cnt;
};