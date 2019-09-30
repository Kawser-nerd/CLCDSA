import java.util.Scanner;
import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		Edge[] edge=new Edge[m];
		for(int i = 0; i<m; i++){
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			long c = sc.nextLong();
			edge[i]=new Edge(a,b,-c);
		}
		long[] dist=new long[n];
		Arrays.fill(dist,Long.MAX_VALUE);
		dist[0]=0;
		boolean flag=true;
		int cnt=0;
		long ans=0;
		while(flag){
			flag=false;
			for(int i = 0; i<m; i++){
				if(dist[edge[i].from]!=Long.MAX_VALUE && dist[edge[i].to]>dist[edge[i].from]+edge[i].cost){
					flag=true;
					dist[edge[i].to]=dist[edge[i].from]+edge[i].cost;
				}
			}
			if(cnt==n){
				ans=-dist[n-1];
			}
			if(cnt==2*n){
				if(ans<-dist[n-1]){
					System.out.println("inf");
					return;
				}
				break;
			}
			cnt++;
		}
		System.out.println(-dist[n-1]);
	}
	static class Edge{
		int from;
		int to;
		long cost;
		public Edge(int from,int to,long cost){
			this.from=from;
			this.to=to;
			this.cost=cost;
		}
	}
}