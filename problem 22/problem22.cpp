#include <iostream>
using namespace std;
void backtrack(string str, int k, string& knum, string& max, int& minswaps, int swaps, int ctr){
    int n = str.length();
    if (k == 0 && stoi(max) > stoi(knum)){//reached limit for part a.
    //second set ensures only the biggest max number from the recursion tree is set to this var.
        knum = max;
    }
    if(ctr >= n && swaps < minswaps){ //replace the least swaps with the newfound way to get the biggest number. 
    //makes sure only the swaps of the highest number with lowest swap count are stored for part b once youre at the end. 
        minswaps = swaps;
        return;
    }
    char maxm = str[ctr];
    for (int j = ctr + 1; j < n; j++) { //find the max digit after the curr index.
        if (maxm < str[j])
            maxm = str[j];
    }
    if (maxm != str[ctr]) //decrease k if you found a good swap candidate.
        --k;
    for (int j = n-1; j >=ctr; j--) {
        if (str[j] == maxm) {
            swap(str[ctr], str[j]); //make the choice
            if (str.compare(max) > 0) //change the max if swapping increases the number. 
                max = str;
            backtrack(str, k, knum, max, minswaps, swaps+1,  ctr + 1); //increase swaps and ctr on recursing
            swap(str[ctr], str[j]); //undo choice. 
        }
    }
}
int main(){
    string str, knum = "0"; int k, swaps, minswaps;
    cin >> str; cin >> k; // input numbers.
    string max = str;
    minswaps = str.length() +1; //plus 1 for safety. 
    backtrack(str, k, knum, max, minswaps, 0, 0); //run function
    cout << knum <<"\n" << minswaps; //pt (a) answer \n pt (b) answer. 
    return 0;
}