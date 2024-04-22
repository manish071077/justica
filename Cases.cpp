#include "Cases.h"


unsigned int Cases::m_cnt = 0;

Cases::Cases()
{
	std::cout << "Cases classes contructor\n";
	this->m_case_id = ++m_cnt;
	this->m_case_status = 3;
	std::cout << "Enter case type, priority : ";
	std::cin >> m_case_type >> m_case_priority;
	int n, m;
	std::cout << "Enter number of petitioner, respondent : ";
	std::cin >> n >> m;
	std::cin.ignore();
	this->m_petitioner = std::vector<Accused>(n);
	this->m_respondent = std::vector<Accused>(m);
	m_time.push_back(time(0));
}

Cases::~Cases()
{
	std::cout << "Cases classes destructor\n";
}

void Cases::input()
{
	std::cout << "input function\n";
}

void Cases::display() const
{
	std::cout << "-------------- Case detail -----------------\n";
	std::cout << "Case id : " << m_case_id << "\n";
	std::cout << "Case status : " << m_case_status << "\n";
	std::cout << "Case type and priority : " << m_case_type << " " << m_case_priority << "\n";
	std::cout << "Petitioner are : \n";
	for (const Accused& e : m_petitioner)
	{
		e.display();
	}
	std::cout << "respondent are : \n";
	for (const Accused& e : m_respondent)
	{
		e.display();
	}
	std::cout << "Judge is : ";
	m_judge.display();
	std::cout << "layers are : \n";
	m_forl.display();
	m_againstl.display();

	char buffer[32];
	ctime_s(buffer, 26, &m_time[0]);
	std::cout << "Creation time " << buffer << "\n";

}