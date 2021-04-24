#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex m_mutex;

class Singleton{
private:
    static Singleton * m_instance;
    const static int num = 10;
    Singleton(){}
public:
    static Singleton* getInstance(){
        if(m_instance == nullptr){
            unique_lock<mutex> m_lock(m_mutex);
            if(m_instance == nullptr){
                m_instance = new Singleton();
            }
        }
        return m_instance;
    }
};

Singleton* Singleton::m_instance = nullptr;

void foo(){
    Singleton* s = Singleton::getInstance();
    cout << s << "      " << endl;
}

int main(){
    vector<thread> threads;
    for(int i = 0; i < 10; ++i){
        threads.push_back(thread(foo));
    }
    for(int i = 0; i < 10; ++i){
        threads[i].join();
    }
    return 0;
}