import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskX solver = new TaskX();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			// input
			int n = in.nextInt();
			Node[] nodes = new Node[n];
			for (int i = 0; i < n; i++) {
				int x = in.nextInt();
				int y = in.nextInt();
				nodes[i] = new Node(i, x, y);
			}

			// solve
			long totalCost = 0;
			@SuppressWarnings("unchecked")
			ArrayList<Edge>[] list = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				list[i] = new ArrayList<Edge>();
			}

			// construct edge
			Arrays.sort(nodes,  (n1, n2) -> Integer.compare(n1.x, n2.x));
			for (int i = 0; i < n - 1; i++) {
				int toNode = nodes[i+1].id;
				int fromNode = nodes[i].id;

				int cost = Math.abs(nodes[i+1].x - nodes[i].x);
				list[fromNode].add(new Edge(fromNode, toNode, cost));
				list[toNode].add(new Edge(toNode, fromNode, cost));
			}
			Arrays.sort(nodes,  (n1, n2) -> Integer.compare(n1.y, n2.y));
			for (int i = 0; i < n - 1; i++) {
				int toNode = nodes[i+1].id;
				int fromNode = nodes[i].id;

				int cost = Math.abs(nodes[i+1].y - nodes[i].y);
				list[fromNode].add(new Edge(fromNode, toNode, cost));
				list[toNode].add(new Edge(toNode, fromNode, cost));
			}

			boolean[] visited = new boolean[n];
			PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
			for (Edge e : list[0]) {
				pq.add(e);
			}
			visited[0] = true;

			while (!pq.isEmpty()) {
				Edge e = pq.remove();
				if (visited[e.to]) {
					continue;
				}
				visited[e.to] = true;
				for (Edge toEdge : list[e.to]) {
					pq.add(toEdge);
				}
				totalCost += e.cost;
			}
			System.out.println(totalCost);
		}
	}

	static class Node {
		int id;
		int x;
		int y;
		Node(int id, int x, int y) {
			this.id = id;
			this.x = x;
			this.y = y;
		}
	}

	static class Edge implements Comparable<Edge> {
		int from;
		int to;
		int cost;
		Edge(int f, int t, int c) {
			this.from = f;
			this.to = t;
			this.cost = c;
		}

		public int compareTo(Edge e){
			return this.cost - e.cost;
		}

	}
	static int getDist(Node n1, Node n2) {
		return Math.min(Math.abs(n1.x - n2.x), Math.abs(n1.y - n2.y));
	}


	static class ArrayUtils {
		public static Map<Integer, Integer> getCountMap(int[] array) {
			Map<Integer, Integer> map = new TreeMap<>();
			for (int x : array)
				map.merge(x, 1, Integer::sum);
			return map;
		}
	}

	static class InputReader {
		BufferedReader in;
		StringTokenizer tok;

		public String nextString() {
			while (!tok.hasMoreTokens()) {
				try {
					tok = new StringTokenizer(in.readLine(), " ");
				} catch (IOException e) {
					throw new InputMismatchException();
				}
			}
			return tok.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextString());
		}

		public long nextLong() {
			return Long.parseLong(nextString());
		}

		public int[] nextIntArray(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public long[] nextLongArray(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}

	}

}