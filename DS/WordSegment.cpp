#include<iostream>
#include <map>
#include<string>
#include<vector>
#include<ctime>
#include "DataStructures.h"
#include "TimeProcess.h"
using namespace std;
class MMSeg{
    protected:
        Dictionary dict;
        int maxLength = 10;
    public:
        void segment(string *text, vector<string> *words);//分词
        vector<string> segment(string *text);//分词
        bool containsKey(string *term);
        MMSeg();
        int getVocabSize();
};

MMSeg::MMSeg(){
    cout << "loading vocabulary " << endl;
    this->dict.loadVocab();
    cout << "finish loading vocabulary " << endl;
};

void MMSeg::segment(string *text, vector<string> *words){
   // int t1, t2, t3, t4;
  //  int tSum = 0;
   // t1 = TimeProcess::nowTimeMS();
    int index=0;
    bool ifWordHere;
    string tempStr;
    string candWord;
    int temMaxLength;
    bool flag;
   // int count = 0;
    while(index<text->length()){
        ifWordHere = false;
        if(index + maxLength > text->length()){
            temMaxLength = text->length() - index;
        }else{
            temMaxLength = maxLength;
            }
        for(int j=temMaxLength; j>0; j--){
            candWord = text->substr(index, j);
           // t3 = TimeProcess::nowTimeMS();
            flag = this->containsKey(&candWord);
           // t4 = TimeProcess::nowTimeMS();
           // count += 1;
           // tSum += t4-t3;
            if(flag){
                words->push_back(candWord);
                index += j;
                ifWordHere = true;
                //t4 = TimeProcess::nowTimeMS();
                break;
            }
        }
        if(!ifWordHere){
            words->push_back(candWord);
            index++;
          }
    }
   // t2 = TimeProcess::nowTimeMS();
   // cout <<text->length() <<" time cost in processing this document is " << t2-t1 << "ms " << " main" << tSum << " " << count << endl;
};



vector<string> MMSeg::segment(string *text){
    vector<string> words;
    //int t1, t2, t3, t4;
   // int tSum = 0;
   // t1 = TimeProcess::nowTimeMS();
    int index=0;
    bool ifWordHere;
    string tempStr;
    string candWord;
    int temMaxLength;
    bool flag;
    //int count = 0;
    while(index<text->length()){
        ifWordHere = false;
        if(index + maxLength > text->length()){
            temMaxLength = text->length() - index;
        }else{
            temMaxLength = maxLength;
            }
        for(int j=temMaxLength; j>0; j--){
            candWord = text->substr(index, j);
            //t3 = TimeProcess::nowTimeMS();
            flag = this->containsKey(&candWord);
            //t4 = TimeProcess::nowTimeMS();
           // count += 1;
           // tSum += t4-t3;
            if(flag){
                words.push_back(candWord);
                index += j;
                ifWordHere = true;
                //t4 = TimeProcess::nowTimeMS();
                break;
            }
        }
        if(!ifWordHere){
            words.push_back(candWord);
            index++;
          }
    }
    //t2 = TimeProcess::nowTimeMS();
   // cout <<text->length() <<" time cost in processing this document is " << t2-t1 << "ms " << " main" << tSum << " " << count << endl;
    return words;
};


int MMSeg::getVocabSize(){
    return this->dict.getVocabSize();
};

bool MMSeg::containsKey(string *term){
    return this->dict.containsKey(term);
};
