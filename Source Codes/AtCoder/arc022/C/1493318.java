import java.util.*;

public class Main{

    public static void main(String[] args){
           
             Scanner sc = new Scanner(System.in);
                   
             int n = sc.nextInt();

		edges = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<Edge>();
		}
		
		for (int i = 0; i < n - 1; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();

			edges[a - 1].add(new Edge(b - 1, 1));
			edges[b - 1].add(new Edge(a - 1, 1));
		}

		int s = 0;
		d = new int[n];
		Arrays.fill(d, -1);
		d[s] = 0;
		max = 0;
		maxt = -1;
		dfs(s);

		s = maxt;
		d = new int[n];
		Arrays.fill(d, -1);
		d[s] = 0;
		max = 0;
		maxt = -1;
		dfs(s);

		System.out.printf("%d %d%n", s + 1, maxt + 1);
		
	}

	private static void dfs(int i) {
		for (Edge e : edges[i]) {
			if (d[e.v] == -1) {
				d[e.v] = d[i] + e.w;
				if (d[e.v] > max) {
					max = d[e.v];
					maxt = e.v;
				}
				dfs(e.v);
			}
		}
		return;
	}

	private static int max;
	private static int maxt;
	private static ArrayList<Edge>[] edges;
	private static int[] d;

	private static class Edge {
		int u; // from
		int v; // to
		int w; // cost
		
		Edge(int v, int w) {
			this.u = u;
			this.v = v;
			this.w = w;
		}
                
	}                 
        
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.