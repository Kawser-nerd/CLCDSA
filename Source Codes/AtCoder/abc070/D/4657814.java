import java.util.Scanner;
import java.util.ArrayList;
public class Main{
	static ArrayList<Edge>[] list;
	static long[] dist;
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		list=new ArrayList[n+1];
		dist=new long[n+1];
		for(int i = 0; i<=n; i++){
			list[i]=new ArrayList<>();
		}
		for(int i = 0; i<n-1; i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			long c = sc.nextLong();
			list[a].add(new Edge(b,c));
			list[b].add(new Edge(a,c));
		}
		int q = sc.nextInt();
		int k = sc.nextInt();
		dfs(k,0,-1);
		for(int i = 0; i<q; i++){
			int x = sc.nextInt();
			int y = sc.nextInt();
			System.out.println(dist[x]+dist[y]);
		}
	}
	static void dfs(int now,long cost,int front){
		dist[now]=cost;
		for(Edge i:list[now]){
			if(i.to!=front){
				dfs(i.to,i.cost+cost,now);
			}
		}
	}
	
	static class Edge{
		int to;
		long cost;
		public Edge(int to,long cost){
			this.to=to;
			this.cost=cost;
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.