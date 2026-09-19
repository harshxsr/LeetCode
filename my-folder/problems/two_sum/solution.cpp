class Solution {
public:
    int n;
    vector<int> twoSum(vector<int>& nums, int target){ 

    for(int i=0;i<nums.size()-1;i++){
        for(int j=i+1;j<nums.size();j++){
            int temp=nums.at(i)+nums.at(j);
            if(temp==target)
                return {i,j};
        }
    }
    return {};
    }
};