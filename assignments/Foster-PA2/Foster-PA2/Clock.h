#pragma once
#include <chrono>

class Clock
{
public:
	Clock()
	{
		Reset();
	}
	void Reset()
	{
		m_Start = std::chrono::system_clock::now();
		m_End = std::chrono::system_clock::now();
	}
	float Elapsed()
	{
		m_End = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsed = m_End - m_Start;
		m_Start = m_End;
		return elapsed.count();
	}
private:
	std::chrono::system_clock::time_point m_Start;
	std::chrono::system_clock::time_point m_End;
};

