
seaice: seaice.cpp seaice.h
	g++ -std=c++11 -pthread seaice.cpp -o seaice




clean:
	$(RM) seaice.cpp
	$(RM) seaice.h
	$(RM) seaice
	