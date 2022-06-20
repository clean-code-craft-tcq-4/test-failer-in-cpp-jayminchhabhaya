class colorInfo
{
public:
  int numberOfMajor;
  int numberOfMinor;
  vector<int>PairNumber;
  vector<std::string>MajorColor;
  vector<std::string>MinorColor;
  colorInfo()
  {
	  numberOfMajor = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
	  numberOfMinor = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);
  }
  ~colorInfo()
  {}
  int printColorMap();
  void GetColorCodeManualRef();
};