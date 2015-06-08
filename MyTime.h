#include <string.h>
#include <iostream>
using namespace std;

#ifndef MYTIME_H
#define MYTIME_H

class MyTime{
	
	private:
		int hour;
		int minute;
		int second;
		
	public:
		MyTime();
		MyTime(int hour, int minute, int second);
		void setTime(int hour, int minute, int second);
		int getHour();
		int getMinute();
		int getSecond();
		void setHour(int hour);
		void setMinute(int minute);
		void setSecond(int second);
		void toString();
		MyTime nextSecond();
		MyTime nextMinute();
		MyTime nextHour();
		MyTime previousSecond();
		MyTime previousMinute();
		MyTime previousHour();
};

#endif
