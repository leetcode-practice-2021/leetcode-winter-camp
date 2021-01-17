//给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。 
//
// 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下： 
//
// 
// "123" 
// "132" 
// "213" 
// "231" 
// "312" 
// "321" 
// 
//
// 给定 n 和 k，返回第 k 个排列。 
//
// 说明： 
//
// 
// 给定 n 的范围是 [1, 9]。 
// 给定 k 的范围是[1, n!]。 
// 
//
// 示例 1: 
//
// 输入: n = 3, k = 3
//输出: "213"
// 
//
// 示例 2: 
//
// 输入: n = 4, k = 9
//输出: "2314"
// 
// Related Topics 数学 回溯算法 
// 👍 350 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public String getPermutation(int n, int k) {
        int[] factorials = new int[n+1];
        factorials[0] = 1;
        for (int i = 1; i < factorials.length; i++) {
            factorials[i] = factorials[i-1]*i;
        }
        int[] used = new int[n+1];
        StringBuilder tempRes = new StringBuilder();
        while( n>0 ) {
            int a0 = (k+factorials[n-1]-1) / factorials[n-1];
            tempRes.append(getNum(used,a0));
            k -= (a0 - 1) * factorials[n-1];
            n = n-1;
        }
        return tempRes.toString();
    }

    
    int getNum(int[] used,int rank){
        for (int i = 1; i < used.length; i++) {
            if(used[i]==1){
                continue;
            }
            if(rank==1){
                used[i] = 1;
                return i;
            }else {
                rank--;
            }
        }
        return 0;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
