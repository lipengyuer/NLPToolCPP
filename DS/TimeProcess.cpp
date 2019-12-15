
#include<ctime>
#include<iostream>
using namespace std;
class TimeProcess{

public:
    static int nowTimeMS();
};

int TimeProcess::nowTimeMS(){
    return 1000*clock()/CLOCKS_PER_SEC;

}
