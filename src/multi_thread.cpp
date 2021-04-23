#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>

using namespace std;

void foo(int num){
    cout << "foo num " << num << " pid = " << this_thread::get_id() << endl;
}


int main(){

    vector<thread> threads;
    for(int i = 0; i < 10; i++){
        threads.push_back(thread(foo, i));
    }
    sleep(1);    
    for(int i = 0; i < 10; i++){
         threads[i].join();
    }

    cout << "main end" << endl;
    return 0;
}