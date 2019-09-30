import java.util.*;
import static java.lang.Math.*;

public class Main {
	int[][] vis;
	int[] color;
	ArrayList<Integer>[] graph;
	
	class Query {
		int v, d, c;
		Query(int v, int d, int c) {
			this.v = v;
			this.d = d;
			this.c = c;
		}
	}
	
	void dfs(int u, int d, int c) {
		if (vis[u][d] == 1) return;
		vis[u][d] = 1;
		if(d == 0) {
			if(color[u] == 0) color[u] = c;
			return;
		}
		dfs(u, d-1, c);
		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u].get(i);
			dfs(v, d - 1, c);
		}
	}

	void run() {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		vis = new int[n][11];
		color = new int[n];
		graph = new ArrayList[n];
		for (int i = 0; i < graph.length; i++) graph[i] = new ArrayList<Integer>();
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
			graph[a].add(b); graph[b].add(a);
		}
		int q = sc.nextInt();
		Stack<Query> s = new Stack<>();
		for (int i = 0; i < q; i++) {
			int v = sc.nextInt() - 1, d = sc.nextInt(), c = sc.nextInt();
			Query query = new Query(v, d, c);
			s.push(query);
		}
		while (!s.isEmpty()) {
			Query query = s.pop();
			dfs(query.v, query.d, query.c);
		}
		for (int i = 0; i < color.length; i++) System.out.println(color[i]);
	}
	
	public static void main(String[] args) {
		new Main().run();
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.