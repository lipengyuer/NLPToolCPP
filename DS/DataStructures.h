#pragma once
#include<map>
#include<string>
#include <unordered_map>
using namespace std;

class Dictionary{

    protected:
        unordered_map<string, string> dict;
        int size;
        unordered_map<string, string>::iterator termIter;
    public:
        vector<string> split_v2(string text, string delimStr);
        void loadVocab();
        bool containsKey(string *term);
        void insertTerm(string term, string postag, int freq);
        int getVocabSize();

       // void deleteTerm(string term);

};


class DictionaryTrie{

    protected:
        unordered_map<string, string> dict;
        int size;
        unordered_map<string, string>::iterator termIter;
    public:
        vector<string> split_v2(string text, string delimStr);
        void loadVocab();
        bool containsKey(string *term);
        void insertTerm(string term, string postag, int freq);
        int getVocabSize();

       // void deleteTerm(string term);

};
