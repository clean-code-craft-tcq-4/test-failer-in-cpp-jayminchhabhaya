#include <iostream>
#include <assert.h>

#define AlertTest TRUE //TRUE for networkAlertTest and FALSE for networkAlertStub

int alertFailureCount = 0;
int networkAlertTest(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
	int returnCode;
	if(AlertTest == TRUE){
		returnCode = networkAlertTest(celcius);
	}
	else{
	    returnCode = networkAlertStub(celcius);	
	}
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
	ssert(alertFailureCount == 0);
    alertInCelcius(303.6);
	ssert(alertFailureCount == 1);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}

