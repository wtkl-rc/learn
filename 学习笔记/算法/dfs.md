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

# 买瓜

数组的传递需要new一个新的数组对象，这道题应该是用bfs的

```java
package test;

import java.util.Scanner;

public class maigua {
	static int[] a;
	static double[] A;
	static int n;
	static double m;
	static int dao2=100; 
	static Scanner scanner = new Scanner(System.in);
	public static void main(String[] args) {
		n = scanner.nextInt();
		m = scanner.nextInt();
		solve(n);
	}
	
	
	public static void solve(int n){
	    A=new double[n];
	    
	    for(int i=0;i<n;i++){
	         A[i]=scanner.nextInt();
	    }
	    
	    int[] Al = new int[n];
	    dfs(Al,0,0,0);
	    System.out.println(dao2);
	   return;
	}
	
	public static int dfs(int[] Al,double mm,int time,int dao){
		
	 if(mm==m){
		 return dao;
	 }else if(time == n || mm>m) {
		 return -1;
	 }
	 
	 for(int i=0;i<Al.length;i++){
		 
	    if(Al[i]==1){
	        continue;
	    }else{
	        Al[i]=1;
	        
	        int[] a=new int[n];
	        int[] b=new int[n];
	        for(int j=0;j<n;j++) {
	        	a[j]=Al[j];
	        	b[j]=Al[j];
	        }
	        
	        int dao1=dfs(a,mm+A[i],time+1,dao);
	        
	        if(dao1==-1) {
	        	int dao3=dfs(b,mm+(A[i]/2),time+1,dao+1);
	        	if(dao3!=-1&&dao3<dao2) {
	        		dao2=dao3;
	        	}
	        }else {
	        	if(dao1<dao2) {
	        		dao2=dao1;
	        	}
	        	}
	    	} 
	    }
	return -1;
	}
	
}

```

# 网路稳定性

```java
package test;

import java.security.AlgorithmConstraints;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

public class wangluowendingxing {
	static Scanner scanner=new Scanner(System.in);
	static int[][] tu;
	static int n;
	public static void main(String[] args) {
		n=scanner.nextInt();
		int m=scanner.nextInt();
		int q=scanner.nextInt();
		
		tu=new int[n][n];
		
		for(int i=0;i<m;i++) {
			int f=scanner.nextInt();
			int s=scanner.nextInt();
			int t=scanner.nextInt();
			
			tu[f-1][s-1]=t;
			tu[s-1][f-1]=t;
		}
	
		
		for(int i=0;i<q;i++) {
			solve();
		}
	}
	
	public static void solve() {
		int x = scanner.nextInt();
		int y = scanner.nextInt();
		dfs(x-1,y-1,new int[n],new ArrayList<Integer>(n));
		if(min==0) {
			System.out.println(-1);
		}else {
			System.out.println(min);
		}
		
	}
	
	static int min=0;
	
	public static int dfs(int x,int y,int[] al,ArrayList<Integer> mid) {
		if(al[x]==1) {
			return -1;
		}else if(tu[x][y]!=0) {
			mid.add(tu[x][y]);
			Collections.sort(mid);
			return mid.get(0);
		}
		for(int i=0;i<n;i++) {
			if(tu[x][i]!=0 && al[i]!=1) {
				mid.add(tu[x][i]);
				al[x]=1;
				int an=dfs(i,y,al,mid);
				al[i]=1;
				if(an!=-1&&an>min) {
					min=an;
				}
				mid.clear();
			}else {
				continue;
			}
		}
		return -1;
	}
}

```

