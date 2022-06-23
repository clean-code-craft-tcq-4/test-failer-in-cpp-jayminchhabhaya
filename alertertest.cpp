#include <iostream>
#include"alertertest.hpp"
namespace AlertTest
{
	int networkAlertTest(float celcius) {
		std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
		// Return 200 for ok
		// Return 500 for not-ok
		return 200;
	}
}