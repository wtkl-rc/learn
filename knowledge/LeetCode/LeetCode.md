 27.移除元素

```c++
暴力破解法
程序不能运行
int removeElement(vector<int>& nums, int val) {
    int i;
    int k=sizeof(nums)-1;        //数组长度
    for(i=0;i<=k;i++){            //遍历数组
        if(nums[i]==val){
            for(int j=i;j<k;j++){            //移动数组
                    nums[j]=nums[j+1];
            }
            k--;
            i--;
        }
    }
    return k;
  }
```

```
双指针法
快慢指针法
用的就是两个指针，一个快指针和一个慢指针，开始时两个指针同时移动，移动到目标元素后，慢指针不动，快指针移动。慢指针的元素变为快指针的元素，实现元素替换。
int removeElement(vector<int>& nums, int val) {
	    int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
}
```

这段代码触及到了我的知识盲区，不知道如何去接受这样的新事物，我只能说，我尽力去了解它
