#include <string.h>
#include "MyTime.h"
#include "ValueOutOfRangeException.h"


using namespace std;

MyTime:: MyTime(){
	setTime(0, 0, 0);
}

MyTime::MyTime(int hour, int minute, int second){
	setTime(hour, minute, second);
}

void MyTime:: setTime(int hour, int minute, int second){
	setHour(hour);
	setMinute(minute);
	setSecond(second);	
}

int MyTime::getHour(){
	return hour;
}

int MyTime::getMinute(){
	return minute;
}

int MyTime::getSecond(){
	return second;
}

//what if the parameters do not satisfy the conditions, should we equate it with 0?
void MyTime::setHour(int hour){
	if (hour>=0 && hour <=23){
			this->hour=hour;
	}
	else{
		throw ValueOutOfRangeException("Hour out of range!");
	}
}

void MyTime::setMinute(int minute){
	if (minute >=0 && minute <=59){
		this->minute=minute;
	}
	else{
		throw ValueOutOfRangeException("Minute out of range!");
	}
}

void MyTime::setSecond(int second){
	if (second >=0 && second<=59){
		this->second=second;
	}	
	else{
		throw ValueOutOfRangeException("Second out of range!");
	}
}

void MyTime::toString(){
	cout<< hour << " : " << minute << " : " << second;	
}


MyTime MyTime::nextSecond(){
	MyTime t1;
	if (this->second==59){
		throw ValueOutOfRangeException("");		
	}else{
		t1.setTime(this->hour, this->minute, ++this->second); 
		return t1;
	}
	
}

MyTime MyTime::nextMinute(){
	MyTime t1;
	
	if (this->minute==59){
		throw ValueOutOfRangeException("");	
		
	}else{
		t1.setTime(this->hour, ++this->minute, this->second);
		return t1;
	}
	
}

MyTime MyTime::nextHour(){
	MyTime t1;
	
	if (this->hour==23){
		throw ValueOutOfRangeException("");
	}else{
		t1.setTime(++this->hour, this->minute, this->second);
		return t1;
	}
	
}

MyTime MyTime::previousSecond(){
	MyTime t1;
	if (this->second==0){
		throw ValueOutOfRangeException("");	
	}else{
		t1.setTime(this->hour, this->minute, --this->second); 
		return t1;	
	}

}

MyTime MyTime::previousMinute(){
	MyTime t1;
	
	if (this->minute==0){
		throw ValueOutOfRangeException("");	
		
	}else{
		t1.setTime(this->hour, --this->minute, this->second);
		return t1;
	}
	
}

MyTime MyTime::previousHour(){
	MyTime t1;
	
	if (this->hour==0){
		throw ValueOutOfRangeException("");
	}else{
		t1.setTime(--this->hour, this->minute, this->second);
		return t1;
	}

}

