 
 
#include <iostream>
#include <assert.h>
#include "CWUtest.h"
#include "Log.h"
using namespace std;
using namespace cw;

string writelog;

float calCircleArea(float r)
{
	float PI=3.14;
	assert(PI == 3.14);
	return PI* r* r;

}

float calSquareArea(float w)
{
	REQUIRED(w >= 0);
	REQUIRED(w < 100000);

	float area = 0.0f;
	 
	if (w > 0)
		area = w * w;
	PROMISED(area >= 0);


	return area;



}

int main(int argc, char* argv[])
{
	
	 
	 CWUtest ut;


	ut.test("calSquareArea(5)==25:", calSquareArea(5) == 25);
	ut.test("calSquareArea(0)==0:", calSquareArea(0) == 0);
	//ut.test("calSquareArea(-1)==0:", calSquareArea(-1) == 0);
	ut.report();


	//2pass
	//1 faile


	//cout<< endl <<"File: " << __FILE__ <<endl<< "Function: " << __FUNCTION__ << endl<< "Line:"  <<__LINE__;

	
	 

	string Info = "Information ";
	string Error = "Error ";
	string Warning = "warning";

	



	//print msg

	cout << endl << Info << endl;
	cout << Error << endl;
	cout << Warning << endl;



	cout << "Would you like to write to the log file? (1 for yes ,0 for no)";
	cin >> writelog;

	if (writelog == "0" || writelog == "1") {
		if (writelog == "0") {
			return 0;

		}
		else if (writelog == "1") {
			
			LOGGER->Log(" Info is:%s \n Error is:%s \n Warning is:%s ", Info.c_str(), Error.c_str(), Warning.c_str());
			//Can wtire in 2 type below vvvvv or upper^^^^^^^^^^^

			/*CreateLog::GetLogger()->Log(Info);
			CreateLog::GetLogger()->Log(Error);
			CreateLog::GetLogger()->Log(Warning);*/
		}
	}
	else {
		cout << "Invalid choice, please re-run and try again" << endl;
		return 0;
	}


	//write msg to log
	//CreateLog::GetLogger()->Log("message to be logged");
	
	//LOGGER->Log(" Message is:%s Number is:%d", error.c_str(), nNum);
	
	return 0;



}

 

 