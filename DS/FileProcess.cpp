
#include<fstream>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class FileProcess{
    public:
        vector<string> readLines(string fileName);
         void addLine(string filePath, string text);
};

vector<string> FileProcess::readLines(string fileName){
    vector<string> lines;
    ifstream fileHandle(fileName);
    string line;
    while(getline(fileHandle, line)){
        //cout << "text is " << line << endl;
        lines.push_back(line);
    }
    fileHandle.close();
    return lines;
}

 void FileProcess::addLine(string filePath, string text){

    ofstream fileHandle(filePath, ios::app);
    fileHandle << text << endl;
    fileHandle.close();
 }

