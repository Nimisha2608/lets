//timed mutex
/*
Timed Mutex In C++ Threading (std::timed_mutex)"
We have learned Mutex, Race Condition, Critical Section in previous videos.
And few points to remember about timed mutex is as follows:
0. std::timed_mutex is blocked till timeout_time or the lock is acquired and returns true if success
   otherwise false.
1. Member Function:
   a. lock
   b. try_lock
   c. try_lock_for    ---\ These two functions makes it different from mutex.
   d. try_lock_until  ---/
   e. unlock

EXAMPLE: try_lock_for();
Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
On successful lock acquisition returns true, otherwise returns false.
*/
#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;
int amount=0;
timed_mutex m;
void increment(int i){
    auto now=chrono::steady_clock::now();
    if(m.try_lock_until(now+std::chrono::seconds(2))){
        ++amount;
        this_thread::sleep_for(chrono::seconds(2));
        cout<<"thraed"<<i<<"enterd"<<endl;
        m.unlock();
    }else{
        cout<<"thread"<<i<<"could not enterd"<<endl;
    }
    /*
    if(m.try_lock_for(std::chrono::seconds(2))){
        ++amount;
        this_thread::sleep_for(chrono::seconds(2));
        cout<<"thraed"<<i<<"enterd"<<endl;
        m.unlock();
    }else{
        cout<<"thread"<<i<<"could not enterd"<<endl;
    }
    */
}
int main(){
    int tty,tt;
    cin>>tty>>tt;
    thread t1(increment,tty);
    thread t2(increment,tt);
    t1.join();
    t2.join();
    cout<<amount<<endl;
}
