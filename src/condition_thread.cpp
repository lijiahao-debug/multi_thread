#include <iostream>
#include <mutex>
#include <list>
#include <thread>

using namespace std;

class A{
private:
    list<int> m_msg;
    mutex m_mutex;
    condition_variable m_cond;
public:
    void recvMsg(){
        for(int i = 0; i < 10; ++i){
            cout << "receive a message: " << i << endl;
            unique_lock<mutex> recv_lock(m_mutex);
            m_msg.push_back(i);
            // recv_lock.unlock();
            m_cond.notify_one();
        }
    }
    void handleMsg(){
        while(true){
            unique_lock<mutex> handle_lock(m_mutex);
            m_cond.wait(handle_lock, [this]{
                return m_msg.empty();
            });
            int cmd = m_msg.front();
            m_msg.pop_front();
            handle_lock.unlock();
            cout << "handle a msg:" << cmd << endl;
        }
    }
};

int main(){
    A a;
    thread t1(&A::recvMsg, &a);
    thread t2(&A::handleMsg, &a);
    return 0;
}