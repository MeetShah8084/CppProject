#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream f1,f2;
    f1.open("srcc.txt",ios::in);
    f2.open("dest.txt",ios::out | ios::ate);
    if(!f1 || !f2){
        cout<< "Error Opening file!!" << endl;
        f1.close();
        f2.close();
    }
    else{
        char ch;
        while(f1.get(ch)){
            f2.put(ch);
            cout<<ch;
        }
    }
    f1.close();
    f2.close();
    return 0;
}