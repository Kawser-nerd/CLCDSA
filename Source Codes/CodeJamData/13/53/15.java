import java.io.*;
import java.util.*;

public class Lost {
	static BufferedReader in;
	static StringTokenizer st;
	static PrintWriter out;
	
	static String nextToken() throws IOException {
		while (st==null || !st.hasMoreElements())
			st = new StringTokenizer(in.readLine());
		return st.nextToken(); 
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	static ArrayList<Edge>[] edges;
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader("lost.in"));
		out = new PrintWriter(new FileWriter("losts.out"));
		
		int tests = nextInt();
		for (int tt=1; tt<=tests; tt++) {
			out.printf("Case #%d: ", tt);
			
			int nodes = nextInt(), nE = nextInt(), path = nextInt();
			edges = new ArrayList[nodes];
			for (int i=0; i<edges.length; i++) edges[i] = new ArrayList<Edge>();
			Edge[] listE = new Edge[nE];
			
			for (int i=0; i<nE; i++) {
				listE[i] = new Edge(nextInt()-1, nextInt()-1, nextLong(), nextLong());
				edges[listE[i].from].add(listE[i]);
			}
			
			long[][] maxDists = new long[nodes][nodes];
			for (int i=0; i<maxDists.length; i++)
				for (int j=0; j<maxDists.length; j++)
					if (j!=i) maxDists[i][j] = Long.MAX_VALUE/5;
			for (Edge e: listE)
				if (e.maxDist < maxDists[e.from][e.to])
					maxDists[e.from][e.to] = e.maxDist;
			for (int k=0; k<nodes; k++) {
				for (int i=0; i<nodes; i++)
					for (int j=0; j<nodes; j++)
						if (maxDists[i][k] + maxDists[k][j] < maxDists[i][j])
							maxDists[i][j] = maxDists[i][k] + maxDists[k][j];
			}
							
			long[] dists = maxDists[0].clone();
			System.out.println("OUT HERE");
			
			int[] pathInds = new int[path];
			for (int i=0; i<path; i++)
				pathInds[i] = nextInt()-1;
			
			long distSoFar = 0;
			boolean flag = true;
			boolean[] visited = new boolean[nodes];
			visited[0] = true;
			for (int i=0; i<path && flag; i++) {
				Edge curr = listE[pathInds[i]];
				distSoFar += curr.minDist;
				visited[curr.to] = true;
				
				if (distSoFar > dists[curr.to] || testBad(dists, visited, distSoFar, curr.to)) {
					out.println(pathInds[i]+1);
					flag = false;
					break;
				}

				int end = curr.to;
				for (int j=0; j<dists.length; j++)
					if (maxDists[end][j] + distSoFar < dists[j])
						dists[j] = maxDists[end][j] + distSoFar;
			}
			
			if (flag) out.println("Looks Good To Me");
		}
		out.close();
	}
	
	private static boolean testBad(long[] dists, boolean[] visited, long distSoFar, int startNode) {
		
		long[] reachDists = new long[dists.length];
		boolean[] canReach = new boolean[visited.length];
		canReach[startNode] = true;
		reachDists[startNode] = distSoFar;
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(startNode);
		while (!q.isEmpty() && !canReach[1]) {
			int curr = q.poll();
			for (Edge e: edges[curr])
				if (!canReach[e.to] && reachDists[curr]+e.minDist <= dists[e.to]) {
					canReach[e.to] = true;
					reachDists[e.to] = reachDists[curr]+e.minDist;
					q.add(e.to);
				}
		}
		return !canReach[1];
	}

	private static class Edge {
		int from;
		int to;
		long minDist;
		long maxDist;
		public Edge(int from, int to, long minDist, long maxDist) {
			super();
			this.from = from;
			this.to = to;
			this.minDist = minDist;
			this.maxDist = maxDist;
		}
	}
}
