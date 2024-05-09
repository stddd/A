#include<iostream>
using namespace std;

class Queen{
    public:
    int x[20],count=0;
    int place(int r,int c);
    int nqueen(int r,int c);
    void display(int n);
};

int Queen::place(int r,int c){
    for(int i=1;i<=r-1;i++){
        if(x[i]==c){
            return 0;
        }
        else if(abs(x[i]-c)==abs(i-r)){
            return 0;
        }
    }
    return 1;
}

int Queen::nqueen(int r,int n){
    for(int c=1;c<=n;c++){
        if(place(r,c)){
            x[r]=c;
            if(c==n)
             {   display(n);
             }
            else{
                nqueen(r+1,n);
            }
        }
    }
    return 0;
}
void Queen::display(int n){
    cout<<"\n"<<++count;
    for(int i=1;i<=n;i++){
        cout<<i<<"  ";
    }

    for(int i=1;i<=n;i++){
        cout<<"\n"<<i;
        for(int j=1;j<=n;j++){
            if(x[i]==j){
                cout<<" Q ";
            }
            else
                cout<<" - ";
        }
    }
}

int main(){
    cout<<"Enter queen";
    int n;
    cin>>n;
    Queen q;
    q.nqueen(1,n);
    return 0;
}