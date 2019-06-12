#include "Log.h"
#include "Log.h"

const string CreateLog::m_sFileName = "Error.txt";
CreateLog* CreateLog::m_pThis = NULL;
ofstream CreateLog::m_Logfile;

CreateLog::CreateLog()
{

}
CreateLog* CreateLog::GetLogger() {
	if (m_pThis == NULL) {
		m_pThis = new CreateLog();
		m_Logfile.open(m_sFileName.c_str(), ios::out | ios::app);
	}
	return m_pThis;
}

void CreateLog::Log(const char* format, ...)
{
	char* sMessage = NULL;
	int nLength = 0;
	va_list args;
	va_start(args, format);
	//  Return the number of characters in the string referenced the list of arguments.
	// _vscprintf doesn't count terminating '\0' (that's why +1)
	nLength = _vscprintf(format, args) + 1;
	sMessage = new char[nLength];
	vsprintf_s(sMessage, nLength, format, args);
	//vsprintf(sMessage, format, args);
	//m_Logfile << Util::CurrentDateTime() << ":\t";
	m_Logfile << sMessage << "\n";
	va_end(args);

	delete[] sMessage;

}

void CreateLog::Log(const string & sMessage)
{
	//m_Logfile << Util::CurrentDateTime() << ":\t";
	m_Logfile << sMessage << "\n";
}

CreateLog& CreateLog::operator<<(const string & sMessage)
{
	//m_Logfile << "\n" << Util::CurrentDateTime() << ":\t";
	m_Logfile << sMessage << "\n";
	return *this;
}

