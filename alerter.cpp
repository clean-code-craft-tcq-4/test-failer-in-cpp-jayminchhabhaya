#include <iostream>
#include <assert.h>
#include"alertertest.hpp"
#include"alerterstub.hpp"

using namespace AlertStub;
using namespace AlertTest;

int alertFailureCount = 0;

void alertInCelcius(float farenheit,int (*funcptr)(float)) {
    float celcius = (farenheit - 32) * 5 / 9;
	int returnCode = funcptr(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5,networkAlertStub);
    assert(alertFailureCount == 0);
    alertInCelcius(303.6,networkAlertTest);
    assert(alertFailureCount == 1);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}

