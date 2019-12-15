#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include "StringProcess.h"
#include "WordSegment.h"
#include "FileProcess.h"
#include "TimeProcess.h"
//#include "DataStructures.h"
using namespace std;



int main(){

    cout << "start to load corpus " << endl;
    FileProcess fileProcessor;
    vector<string> documents = fileProcessor.readLines("E:\\work\\data\\tlbb.txt");
    cout << "finish loading corpus " << documents.size()<< endl;

    MMSeg wordSeg;
    int vocabSize = wordSeg.getVocabSize();
    cout << "词典的大小是" << vocabSize << endl;
    string word = u8"love";
    if(wordSeg.containsKey(&word)){
        cout << "the word is contained " << endl;
    }

    string sentence = "ilovethisworld";
    vector<string> words;
    wordSeg.segment(&sentence, &words);
    for(string word: words){
        cout<< word << endl;
    }
    cout << "word number is " << words.size()<< endl;

    int count = 0;
    int charNum = 0;
    int t1, t2, totalT = 0;

    string tempText = "";
    cout << "start timestamp is "<<TimeProcess::nowTimeMS()/1000 << endl;
    StringProcess strProcessor;
    for(string line: documents){
        tempText += line;
        if(tempText.length()>500000){
            t1 = TimeProcess::nowTimeMS();
            vector<string> words;
            wordSeg.segment(&tempText, &words);
            //vector<string> words = wordSeg.segment(&tempText);
            t2 = TimeProcess::nowTimeMS();
            totalT += t2-t1;
            string segText = strProcessor.joinStrs(words, " ");
            fileProcessor.addLine("result.txt", segText);
            cout << "total time cost is " << t2-t1 <<" total is " << totalT/1000<< endl;
            charNum += tempText.length();
            tempText = "";
            count++;
            if(count%500==0){
                cout << "document number is " << count << " totalT is" << totalT/1000 << endl;
                cout << "speed is " <<  charNum << " " << (charNum/totalT)*1000 << endl;
            }
        }
    }
    cout << "time cost is " << totalT/1000 << "Second" << endl;
    cout << "char number is " << charNum << endl;
    cout << "speed is " <<  charNum << " " << charNum/totalT*1000 << endl;

    return 0;
};
