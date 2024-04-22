#pragma once

#include <iostream>
#include <string>

class Accused
{
public:
	Accused();
	~Accused();
	void display() const;
private:
	unsigned int m_accused_id;
	char m_accused_name[50];
	static int m_cnt;
};