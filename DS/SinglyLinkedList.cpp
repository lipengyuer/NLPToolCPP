#include <String>
#include <iostream>
#include<cmath>
using namespace std;
class Node{

public:
    Node *nextNode;
    string name;
    Node(string aName){
        this->name = aName;
        }
    void setNextNode(Node* aNode){
        *nextNode = *aNode;
    }
};

class SinglyLinkedList{

};
/*
int main(){
    cout<< "asd" << endl;
    Node a = Node("aaa");
    cout<< a.name << endl;
   // Node* b = Node("bbb");
    //a.setNextNode(b);
    const float PI = 3.14;//����6-7λ��Ч����
    float R = 0.5;
    cout << "�����" << PI* pow(R, 2) << &R<< endl;
    //float *p;
   // *p = R;
  // cout << *p << endl;
   //delete p;
   int *myArray[4];//ָ������
   for(int i=0; i<2 ; i=i+1){
        myArray[i] = &i;
        cout << *myArray[i] << endl;
       // cout << *(myArray+1) << endl;
   }

  // delete myArray;
   //delete p;
   return 0;
}
*/
