
storm: storm.cpp defn.h
	g++ -std=c++11 storm.cpp -o storm




clean:
	$(RM) storm
	