#include <iostream>
#include <thread>

using namespace std;

class Test{
public:
    int &mi;
    Test(int& i): mi(i){

    }
    void operator()(){
        cout << "Test thread" << endl;
        cout << "Test thread mi1=" << mi << endl;
        cout << "Test thread mi2=" << mi << endl;
    }
};

int main(){
    int i = 10;
    Test test(i);
    thread t1(test);
    t1.join();
    // detach will cause bug
    // t1.detach();
    cout << "main thread end" << endl;

    auto fun = []{
        cout << "lambada thread" << endl;
    };

    thread t2(fun);
    t2.join();
    return 0;
}