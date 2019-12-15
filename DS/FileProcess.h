
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

