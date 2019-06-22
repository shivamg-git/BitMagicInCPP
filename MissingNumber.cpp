// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
// find the one that is missing from the array. For example, Given nums = [0, 1, 3] 
// return 2. (Of course, you can do this by math.)

int missingNumber(vector<int>& nums) {
    int ret = 0;
    for(int i = 0; i < nums.size(); ++i) {
        ret ^= i;
        ret ^= nums[i];
    }
    return ret^=nums.size();
}