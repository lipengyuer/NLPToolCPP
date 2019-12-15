

#include<string>
#include<vector>
#include<iostream>
using namespace std;

class StringProcess{
    public:
        vector<string> split(string text, string delimStr);
        void split_v2(vector<string> &slices, string text, string delimStr);
        static string joinStrs(vector<string> terms, string delimStr);
        //string substring(string text, int startIndex, int endIndex);

};

vector<string> StringProcess::split(string text, string delimStr){
    string tempText = text;
    //cout << "1text content is "<<tempText << endl;
    vector<string> slices;
    //cout << "2text content is "<<tempText << endl;
    if(tempText.length()==0){
             cout << "asd slice number is "<<text << endl;
        return slices;
    }
    unsigned int index = 0;
    int lenDelimStr = delimStr.length();
    string tempStr = "";
    //cout << "split string "<< tempText[0] << endl;
    while(index<tempText.length()){
        //cout << "split string index "<<index << endl;
        if(tempText.substr(index, lenDelimStr) == delimStr){

            slices.push_back(tempStr);
            tempStr = "";
            index += lenDelimStr;
        }else{
            tempStr += tempText[index];
            index++;
        }
    }
    if (tempStr.length()>0){
        slices.push_back(tempStr);
    }
    cout << "slice number is "<< slices.size() << endl;
    return slices;
    };


void StringProcess::split_v2(vector<string> &slices, string text, string delimStr){
    string tempText = text;
    unsigned int index = 0;
    int lenDelimStr = delimStr.length();
    string tempStr = "";
    while(index<tempText.length()){
        if(tempText.substr(index, lenDelimStr) == delimStr){
            slices.push_back(tempStr);
            tempStr = "";
            index += lenDelimStr;
        }else{
            tempStr += tempText[index];
            index++;
        }
    }
    if (tempStr.length()>0){
        slices.push_back(tempStr);
    }
    //cout << "1 slice number is "<< slices.size() << endl;
    };

string StringProcess::joinStrs(vector<string> terms, string delimStr){
    string text = "";
    for(string term: terms){
       // subText += (string)text[i];
        text += term + delimStr;
    }
    return text;
};

