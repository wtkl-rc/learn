//4.2串的存储结构

//4.2.1定长顺序存储结构
typedef unsigned char sstring[256];  //用户可在255以内定义最大串长,+1是因为0号放串的长度
//算法4-1定长顺序存储上串的连接算法
//算法4-2求子串操作算法
//算法4-3串的插入操作算法

//算法4-4串的删除操作算法
//算法4-5串的比较操作算法

//4.2.2堆分配存储表示

//算法4-6堆分配存储上串的连接算法

//4.2.3块链存储表示
typedef struct chunk{   //结点结构
    char ch[80];     //用户定义的块（结点）大小
    struct chunk *next;
}chunk;

typedef struct {
    chunk *head,*tail;
    int curlen;
}Lstring;

//BF算法
/**
 * 描述是个问题，我觉得主串有个指针i，子串有个指针j。我要判断主串里面有没有子串，
 * 那么我首先重主串的第一个开始比较，依次往后比较，比较到不一样的时候，主串从第二个开始比较
 * 子串从第一个开始比较
*/

int index(sstring s,sstring t,int pos){
    int i,j=1;
    while(i<=s[0]&&j<=t[0]){  //我觉得可以用for(i=1;i<s[0]-t[0];i++)
       if(s[i]==t[j]){
            j++;
            i++;
        }else{     //指针后退重新开始匹配
            i=i-j+2;
            j=1;
        }   
    }

    if(j>t[0]){    //因为在上面当j=t[0]也会执行一次循环，所以j++，当j>t[0]就是有匹配的子串

        return i-t[0];
    }else{
        return 0;
    }
}