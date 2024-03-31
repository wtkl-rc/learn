# dfs模板

```java
void dfs()//参数用来表示状态  
{  
    if(到达终点状态)  
    {  
        ...//根据题意添加  
        return;  
    }  
    
    if(越界或者是不合法状态)  
        return;  
    if(特殊状态)//剪枝
        return ;
    for(扩展方式)  
    {  
        if(扩展方式所达到状态合法)  
        {  
            修改操作;//根据题意来添加  
            标记；  
            dfs（）；  
            (还原标记)；  
            //是否还原标记根据题意  
            //如果加上（还原标记）就是 回溯法  
        }  
    }  
}  
```

# 飞机降落

数组赋值需要使用for循环，用system.arrcopy不可以

```java

import java.security.AlgorithmConstraints;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import javax.print.attribute.standard.JobMessageFromOperator;

public class Main{
	
	static Map<Integer,int[]> map;
	static Scanner scanner = new Scanner(System.in);
	static int N;
	
	public static void main(String[] args) {
		int T = scanner.nextInt();
		
		for(int i=0;i<T;i++) {
			solve();
		}
		
		return;
	}
	
	public static void solve() {
		N= scanner.nextInt();
		map = new HashMap<>();
		for(int i=0;i<N;i++) {
			int a= scanner.nextInt();
			int b= scanner.nextInt();
			int c= scanner.nextInt();
			map.put(i, new int[]{a,b,c});
		}

		
		
		for(int i=0;i<N;i++) {
			int [] al=new int[N];
			int time = map.get(i)[2]+map.get(i)[0];
			al[i]=1;
			int flag=0;
			
			if(dfs(al,flag+1,time)){
				 System.out.println("YES");
				 return;
			}
		}
		System.out.println("NO");
		return;
	}
	
	
	public static boolean dfs(int[] al,int flag,int time) {
		if(flag==N) {
			return true;
		}
		
		for(int j=0;j<N;j++) {
			int time1=time;
			int[] al1=new int[al.length];
			for(int i=0;i<al.length;i++) {
				al1[i]=al[i];
			}
			if(al1[j]==1) {
				continue;
			}else {
				int[] s=map.get(j);
				int t = s[0];
				int d = s[1];
				int l = s[2];
				if(t+d<time) {
					return false;
				}else {
					time1=time1 + l; 
					al1[j]=1;
					if(dfs(al1,flag+1,time1)) {
						return true;
					}else {
						continue;
					}
				}
			}
		}
		return false;
	}
	
	
}

```

