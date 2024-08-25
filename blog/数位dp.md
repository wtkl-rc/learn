# 数位dp

可以理解为，有3位数，每位数都可以填0-9，当第一位选填0，那么第二位可以填0-9，第二位选填0，第三位又可以填0-9。

一直递归下去直到把所有的数遍历完，加入记忆化搜索，和具体题目的条件。



[233. 数字 1 的个数](https://leetcode.cn/problems/number-of-digit-one/)

思路：假设在4位数中，先选填第一位，再选填第二位，当每选填一位数有 1 结果就加 1，要记忆化搜索，加上一个memo二维数组。 

```java
class Solution {
     public  int countDigitOne(int n) {
        int l= Integer.toString(n).length();

        char[] c = Integer.toString(n).toCharArray();
        int[][]  memo= new int[l][l];

        for(int[] a:memo){
            Arrays.fill(a,-1);
        }

        return dfs(0,0,true,c,memo);
    }

     public  int dfs(int i, int cnt, boolean isLimit,char[] c,int[][] memo) {
         //超过了数字的长度
        if(i==c.length){
            return cnt;
        }
        //已经遍历过的
        if(!isLimit && memo[i][cnt]>=0){
            return memo[i][cnt];
        }
        int res = 0;
         //如果有限制，那么此位可以选填0 - c[i] - '0'
        int up = isLimit? c[i] - '0': 9;
        //对于limit的理解，只有当d==up的时候，也就是第二位（此位）数字等于他的上限的时候，第三位（下一位）数字才受到限制
        for(int d = 0;d <= up;d++){
            res += dfs(i+1,  cnt+(d==1?1:0),isLimit && d==up, c  ,memo);
        }
        
        if(!isLimit){
           memo[i][cnt]=res;
        }

        return res;
    }
}
```

