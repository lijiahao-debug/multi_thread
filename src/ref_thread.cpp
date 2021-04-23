#include <iostream>
#include <thread>

using namespace std;
class A{
public:
    int m_i;
    A(int i): m_i(i){
        cout << "A constructor" << endl;
    }
    A(const A& a):m_i(a.m_i){
        cout << "A copy constructor" << endl;
    }
    ~A(){
        cout << "deconstructor" << endl;
    }
};
void test(A & a){
    cout << "test thread " << this_thread::get_id() << endl;
    cout << "test a.m_i=" << a.m_i << endl;
    a.m_i = 100;
}

int main(){
    cout << "main" << this_thread::get_id() << endl;
    A a(10);
    thread t1(test, ref(a));
    t1.join();
    cout << "test a.m_i=" << a.m_i << endl;
    cout << "main end" << endl;
    return 0;
}