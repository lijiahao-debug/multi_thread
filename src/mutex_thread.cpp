#include <iostream>
#include <thread>
#include <list>
#include <mutex>

using namespace std;

class Msg{
private:
    list<int> m_msg;
    mutex m_mutex;
public:
    void recvMsg(){
        for(int i = 0; i < 10000; ++i){
            {
                lock_guard<mutex> gard(m_mutex);
                m_msg.push_back(i);
            }
            cout << "receive a msg" << endl;
        }
    }    
    void outMsg(){
        for(int i = 0; i < 30000; i++){
            m_mutex.lock();
            if(!m_msg.empty()){
                int cmd = m_msg.front();
                m_msg.pop_front();
                m_mutex.unlock();
                cout << "handle a command " << cmd << endl;
            }else{
                m_mutex.unlock();
            }
        }
    }
};

int main(){
    Msg msg;
    thread t1(&Msg::recvMsg, &msg);
    thread t2(&Msg::outMsg, &msg);
    t1.join();
    t2.join();
    return 0;
}