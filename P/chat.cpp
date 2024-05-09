#include<iostream>
#include<string>
using namespace std;

string getuserinput(){
    cout<<"You :\n";
    string inpu;
    getline(cin,inpu);
    return inpu;
}

string inputresponse(string inpu){
    
    if(inpu=="hi"|| inpu=="hello"){
        return "hiiii";
    }else if(inpu=="how are you"){
        return "i am fine";
    }else if(inpu=="ok"){
        return "okkk";
    }else{
        return "invalid userinput";
    }
}

int main(){
    string inp,res;
    while(true){
        inp=getuserinput();
        if(inp=="exit"){
            cout<<"bye";
            break;
        }
        res=inputresponse(inp);
        cout<<"boat:"<<res<<endl;
    }
    return 0;
}