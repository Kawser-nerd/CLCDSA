import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;

public class Main {
	static class Edge{
		int to;
		Edge(int to){
			this.to = to;
		}
	}
	static boolean visited[];
	static ArrayList<Edge>[] edges;
	static boolean flag;
 	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		int[] u = new int[M];
		int[] v = new int[M];
		edges = new ArrayList[N];
		for(int i = 0; i < N; i++){
			edges[i] = new ArrayList<Edge>();
		}
		for(int i = 0; i < M; i++){
			u[i] = scanner.nextInt()-1;
			v[i] = scanner.nextInt()-1;
			edges[u[i]].add(new Edge(v[i]));
			edges[v[i]].add(new Edge(u[i]));
		}
		visited = new boolean[N];
		for(int i = 0; i < N; i++){
			visited[i] = false;
		}
		flag = false;
		int ans = 0;
		for(int i = 0; i < N; i++){
			if(!visited[i]){
				flag = true;
				dfs(i, -1);
				if(flag){
					ans++;
				}
			}
		}
		System.out.println(ans);
	}
	public static void dfs(int now, int parent){
		for(Edge e : edges[now]){
			if(e.to == parent) continue;
			if(visited[e.to]){
				flag = false;
			}else{
				visited[e.to] = true;
				dfs(e.to, now);
			}
		}
		return;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.