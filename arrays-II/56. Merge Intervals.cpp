//Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

//Approach: Brute Force
//First check whether the array is sorted or not.If not sort the array. 
//Now linearly iterate over the array and then check for all of its next intervals whether they are overlapping 
//with the interval at the current index. Take a new data structure and insert the overlapped interval.
// If while iterating if the interval lies in the interval present in the data structure simply continue and move to the next interval.
//COde:
#include<bits/stdc++.h>
using namespace std;

vector < pair < int, int >> merge(vector < pair < int, int >> & arr) {

    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector < pair < int, int >> ans;

    for (int i = 0; i < n; i++) {
        int start = arr[i].first, end = arr[i].second;

        //since the intervals already lies 
        //in the data structure present we continue
        if (!ans.empty()) {
            if (start <= ans.back().second) {
                continue;
            }
        }

        for (int j = i + 1; j < n; j++) {
            if (arr[j].first <= end) {
                end = max(end, arr[j].second);
            }
        }
    
        end = max(end, arr[i].second);

        ans.push_back({start, end});
    }

    return ans;
}

//optimized approach:

// Approach: 
// Linearly iterate over the array if the data structure is empty insert the interval in the data structure. 
// If the last element in the data structure overlaps with the current interval we merge the intervals by updating the last element in the data structure, 
// and if the current interval does not overlap with the last element in the data structure simply insert it into the data structure.

// Intuition: Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent.
// We kept on merging simultaneously as we were traversing through the array and when the element was non-overlapping we simply inserted the element in our data structure.
Code:
vector<vector<int>> mergedIntervals;
        if(intervals.size()==0)
            return mergedIntervals;
        sort(intervals.begin(),intervals.end());
        vector<int> tempInterval=intervals[0];

        for(auto it:intervals)
        {
            if(it[0]<=tempInterval[1])
            {
                tempInterval[1]=max(it[1],tempInterval[1]);
            }else
            {
                mergedIntervals.push_back(tempInterval);
                tempInterval=it;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;