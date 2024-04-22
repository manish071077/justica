#pragma once

#include <iostream>

class Judgement
{
public:
	Judgement();
	~Judgement();
	void display() const;
private:
	unsigned int m_judgement_id;
	char verdict[200];
	static unsigned int m_cnt;
};