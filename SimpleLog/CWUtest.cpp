
#include <iostream>
#include <string>
#include <assert.h>
#include "CWUtest.h"
 

namespace cw
{

	CWUtest::CWUtest() :m_fail(0), m_allCases(0)
	{

	}

	CWUtest::~CWUtest()
	{

	}

	void CWUtest::init(const std::string& testName)
	{
		
		m_testName = testName;

		std::cout << m_testName << std::endl;

	}

	void CWUtest::test(const std::string& msg, const bool condition)
	{
		if (!condition)
		{
			m_fail++;
			//counting
		}
		else
		{

			m_allCases++;
			//coun test cases

			std::cout << msg << " : " << condition << std::endl;

		}

	}


	void CWUtest::report() const
	{

		std::cout << "--------x" << m_testName << "x--------\n";
		std::cout << "all cases :" << m_allCases << std::endl;
		std::cout << "Fail : " << m_fail << std::endl;;



	}

}