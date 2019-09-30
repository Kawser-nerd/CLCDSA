import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		PersistentUnionFind puf=new PersistentUnionFind(n+1);
		for(int i=0;i<m;i++){
			int a=sc.nextInt(),b=sc.nextInt();
			puf.union(a,b);
		}
		int q=sc.nextInt();
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<q;i++){
			int x=sc.nextInt(),y=sc.nextInt(),z=sc.nextInt();
			int left=1,right=m;
			while(left<right){
				int mid=(left+right)/2+(int)(Math.random()*2);
				if(puf.same(x,y,mid)){
					int v=puf.size(x,mid);
					if(v>=z) right=mid;
					else left=mid+1;
				}else{
					int v=puf.size(x,mid)+puf.size(y,mid);
					if(v>=z) right=mid;
					else left=mid+1;
				}
			}
			sb.append(left).append("\n");
		}
		System.out.println(sb);
	}
}
class PersistentUnionFind{
	int[] par;
	int[] time;
	int[] rank;
	ArrayList<Integer>[] history;
	ArrayList<Integer>[] size;
	int now;
	public PersistentUnionFind(int n){
		par=new int[n];
		for(int i=0;i<n;i++) par[i]=i;
		time=new int[n];
		rank=new int[n];
		Arrays.fill(time,Integer.MAX_VALUE);
		now=0;
		
		history=new ArrayList[n];
		size=new ArrayList[n];
		for(int i=0;i<n;i++){
			history[i]=new ArrayList<Integer>();
			size[i]=new ArrayList<Integer>();
			history[i].add(0);
			size[i].add(1);
		}
	}
	int find(int n,int t){
 		if(time[n] > t){
 			return n;
 		}
		return find(par[n],t);
	}
	void union(int x,int y){
		now++;
		x=find(x,now);
		y=find(y,now);
		if(x==y) return;
		if(rank[x] > rank[y]){
			int z=x;
			x=y;
			y=z;
		}
		
		int sx=size[x].get(size[x].size()-1);
		int sy=size[y].get(size[y].size()-1);
		history[y].add(now);
		size[y].add(sx+sy);
		
		time[x]=now;
		if(rank[x]==rank[y]){
			rank[y]++;
		}
		par[x]=y;
	}
	boolean same(int x,int y,int t){
		return find(x,t) == find(y,t);
	}
	int unionTime(int x,int y){
		if(!same(x,y,now)) return -1;
		
		int res=0;
		while(x!=y){
			if(rank[x]<rank[y]){
				res=Math.max(res,time[x]);
				x=par[x];
			}else{
				res=Math.max(res,time[y]);
				y=par[y];
			}
		}
		return res;
	}
	int size(int x,int t){
		x=find(x,t);
		
		int left=0,right=size[x].size()-1;
		while(left<right){
			int mid=(left+right)/2+(left==(right-1)?1:0);
			if(history[x].get(mid)>t) right=mid-1;
			else left=mid;
		}
		return size[x].get(left);
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.