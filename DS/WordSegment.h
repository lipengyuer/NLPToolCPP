#include<list>
#include<string>
#include<vector>
#include "DataStructures.h"
using namespace std;
class MMSeg{
    protected:
        Dictionary dict;
        int maxLength;
    public:
        void segment(string *text, vector<string> *words);//分词
        vector<string> segment(string *text);//分词
        vector<string> segment_v1(string &text);//分词
        bool containsKey(string *term);
        int getVocabSize();
        MMSeg();
};
