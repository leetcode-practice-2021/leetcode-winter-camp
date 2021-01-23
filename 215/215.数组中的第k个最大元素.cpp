/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
    void buildMaxHeap(vector<int>& nums){
        for (int i = nums.size()/2; i >= 0; i--)
        {
            sink(nums,i, nums.size());
        }
    }
    void sink(vector<int>& nums, int i, int heap_sz){
        while (2*i + 1 <= heap_sz - 1)
        {
            int j = 2*i + 1;
            if(j < heap_sz-1 && nums[j+1]>nums[j]){
                j++;
            }
            if(nums[j]<nums[i]){
                break;
            }
            swap(nums[i],nums[j]);
            i = j;
        }
    }

    int partition(vector<int>& nums, int idx, int lo,int hi){
        if(lo == hi){
            return lo;
        }
        int cur_num = nums[lo];
        int i = lo;
        int j = hi+1;
        while (true)
        {
            while (nums[++i] <= cur_num)
            {
                if(i==hi){
                    break;
                }
            }
            while (cur_num < nums[--j])
            {
                if(j==lo){
                    break;
                }
            }
            if(i >= j){
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[lo], nums[j]);
        return j;
    }
    int randPartition(vector<int>& nums, int idx, int lo,int hi){
        if(lo == hi){
            return lo;
        }
        int rand_idx = rand()%(hi - lo + 1) + lo;
        swap(nums[rand_idx], nums[lo]);
        return partition(nums, idx, lo ,hi);
    }

    int quickSelect(vector<int>& nums, int idx, int lo,int hi){

        int p_idx = randPartition(nums, idx, lo,hi);
        //for(int i:nums){
        //    cout << i << " ";
        //}
        //cout << endl;
        if(p_idx == idx){
            return nums[p_idx];
        }
        if(p_idx < idx){
            return quickSelect(nums, idx,p_idx+1, hi );
        }else{
            return quickSelect(nums,idx,lo,p_idx-1 );
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        // buildMaxHeap(nums);
        // int heap_sz= nums.size();
        // for (int i = 0; i < k-1; i++)
        // {
        //     swap(nums[0], nums[heap_sz-1]);
        //     sink(nums, 0, heap_sz);
        //     heap_sz--;
        // }
        // return nums[0];
        srand(time(0));
        return quickSelect(nums, nums.size()-k,0, nums.size()-1 );
    }
};
// @lc code=end

