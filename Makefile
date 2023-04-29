all:	
	g++ -std=c++11 main.cpp project2.h kmp.cpp bmh.cpp brute.cpp -o project2

clean:
	/bin/rm -rf *.o project2