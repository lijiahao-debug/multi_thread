#include <iostream>
#include <unistd.h>

using namespace std;

// thread header
#include <thread>

void hello_thread(){
    cout << "hello thread" << endl;
}

int main(){
    //create a thread and execute this thread obj
    thread t1(hello_thread); 
    //block main thread
    cout << t1.joinable() << endl;
    t1.join();
    sleep(1);
    cout << t1.joinable() << endl;
    cout << "main thread t1" << endl;
    thread t2(hello_thread);
    t2.detach();
    cout << "main thread t2" << endl; 
    return 0;
}