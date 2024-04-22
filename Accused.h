#pragma once

#include <iostream>
#include <string>

class Accused
{
public:
	Accused();
	~Accused();
	void display();
private:
	unsigned int m_accused_id;
	const char* m_accused_name;
};