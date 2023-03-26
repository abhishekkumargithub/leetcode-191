Kadanes Algorithm we have used here:

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxso_far=INT_MIN, max_ending_here=0;
        int start = 0, end = 0, s = 0;
        for(int i=0;i<nums.size();i++)
        {
            
            max_ending_here += nums[i];
 
            if (maxso_far < max_ending_here) {
                maxso_far = max_ending_here;
                start = s;
                end = i;
            }
    
            if (max_ending_here < 0) {
                max_ending_here = 0;
                s = i + 1;
            }
        }
        return maxso_far;
    }
};