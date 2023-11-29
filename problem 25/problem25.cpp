#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
// given:
//     a list of jobs with start, end, and profit
// return:
//     maximum profit generated st no two time ranges collide.
// Define a structure Job with properties: start, end, profit
// struct job{
//     int start;
//     int end;
//     int profit;
//     job(int s, int e, int p) : start(s) , end(e), profit(p) {};
// };
// // Define a function jobComparator
// //     Input: two jobs s1, s2
// //     Returns true if end time of s1 is less than end time of s2
// bool jobComparator(job* s1, job* s2){
//     return s1->end < s2->end; 
// }
// // Define a function latestNonConflict
// //     Input: a list of jobs, an integer index
// //     Perform binary search to find the latest job that doesn't conflict with the job at the given index
// //     Returns the index of the non-conflicting job or -1 if none found
// int latestNonConflict(vector<job*> jobs, int index){
//     return 0;
// }
// // Define a function findMaxProfit
// //     Input: lists of start times, end times, and profits for jobs
// //     Create a list of jobs using the given start, end, and profit lists
// //     Sort the jobs list using jobComparator
// //     Initialize a dynamic programming array to store maximum profit up to each job
// //     Iterate over each job:
// //         Calculate profit including the current job
// //         Update the dynamic programming array with the maximum profit up to this job
// //     Return the maximum profit from the last job
// int maxProfit(vector<int> starts, vector<int> ends, vector<int> profits){
//     return 0;
// }

class solution{
    public:
        int n;
        vector<int> memo;
        solution(int num){
            for(int i=0; i < num; i++){
                memo.push_back(-1);
            }
        };
        int getnextindex(vector<vector<int>>& array, int l, int currentjobend){
            int r = n -1;

            int result = n+1;

            while(l <= r){
                int mid = l + (r-l)/2;

                if(array[mid][0] >= currentjobend){
                    result = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }

            return result;
        }
        int solve(vector<vector<int>>& array, int i){
            if (i >= n)
                return 0;
            if(memo[i] != -1){
                return memo[i];
            }
            int next = getnextindex(array, i+1, array[i][1]);
            int taken = array[i][2] + solve(array, next);
            int nottaken = solve(array, i+1);

            return memo[i] = max(taken, nottaken);
        }

        int jobscheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
            n = startTime.size();
            vector<vector<int>> array(n, vector<int>(3,0));

            for (int i = 0; i<n; i++){
                array[i][0]= startTime[i];
                array[i][1]= endTime[i];
                array[i][2]= profit[i];
            }

            auto comp = [&](auto& vec1, auto& vec2){
                return vec1[0] <= vec2[0];
            };

            sort(begin(array), end(array), comp);
            
            return solve(array,0);
        }
};

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
    stringstream s1(input);
    while (!s1.eof()){
        temp = "";
        s1 >> temp;
        ends.push_back(stoi(temp));
    }
    input = ""; getline(cin, input); //reset and fetch another line of input
    stringstream s2(input);
    while (!s2.eof()){
        temp = "";
        s2 >> temp;
        profits.push_back(stoi(temp));
    }
    solution s(starts.size());
    cout << s.jobscheduling(starts, ends, profits);
    return 0;
}
/*
Main Function:
    Read strings of start times, end times, and profits
    Convert these strings into lists of integers
    Call findMaxProfit with these lists
    Print the result
*/
//chatgpt spat out the following pseudo code:
// function getMaxProfit(startTime, endTime, profit):
//     return findNonOverlappingJobs(0, startTime, endTime, profit, 0)
// function findNonOverlappingJobs(currentIndex, startTime, endTime, profit, currentProfit):
//     if currentIndex == length(startTime):
//         return currentProfit
//     // Skip the current job
//     profitWithoutCurrentJob = findNonOverlappingJobs(currentIndex + 1, startTime, endTime, 
                                                    // profit, currentProfit)
//     // Include the current job if it doesn't overlap with previous jobs
//     nextCompatibleIndex = findNextCompatibleIndex(currentIndex, startTime, endTime)
//     profitWithCurrentJob = findNonOverlappingJobs(nextCompatibleIndex, startTime, endTime, 
                                            //profit, currentProfit + profit[currentIndex])
//     // Return the maximum of the two options
//     return max(profitWithoutCurrentJob, profitWithCurrentJob)
// function findNextCompatibleIndex(currentIndex, startTime, endTime):
//     // Find the next job that doesn't overlap with the current job
//     for i = currentIndex + 1 to length(startTime) - 1:
//         if startTime[i] >= endTime[currentIndex]:
//             return i
//     return length(startTime)
