import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.stream.Stream;

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

	static int INF = 1 << 30;
	static int modP = 1000000007;

	@SuppressWarnings("unchecked")
	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			// input
			int n = in.nextInt(), m = in.nextInt();

			List<Edge>[] g = new ArrayList[n];
			g = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
			for (int i = 0; i < m; i++) {
				int a = in.nextInt()-1, b = in.nextInt()-1;
				g[a].add(new Edge(b, 1));
				g[b].add(new Edge(a, 1));
			}

			Queue<Integer> q = new ArrayDeque<>();

			int[] d = new int[n];
			Arrays.fill(d, INF);
			d[0] = 0;
			q.add(0);

			while (!q.isEmpty()) {
				int from = q.remove();

				for (int i = 0; i < g[from].size(); i++) {
					int to = g[from].get(i).toNodeNum;
					int c = g[from].get(i).weight;
					if (c >= 3) {
						break;
					}
					if (d[to] > d[from] + c) {
						d[to] = d[from] + c;
						q.add(to);
					}
				}
			}

			if (d[n-1] <= 2) {
				out.println("POSSIBLE");
			} else {
				out.println("IMPOSSIBLE");
			}

		}
	}

	@SuppressWarnings("rawtypes")
	/**
	 * ?????
	 * */
	static class MyComparator implements Comparator {

		public int compare(Object o1, Object o2) {

			Node n1 = (Node) o1;
			Node n2 = (Node) o2;

			int cost1 = n1.cost;
			int cost2 = n2.cost;

			if (cost1 > cost2) {
				return 1;
			} else if (cost1 < cost2) {
				return -1;
			} else {
				return 0;
			}
		}
	}

	static class Node {
		int nodeNum;
		int cost;

		public Node(int nodeNum, int weight) {
			this.nodeNum = nodeNum;
			this.cost = weight;
		}
	}
	static class Edge {
		int toNodeNum;
		int weight;

		public Edge(int nodeNum, int weight) {
			this.toNodeNum = nodeNum;
			this.weight = weight;
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

		public double nextDouble() {
			return Double.parseDouble(nextString());
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