#include<map>
#include<string>
using namespace std;

class Dictionary{

    protected:
        map<string, string> dict;
        int size;
        map<string, string>::iterator termIter;
    public:
        vector<string> split_v2(string text, string delimStr);
        void loadVocab();
        bool containsKey(string *term);
        void insertTerm(string term, string postag, int freq);
        int getVocabSize();

       // void deleteTerm(string term);

};
