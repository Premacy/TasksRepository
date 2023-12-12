class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i,j;
        int count;

        i = 0;
        count = 0;
        j = nums.size() - 1;

        while( j >= i ){
            while( nums[j] == val ) j --;

            if( nums[i] == val ){
                std::swap( nums[i], nums[j] );
                j--;
            }else{
                count++;
            }
            i++;
        }

        return count;
    }
};