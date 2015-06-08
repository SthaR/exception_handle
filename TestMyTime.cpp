#include <iostream>
#include "MyTime.h"
#include "ValueOutOfRangeException.h"

using namespace std;


MyTime nextSecEH(MyTime t);
MyTime nextMinEH(MyTime t);
MyTime nextHrEH(MyTime t);
MyTime previousSecEH(MyTime t);
MyTime previousMinEH(MyTime t);
MyTime previousHrEH(MyTime t);
void getUserValue(string valueFor, MyTime &t1);

int main(){
	MyTime t(13, 59, 59), t1;
	int hr, min, sec;
	bool exception;
	
	cout << "Trying out constructor with parameters: ";
	t.toString();
	
	cout << "\n\n";
	
	//Getting hour, minute and second from the user
	getUserValue("hour", t1);
	getUserValue("minute", t1);
	getUserValue("second", t1);

	cout << "\n\nCurrent time: \n";
	t1.toString();
	
	cout << "\n\n";
	
	t1=nextSecEH(t1);
	cout << "Next Second: \n";
	t1.toString();
	cout << "\n\n";
	
	t1=nextMinEH(t1);
	cout << "Next Minute: \n";
	t1.toString();
	cout << "\n\n";
	
	t1=nextHrEH(t1);
	cout << "Next Hour: \n";
	t1.toString();	
	cout << "\n\n";	

	t1=previousSecEH(t1);
	cout << "Previous Second: \n";
	t1.toString();
	cout << "\n\n";
	
	t1=previousMinEH(t1);
	cout << "Previous Minute: \n";
	t1.toString();
	cout << "\n\n";	

	t1=previousHrEH(t1);
	cout << "Previous Hour: \n";
	t1.toString();
}


MyTime nextSecEH(MyTime t){
	try{
		t.nextSecond();
	}
	catch(ValueOutOfRangeException &nextMinuteException){
		t=nextMinEH(t);
		t.setSecond(0);
	}
	return t;
}

MyTime nextMinEH(MyTime t){
	try{
		t.nextMinute();
	}
	catch(ValueOutOfRangeException &nextMinuteException){
		t=nextHrEH(t);
		t.setMinute(0);
	}
	return t;
}

MyTime nextHrEH(MyTime t){
	try{
		t.nextHour();
	}
	catch(ValueOutOfRangeException &nextHourException){
		t.setHour(0);	
	}
	return t;
}

MyTime previousSecEH(MyTime t){
	try{
		t.previousSecond();
	}
	catch(ValueOutOfRangeException &previousSecondException){ //why this parameter? parameter compulsory? only reference?
		t=previousMinEH(t);
		t.setSecond(59);
	}
	return t;
}

MyTime previousMinEH(MyTime t){
	try{
		t.previousMinute();
	}
	catch(ValueOutOfRangeException &previousSecondException){ //why this parameter? parameter compulsory? only reference?
		t=previousHrEH(t);
		t.setMinute(59);
	}
	return t;
}

MyTime previousHrEH(MyTime t){
	try{
		t.previousHour();
	}
	catch(ValueOutOfRangeException &nextHourException){
		t.setHour(0);	
	}
	return t;
}

void getUserValue(string valueFor, MyTime &t1){
	bool exception;
	int val;
	do{ 
		exception=false;
		
		cout << "\nEnter " << valueFor << " : ";
		cin >> val;
								
		try{	
			if (valueFor=="hour")		
				t1.setHour(val);	
			else if (valueFor=="minute")			
				t1.setMinute(val);
			else
				t1.setSecond(val);
		}
		catch (ValueOutOfRangeException &valueOutOfRange){ 
			exception=true;
			cout << "Exception occured: " << valueOutOfRange.what();
		}
	}while	(exception==true);
}
