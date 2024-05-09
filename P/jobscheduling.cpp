#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id;       
    int deadline; 
    int profit;
};

class Jobscheduling
{
    public:
    
    int findMaxDeadline(Job arr[], int n);
    void findMaxProfitSchedule(Job arr[], int n);
};

bool compare(Job a, Job b) 
    {
       return (a.profit > b.profit);
    }


int Jobscheduling::findMaxDeadline(Job arr[], int n) {
    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > max_deadline)
            max_deadline = arr[i].deadline;
    }
    return max_deadline;
}

void Jobscheduling:: findMaxProfitSchedule(Job arr[], int n) 
  {
  
    sort(arr, arr + n, compare);

   
    int max_deadline = findMaxDeadline(arr, n);

    int schedule[max_deadline];
    for(int k=0;k<max_deadline;k++)
    {
        schedule[k]=-1;
    }

    int total_profit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = min(max_deadline, arr[i].deadline) - 1; j >= 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = arr[i].id;
                total_profit += arr[i].profit;
                break;
            }
        }
    }

    cout << "Maximum profit job schedule:" << endl;
    for (int i = 0; i < max_deadline; i++) {
        if (schedule[i] != -1) {
            cout << "Job " << schedule[i] << " ";
        }
    }
    cout << endl;
    cout << "Total profit: " << total_profit << endl;
}

int main() {
    Jobscheduling j1;
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter deadline and profit for job " << i+1 << ": ";
        cin >> arr[i].deadline >> arr[i].profit;
        arr[i].id = i + 1;
    }

    j1.findMaxProfitSchedule(arr, n);

    return 0;
}
