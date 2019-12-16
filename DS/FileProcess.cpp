
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
    ifstream fileHandle(fileName.c_str());
    string line;
    while(getline(fileHandle, line)){
        //cout << "text is " << line.length() << endl;
        lines.push_back(line);
    }
    //for(string line : lines){
   //	for(int i=0; i<lines.size(); i++){
   	//	line = lines[i];
//        cout << "text is " << line.length() << endl;
   // }
    fileHandle.close();
    return lines;
}

 void FileProcess::addLine(string filePath, string text){

    ofstream fileHandle1(filePath.c_str());//, ios::app);
    fileHandle1 << text << endl;
    fileHandle1.close();
 }

