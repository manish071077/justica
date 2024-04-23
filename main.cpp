#include <iostream>
#include <vector>
#include <ctime>
#include <queue>
#include <algorithm>

#include "Cases.h"
#include "Accused.h"
#include "Judge.h"
#include "Lawyer.h"
#include "Judgement.h"

class cmp
{
public:
	bool operator()(const Cases& a, const Cases& b)
	{
		if (a.m_case_priority == b.m_case_priority) {
			if (a.m_case_type == b.m_case_type) {
				if (a.m_case_heard == b.m_case_heard) {
					return a.m_time_req > b.m_time_req;
				}
				return a.m_case_heard < b.m_case_heard;
			}
			return a.m_case_type > b.m_case_type;
		}
		return a.m_case_priority > b.m_case_priority;
	}
};

int main(int argc, char* argv[])
{
	std::cout << "working\n";
	int n = 3;
	std::vector<Cases> arr(n);
	std::cout << "Enter " << n << " times for simulation : ";
	std::vector<Cases> vec;
	std::priority_queue<Cases, std::vector<Cases>, cmp> pq;
	for (int i = 0; i < n; i++) {
		arr[i].display();
		pq.push(arr[i]);
	}
	int day = 1;
	int complete = 0;
	int remaning = 21600;
	while (!pq.empty()) {
		arr.clear();
		while (remaning > 0 && !pq.empty()) {
			Cases temp = pq.top();
			pq.pop();
			if (remaning >= 3600 && (temp.m_time_req - 3600) >= 0) {
				temp.m_time_req -= 3600;
				remaning -= 3600;
			}
			else if (remaning-temp.m_time_req >= 0) {
				remaning -= temp.m_time_req;
				temp.m_time_req = 0;
			}
			else {
				temp.m_time_req -= remaning;
				remaning = 0;
			}
			temp.m_case_heard++;
			arr.push_back(temp);
		}
		if (remaning <= 0) {
			day++;
			remaning += 216000;
		}
		
		while (!pq.empty()) {
			Cases temp = pq.top();
			if (temp.m_case_priority > 0)
				temp.m_case_priority--;
			arr.push_back(temp);
		}
		for (const Cases& e : arr) {
			if (e.m_time_req <= 0) {
				complete++;
				vec.push_back(e);
			}
			else {
				pq.push(e);
			}
				
		}
	}
	for (const Cases& e : vec) {
		e.display();
	}

	return 0;
}