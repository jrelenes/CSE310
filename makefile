
encode: encode.cpp
	g++ -std=c++11 encode.cpp -o encode   

decode: decode.cpp
	g++ -std=c++11 decode.cpp -o decode 


clean:
	$(RM) encode
	$(RM) decode
