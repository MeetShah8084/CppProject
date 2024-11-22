#include<iostream>
#include<string.h>

int main(){
    char input[100];
    std::cin.getline(input,100);
    std::cin.ignore(100,'\n');
    std::cout<<input;
    return 0;
}