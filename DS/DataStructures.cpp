#include<map>
#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include "StringProcess.h"
#include "TimeProcess.h"
using namespace std;

class Dictionary{
    protected:
        map<string, string> dict;
        int size = 0;
        map<string, string>::iterator termIter;
    public:
        vector<string> split_v2(string text, string delimStr);
        void loadVocab();
        bool containsKey(string *term);
        void insertTerm(string term, string postag, int freq);
        int getVocabSize();

        //void deleteTerm(string term);
};

vector<string> Dictionary::split_v2(string text, string delimStr){
    vector<string> slices;
    unsigned int index = 0;
    int lenDelimStr = delimStr.length();
    string tempStr = "";
    while(index<text.length()){
        if(text.substr(index, lenDelimStr) == delimStr){
            slices.push_back(tempStr);
            tempStr = "";
            index += lenDelimStr;
        }else{
            tempStr += text[index];
            index++;
        }
    }
    if (tempStr.length()>0){
        slices.push_back(tempStr);
    }
    return slices;
    };


void Dictionary::loadVocab(){
    ifstream vocab("E:\\work\\data\\CoreNatureDictionary.txt");
    string line;
    while(getline(vocab, line)){
        //cout<< line<< " "<<this->dict.size() << endl;
        vector<string> slices;
        slices = this->split_v2(line, "\t");
        if(slices.size()==0){
            cout << "this line is empty:" << line << endl;
            continue;
        }
        this->size += 1;
        this->dict[slices[0]] = "0";
        //cout << "vocab size is " << this->size << " "<<this->dict.size() <<endl;
    }
    vocab.close();
};

bool Dictionary::containsKey(string *term){
    this->termIter = this->dict.find(*term);
    if(this->termIter != this->dict.end()){
        return true;
    }else{
        return false;
    }
};

void Dictionary::insertTerm(string term, string postag, int freq){
    this->dict[term] = postag;
    this->size++;
};

int Dictionary::getVocabSize(){
    return this->dict.size();
};
