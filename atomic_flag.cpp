// using atomic_flag as a lock
#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <sstream>

using namespace std;

std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;
std::stringstream stream;

void append_thread_number(int x){
	while(lock_stream.test_and_set())
	{}
	stream << "Thread[" << x << "]\n";
	lock_stream.clear();
}

int main(){

	std::vector<std::thread> threads;
	for(int i = 0; i <=10; i++)
		threads.push_back( std::thread(append_thread_number, i) );
	for(auto &th: threads)
		th.join();

	std::cout<<stream.str();
	return 0;
}