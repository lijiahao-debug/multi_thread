#include <iostream>
#include <thread>

using namespace std;

int main(){
    auto foo = [](const int &i, char* buff){
        cout << i << endl;
        cout << buff << endl;
    };
    int i = 10;
    char buff[] = "hello thread";
    thread t1(foo, i, buff);
    t1.join();
    return 0;
}