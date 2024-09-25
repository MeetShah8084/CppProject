#include<iostream>  
#include<string.h>


class Register{
    private:
    int id;
    char passwd[10];
    public:
    char username[100]; 
    static int count;    
    void registerUser(); 
    char* getpassword();     
};

int Login(Register* ee,int n);


int loggedin = -1;
char choice='1';
int Register::count = 0;


int main(){

    int count;
    std::cout<<"Enter the number of users : ";
    std::cin>>count;
    Register *acc = new Register[count];
    int i = 0;
    do{
        std::cout<<"\n\t\tMenu"<<std::endl<<"1.Sign in\n2.Log in\n3.Sign Out\n4.Exit\n"<<std::endl<<"Enter your choice: ";
        std::cin>>choice;
        switch(choice){
            case '1':
            if(loggedin == 0){
                std::cout<<"Please Sign out to create new account"<<std::endl;
                break;
            }
            if(Register::count >= count){
                std::cout<<"Number of users Full!!!"<<std::endl;
                break;
            }
            acc[i].registerUser();
            break;
            case '2':
            if(loggedin == 0){
                std::cerr<<"Please sign out to log in with different account " <<std::endl;
                break;
            }
            loggedin = Login(acc,count);
            break;
            case '3':
            if(loggedin == 0){
                loggedin = -1;
                std::cout<<"Succesfully signed out!!!"<<std::endl;
            }
            else{
                std::cout<<"Please log in first!!"<< std::endl;
            }
            break;
            case '4':
                std::cout<<"Exiting...."<<std::endl;
                return 0;
            break;
            default:
            std::cout<<"Invalid choice"<<std::endl;
        }
    }while(choice != '0');

    return 0;
}



void Register::registerUser(){
    std::cout<<"\t\tRegistration Menu"<<std::endl;
    std::cout<<"Enter the username:"<<std::endl;
    std::cin >> this->username;
    std::cout<<"Enter the password (10) : " <<std::endl;
    std::cin>>this->passwd;
    this->id = ++Register::count;
    this->id += 1000;
    std::cout<<"Your id is "<<id << std::endl;
}


char* Register::getpassword(){
    return this->passwd;
}


int Login(Register* ee,int n){
    char pa[100],usrname[100];
    int logg,flag=0,idd,temp;
    std::cout<<"\t\tLogin Menu"<<std::endl<<"Enter id : ";
    std::cin >> idd; 
    std::cout<<"Enter Username : ";
    std::cin >> usrname;
    std::cout<<"Enter password(10) : ";
    std::cin>>pa;
    std::cout<<'\n';
    // idd -= 1001;
    temp = idd - 1001;
    if(temp < 0 || temp > Register::count){
        std::cout<<"Enter proper id"<<std::endl; 
        return -1;
    }
    if(strcmp(ee[temp].username,usrname) == 0){
        if(strcmp(ee[temp].getpassword(),pa) == 0){
            std::cout<<"Successfully Logged in as "<<usrname << std::endl;
            return 0;
        }
        else{
            std::cout<<"Enter correct password"<<std::endl;
            return -1;
        }
    }
    else{
        std::cout<<"Wrong username or password"<<std::endl;
        return -1;
    }
}