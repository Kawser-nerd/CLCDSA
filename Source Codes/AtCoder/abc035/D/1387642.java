import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		new Main().solve();
	}
	int N,M,T;
	int[] reward;

	
	void solve(){
		Scanner sc=new Scanner(System.in);
		N=sc.nextInt();
		M=sc.nextInt();
		T=sc.nextInt();
		reward=new int[N];
		
		for(int i=0;i<N;i++){
			reward[i]=sc.nextInt();
		}
		ArrayList<Edge>[] edgeGo=new ArrayList[N];
		ArrayList<Edge>[] edgeBack=new ArrayList[N];
		for(int i=0;i<N;i++){
			edgeGo[i]=new ArrayList<Edge>();
			edgeBack[i]=new ArrayList<Edge>();
		}
		
		for(int i=0;i<M;i++){
			int a=sc.nextInt()-1;
			int b=sc.nextInt()-1;
			int c=sc.nextInt();
			
			edgeGo[a].add(new Edge(b,c));
			edgeBack[b].add(new Edge(a,c));
		}
		
		int[] distanceGo=dijkstra(N,edgeGo,0);
		int[] distanceBack=dijkstra(N,edgeBack,0);
		
		long max=0;
		for(int i=0;i<N;i++){
			long cost=(long)distanceGo[i]+(long)distanceBack[i];
			max=Math.max(max, (long)reward[i]*(T-cost));
		}
		System.out.println(max);
		
	}
	int[] dijkstra(int N,ArrayList<Edge>[] edge,int start){
		boolean[] fixed=new boolean[N];
		int[] distance =new int[N];
		Arrays.fill(distance, Integer.MAX_VALUE);
		distance[start]=0;
		
		Queue<Edge> q=new PriorityQueue<>();
		q.add(new Edge(start,0));
		
		while(!q.isEmpty()){
			Edge e=q.poll();
			if(fixed[e.to]){
				continue;
			}
			fixed[e.to]=true;
			for(Edge ei: edge[e.to]){
				if(!fixed[ei.to]){
					if(distance[ei.to]>distance[e.to]+ei.cost){
						distance[ei.to]=distance[e.to]+ei.cost;
						q.add(new Edge(ei.to,distance[ei.to]));
					}
				}
			}
		}
		return distance;
	}
	
	class Edge implements Comparable<Edge>{
		int to;
		int cost;
		
		Edge(int to,int cost){
			this.to=to;
			this.cost=cost;
		}
		
		public int compareTo(Edge e) {
			return this.cost - e.cost;
		}

	}
	
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.