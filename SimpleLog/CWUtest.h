#pragma once

#include <assert.h> 

#define REQUIRED(stm) assert(stm)
#define PROMISED(stm) assert(stm)

namespace cw
{
	class CWUtest
	{

	public:
		CWUtest();
		~CWUtest();

		void init(const std::string& testName);
		void test(const std::string& msg, const bool condition);
		void report() const;


	private:
		std::string m_testName;
		unsigned int m_fail;
		unsigned int m_allCases;

	};






}