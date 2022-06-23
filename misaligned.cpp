#include <iostream>
#include <assert.h>
#include<string>
#include "misaligned.hpp"
using namespace std;

colorInfo colorInfoobject2;
void colorInfo::GetColorCodeManualRef(){
    int PNumber = 1;
    for(int i_majorClrCount = 0; i_majorClrCount < numberOfMajor; i_majorClrCount++){
        for(int j_minorClrCount = 0; j_minorClrCount < numberOfMinor; j_minorClrCount++){
            PairNumber.push_back(PNumber);
            MajorColor.push_back(MajorColorNames[i_majorClrCount]);
            MinorColor.push_back(MinorColorNames[j_minorClrCount]);
            PNumber++;
        }
    }
}
void fillcolorInfoobject(int pairNumber,const char* majorColor,const char* minorColor){
	colorInfoobject2.PairNumber.push_back(pairNumber);
    colorInfoobject2.MajorColor.push_back(majorColor);
    colorInfoobject2.MinorColor.push_back(minorColor);
}
int colorInfo::printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < numberOfMajor; i++) {
        for(j = 0; j < numberOfMinor; j++) {
            std::cout << i * numberOfMinor + j << " | " << MajorColorNames[i] << " | " << MinorColorNames[i] << "\n";
			fillcolorInfoobject((i * numberOfMinor + j),MajorColorNames[i],MinorColorNames[i]);
        }
    }
    return i * j;
}
void testassert(const colorInfo &obj1,const colorInfo &obj2){
	for(int i_ClrCount=0;i_ClrCount<25;i_ClrCount++){
        assert(obj1.PairNumber[i_ClrCount] == obj2.PairNumber[i_ClrCount]);
        assert(obj1.MajorColor[i_ClrCount] == obj2.MajorColor[i_ClrCount]);
        assert(obj1.MinorColor[i_ClrCount] == obj2.MinorColor[i_ClrCount]);
    }
}
int main() {
    colorInfo colorInfoobject1;
	colorInfoobject1.GetColorCodeManualRef();
    int result = colorInfoobject1.printColorMap();
    assert(result == 25);
	testassert(colorInfoobject1,colorInfoobject2);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
