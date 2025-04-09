#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:

static int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int n = difficulty.size();
    int m = worker.size();
    // 1. Pair jobs (difficulty, profit) and sort by difficulty
    vector<pair<int,int>>jobs;
    for(int i = 0; i<n; i++){
        jobs.emplace_back(difficulty[i], profit[i]);
    }
    sort(jobs.begin(),jobs.end());
    // 2. Sort workers
    sort(worker.begin(),worker.end());
    // 3. Two pointers: worker_ptr and job_ptr
    int total_profit = 0;
    int max_profit = 0;
    int job_ptr = 0;
    for(int ability : worker){
        // Find all jobs with difficulty <= ability
        while(job_ptr<n&&jobs[job_ptr].first <= ability){
            max_profit = max(max_profit, jobs[job_ptr].second);
            job_ptr++;
        }
        total_profit+=max_profit;
    }
    return total_profit;

}
};

int main() {
    vector<int> difficulty = {2, 4, 6, 8, 10};
    vector<int> profit = {10, 20, 30, 40, 50};
    vector<int> worker = {4, 5, 6, 7};
    
    cout << Solution::maxProfitAssignment(difficulty, profit, worker) << endl; // Output: 100
    return 0;
}