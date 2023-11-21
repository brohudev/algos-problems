/*
Define a structure Job with properties: start, end, profit

Define a function jobComparator
    Input: two jobs s1, s2
    Returns true if end time of s1 is less than end time of s2

Define a function latestNonConflict
    Input: a list of jobs, an integer index
    Perform binary search to find the latest job that doesn't conflict with the job at the given index
    Returns the index of the non-conflicting job or -1 if none found

Define a function findMaxProfit
    Input: lists of start times, end times, and profits for jobs
    Create a list of jobs using the given start, end, and profit lists
    Sort the jobs list using jobComparator
    Initialize a dynamic programming array to store maximum profit up to each job
    Iterate over each job:
        Calculate profit including the current job
        Update the dynamic programming array with the maximum profit up to this job
    Return the maximum profit from the last job

Main Function:
    Read strings of start times, end times, and profits
    Convert these strings into lists of integers
    Call findMaxProfit with these lists
    Print the result
*/
#include <iostream>
using namespace std;
//do stuff

int main(int argc, char const *argv[])
{
    //write stuff here
    return 0;
}
