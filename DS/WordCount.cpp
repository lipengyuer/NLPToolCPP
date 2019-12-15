//统计语料中的字的频数
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int findIndex(map<string, int> aMap, string aStr){
    map<string, int>::iterator myiter;
    myiter = aMap.find(aStr);
    if(myiter==aMap.end()){
        return -1;
    }else{
        return 0;//(unsigned)myiter.second;
    }

}
int main(){
    string data;
    map<string, int> word_freq;
    cout << "asdasd" <<endl;
    ifstream fheadle;
    fheadle.open("C:/Users/Administrator/Desktop/想法.txt");
    fheadle >> data;
    cout << data.length() <<endl;
    string ngram;
    int aIndex;
    for(int i=1; i<data.length(); i++){
        ngram = data.substr(i-1,i);
        cout << ngram <<endl;
        if(word_freq.count(ngram)==0){
             word_freq[ngram] = 1;
        }else{

            //aIndex = findIndex(word_freq, ngram);
            cout <<word_freq[ngram]<<endl;
            //word_freq[aIndex] = word_freq[aIndex] + 1;
        }

    }
    //map<string, int>::iterator myiter = word_freq.begin();
   // for(;myiter!=word_freq.end(); myiter++){
   //     cout << myiter->first<<myiter->second <<endl;
    //}
}
