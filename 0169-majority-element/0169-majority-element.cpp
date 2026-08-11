class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int cand=0;
        

        for (int i=0;i<nums.size();i++){
            int x=nums[i];
            if(count==0)
            cand=x;
            if(x==cand)
            count++;
            else
            count--;

        }
        return cand;
    }

};