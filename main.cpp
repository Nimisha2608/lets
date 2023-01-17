//recursive mutex
#include <bits/stdc++.h>
#include <mutex>
#include <thread>
using namespace std;
//exa 1 with recursion
recursive_mutex m;
int buff=0;
void recursion(char c,int loopfor){
    if(loopfor<0){
        return;
    }
    m.lock();
    cout<<"locked by threadid: "<<c<<" "<<buff++<<endl;
    recursion(c,--loopfor);
    m.unlock();
    cout<<"unlocked by threadid"<<c<<endl;
}
int main(){
    thread t1(recursion,'1',2);
    thread t2(recursion,'2',2);
    t1.join();
    t2.join();
    return 0;
}
//how it is going in memory for that see the image
//exa 2 with for loop
/*
 for(int i=0;i<5;i++)
{
 m.lock();
cout<<"locked"<<i<<endl;
}
 for(int i=0;i<5;i++)
{
 m.unlock();
cout<<"unlocked"<<i<<endl;
}
 *
 *
 * */
