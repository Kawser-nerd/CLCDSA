import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main{
	static int n,k;
	static LinkedList<Integer>[] g;
	static edge[] e;
	static int cal(int x){
		int[] ans=bfs(x);
		int res=0;
		for(int i=0;i<n;i++) if(2*ans[i]>k) res++;
		return res;
	}
	static int cal(int x,int y){
		int[] a1=bfs(x);
		int[] a2=bfs(y);
		int res=0;
		for(int i=0;i<n;i++) if(2*a1[i]>k && 2*a2[i]>k) res++;
		return res;
	}
	static int[] bfs(int x){
		int[] res=new int[n];
		Arrays.fill(res,-1);
		Queue<state> que=new ArrayDeque<state>();
		que.add(new state(x,-1));
		res[x]=0;
		while(!que.isEmpty()){
			state now=que.poll();
			for(int e:g[now.x]){
				if(e!=now.p && res[e]==-1){
					res[e]=res[now.x]+1;
					que.add(new state(e,now.x));
				}
			}
		}
		return res;
	}
	static class state{
		int x,p;
		public state(int a,int b){
			x=a; p=b;
		}
	}
	static class edge{
		int s,t;
		public edge(int a,int b){
			s=a; t=b;
		}
	}
	@SuppressWarnings("unchecked")
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
			n=sc.nextInt();
			k=sc.nextInt();
			g=new LinkedList[n]; for(int i=0;i<n;i++) g[i]=new LinkedList<Integer>();
			edge[] e=new edge[n-1];
			for(int i=0;i<n-1;i++){
				int a=sc.nextInt(); a--;
				int b=sc.nextInt(); b--;
				g[a].add(b);
				g[b].add(a);
				e[i]=new edge(a,b);
			}
			int min=Integer.MAX_VALUE;
			if(k%2==0) for(int i=0;i<n;i++) min=Math.min(min,cal(i));
			else for(int i=0;i<n-1;i++) min=Math.min(min,cal(e[i].s,e[i].t));
			System.out.println(min);
		}
	}
}