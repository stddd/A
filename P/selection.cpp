#include<iostream>
using namespace std;

class Selction
{
    public:
       int M[10];
       int per;
    
    void sorting();

};

void Selction::sorting()
{
    int n,i,j,k;
    int min;
    int ind;
    cout<<"Enter total no of Student :";
    cin>>n;
    for(j=0;j<n;j++)
    {
        cout<<"Enter percentages :";
        cin>>M[j];
    }

    for(i=0;i<n;i++)
    {
        min=M[i];
        ind=i;
        for(k=i+1;k<n;k++)
        {
           if(M[k]<min)
           {
              min=M[k];
              ind=k;
           } 
        }
        swap(M[i],M[ind]);
    }

    cout<<"After sorting marks :";
    for(i=0;i<n;i++)
    {
        cout<<M[i]<<" ";
    }
}

int main()
{
    Selction s1;
    s1.sorting();
    return(0);
}