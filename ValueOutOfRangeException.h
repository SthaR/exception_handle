#include <stdexcept>
using namespace std;

class ValueOutOfRangeException: public runtime_error{
	public:
		ValueOutOfRangeException(string msg):runtime_error(msg){};
		//ValueOutOfRangeException(){}; (Couldn't figure out why this didn't work) Throws error: no matching function for call to std:::runtime_error::runtime_error()
};
