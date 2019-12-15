#include<string>
#include<vector>
using namespace std;

class StringProcess{
    public:
        static vector<string> split(string text, string delimStr);
        static void split_v2(vector<string> &slices, string text, string delimStr);
        static string joinStrs(vector<string> terms, string delimStr);
       // string substring(string text, int startIndex, int endIndex);

};

