default: atomic_flag

atomic: atomic.cpp
	g++ -g -std=c++14 -Wall -o atomic atomic.cpp 
atomic_flag: atomic_flag.cpp
	g++ -g -std=c++14 -Wall -o atomic_flag atomic_flag.cpp -lpthread
#	g++ -std=c++14 -o atomic_flag atomic_flag.o -lpthread
regex: regex.cpp
	g++ -g -std=c++14 -Wall -o regex regex.cpp
clean:	
	rm -f regex atomic atomic_flag