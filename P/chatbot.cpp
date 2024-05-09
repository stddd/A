#include<iostream>
#include<cstring>
using namespace std;

string getuserinput()
{   
    string input;
    cout<<"You:";
    getline(cin,input);
    return input;
}
string getresponse(string userinput)
{
    if(userinput=="hi"|| userinput=="hello")
    {
        return "Hello! How can I help you!";
    }
    else if(userinput=="how are you")
    {
        return "I am fine, but am just a chatbot i dont have feelings";
    }
    else if(userinput=="bye")
    {
        return "GoogBye! Have a nice Day";
    }
    else
    {
        return "please enter valid input";
    }
}

int main()
{
    string userinput;
    cout << "Welcome to the Elementary Chatbot!" << endl;
    cout << "You can start chatting. Type 'bye' to exit." << endl;
    while(true)
    {
        userinput=getuserinput();

        //transform(userinput.begin(),userinput.end(),userinput.begin(),::tolower);

        if(userinput=="bye")
        {
            break;
        }

        string response=getresponse(userinput);
        cout<<"Chatbot:"<<response<< endl;

    }
}