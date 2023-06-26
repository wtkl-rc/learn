/**
 * 7.1排序的基本概念
 * 2、排序的分类
 * （1）内排序与外排序
 * 
 * （2）稳定排序与不稳定排序
 * 
 * 3、内排序的方法
 * 插入排序、选择排序、归并类排序
 * 
*/


/**
 * 7.2.1直接插入排序
 * 在一堆数中，我们先把第一个数当做一个数组
 * 接下来依次把第二个第三个数插入到数组里
 * 插入到数组中需要排序，就一个一个查找
*/
typedef int keytype; //将关键字类型定义为整形

typedef struct {
    keytype key;       //关键字项
    int otherinfo;   //其他数据项
}redtype;          //记录类型

typedef struct {
    redtype r[80+1]; //一般将r[0]闲置   10的意思是maxsize
    int length;   
}sqlist;

/**
 * 算法7-1  不带监视哨的直接插入排序
*/
void sort_insert_1(sqlist &l){
    int i,j;
    for(i=2;i<l.length;i++){         //因为0是没有值的，我们直接从2开始，1已经在数组里面了
        redtype temp = l.r[i];       //先把要插入的值存入temp，因为后面移动时会覆盖掉l.r[i]

        /**
         * 将temp与里面的小数组的数依次比较。
         * 内部小数组比外部数组少一个所以是j-1，从后面开始查起
         * temp.key < l.r[j].key   差不多就是a[4]<a[i]  i=(3,2,1)的意思
         * 如果3比4大，那么就用3把四覆盖掉，继续用3跟temp比较
         * 到最后就是用temp就是j+1的位置
         * 
         * 用j>=1来控制下标越界，可能是让j不能等于0，因为他是倒序的
        */
        for(j=i-1;j>=1&&temp.key < l.r[j].key;j--){       
            l.r[j+1]=l.r[j];
        }
        l.r[j+1]=temp;
    }
}

/**
 * 算法7-2带监视哨的直接插入排序
 * ，勉强能理解代码，但是不是很懂为什么要改成这样
*/

void sort_insert(sqlist &l){
    int i,j;
    for(i=2;i<l.length;i++){
        if(l.r[i].key < l.r[i-1].key){
            l.r[0]=l.r[i];
            l.r[i]=l.r[i-1];
            for(j=i-2;l.r[0].key < l.r[j].key;j--){     
                l.r[j+1]=l.r[j];
            }
            l.r[j+1]=l.r[0];
        }
    }
}


/**
 * 7.2.2希尔排序
 * 待排序序列分成若干个子序列，然后分别进行插入排序的方法
 * 
*/

void sort_shell(sqlist &l,int dk){
    int i,j;
    for(i=1+dk;i<l.length;i++){
        if(l.r[i].key<l.r[i-dk].key){    //如果前面的大于后面的
            l.r[0]=l.r[i];
            l.r[i]=l.r[i-dk];
            for(j=i-2*dk;l.r[0].key<l.r[j].key;j-=dk){     //我还是不能明白为什么j=i-2*dk这里算出来的是负数
                l.r[j+dk]=l.r[j];      //这样会出现两个l.r[j]然后方便0插入
            }
            l.r[j]=l.r[0];
        }
    }
}

void sort_shell(sqlist &l,int dlta[],int t){
    for(int a=0;a<t;a++){
        sort_shell(l,dlta[a]);    
    }
}

/**
 * 7.3交换排序
 * 7.3.1冒泡排序
*/

//7.3.2快速排序
