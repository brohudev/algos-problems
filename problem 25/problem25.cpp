#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
// given:
//     a list of jobs with start, end, and profit
// return:
//     maximum profit generated st no two time ranges collide.
// Define a structure Job with properties: start, end, profit
struct job{
    int start;
    int end;
    int profit;
    job(int s, int e, int p) : start(s) , end(e), profit(p) {};
};

// Define a function jobComparator
//     Input: two jobs s1, s2
//     Returns true if end time of s1 is less than end time of s2
bool jobComparator(job* s1, job* s2){
    return s1->end < s2->end; 
}
// Define a function latestNonConflict
//     Input: a list of jobs, an integer index
//     Perform binary search to find the latest job that doesn't conflict with the job at the given index
//     Returns the index of the non-conflicting job or -1 if none found
int latestNonConflict(vector<job*> jobs, int index){

    return 0;
}
// Define a function findMaxProfit
//     Input: lists of start times, end times, and profits for jobs
//     Create a list of jobs using the given start, end, and profit lists
//     Sort the jobs list using jobComparator
//     Initialize a dynamic programming array to store maximum profit up to each job
//     Iterate over each job:
//         Calculate profit including the current job
//         Update the dynamic programming array with the maximum profit up to this job
//     Return the maximum profit from the last job
int maxProfit(vector<int> starts, vector<int> ends, vector<int> profits){
    
    return 0;
}
int main(){
    vector<int> starts, ends, profits; //make room for inputs
    string input = "", temp = ""; 
    getline(cin, input);
    stringstream ss(input);
    while (!ss.eof()){
        temp = "";
        ss >> temp;
        starts.push_back(stoi(temp));
    }
    input = ""; getline(cin, input);
    stringstream ss(input);
    while (!ss.eof()){
        temp = "";
        ss >> temp;
        ends.push_back(stoi(temp));
    }
    input = ""; getline(cin, input); //reset and fetch another line of input
    stringstream ss(input);
    while (!ss.eof()){
        temp = "";
        ss >> temp;
        profits.push_back(stoi(temp));
    }
    vector<job*> jobs;
    for(int i = 0; i<starts.size(); i++){//plop in all the jobs
        job* temp = new job(starts[i], ends[i], profits[i]);
        jobs.push_back(temp);
    }
    cout << maxProfit(starts, ends, profits) << endl; //run the thing
    return 0;
}
/*
Main Function:
    Read strings of start times, end times, and profits
    Convert these strings into lists of integers
    Call findMaxProfit with these lists
    Print the result
*/