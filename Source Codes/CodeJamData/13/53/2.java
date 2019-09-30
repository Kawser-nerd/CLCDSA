import static java.lang.Math.min;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class C {

	static void solveMultiTest() throws IOException {
		int testCases = nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			out.print("Case #" + testCase + ": ");
			solveOneTest();
			System.err.println("solved "+testCase+"/"+testCases);
		}
	}

	static void solveOneTest() throws IOException {
		int n = nextInt();
		int edges = nextInt();
		int path = nextInt();
		Edge[] e = new Edge[edges];
		for (int i = 0; i < edges; i++) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			int a = nextInt();
			int b = nextInt();
			e[i] = new Edge(u, v, a, b, i);
		}

		Edge[] list = new Edge[path];
		for (int i = 0; i < path; i++) {
			list[i] = e[nextInt() - 1];
		}

		Edge[] originalList = list.clone();

		for (int i = 1; i < path; i++) {
			if (list[i - 1].to != list[i].from) {
				throw new AssertionError();
			}
		}
		int start = list[0].from;
		int finish = list[path - 1].to;
		boolean[] was = new boolean[n];
		was[start] = true;

		int firstRealBad = -1;
		for (int i = 0; i < path; i++) {
			if (was[list[i].to]) {
				firstRealBad = i;
				break;
			}
			was[list[i].to] = true;
		}

		if (firstRealBad < 0) {
			firstRealBad = list.length;
		}

		int left = -1;
		int right = firstRealBad;
		while (right - left > 1) {
			int mid = right + left >> 1;
			Edge[] list2 = copyOf(list, mid + 1);
			boolean ok = canBeShortestPath(n, e, list2, finish);
			if (ok) {
				left = mid;
			} else {
				right = mid;
			}
		}
//		System.err.println(right+" "+list.length);

		if (right == list.length) {
			out.println("Looks Good To Me");
		} else {
			out.println(originalList[right].id + 1);
		}

	}

	static boolean canBeShortestPath(int n, Edge[] allEdges, Edge[] list,
			int finish) {
		if (list.length == 0) {
			return true;
		}
//		System.err.println("checking "+list.length);
		int edges = allEdges.length;
		boolean[] onPath = new boolean[edges];
		for (Edge edge : list) {
			onPath[edge.id] = true;
		}

		final int INF = Integer.MAX_VALUE / 2;
		int[][] d = new int[n][n];
		for (int[] dd : d) {
			fill(dd, INF);
		}

		for (Edge edge : allEdges) {
			int w = edge.b;
			if (onPath[edge.id]) {
				w = edge.a;
				continue;
			}
			if (d[edge.from][edge.to] > w) {
				d[edge.from][edge.to] = w;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				int[] di = d[i];
				int[] dk = d[k];
				if (di[k] == INF) {
					continue;
				}
				for (int j = 0; j < n; j++) {
					int ok = di[k] + dk[j];
					if (ok < di[j]) {
						di[j] = ok;
					}
				}
			}
		}
		int[] listVertexList = new int[list.length + 1];
		int[] sumWeights = new int[list.length + 1];

		listVertexList[0] = list[0].from;
		for (int i = 0; i < list.length; i++) {
			listVertexList[i + 1] = list[i].to;
			sumWeights[i + 1] = sumWeights[i] + list[i].a;
		}

		for (int i = 0; i < list.length + 1; i++) {
			for (int j = i + 1; j < list.length + 1; j++) {
				int ourPath = sumWeights[j] - sumWeights[i];
				int theirPath = d[listVertexList[i]][listVertexList[j]];
				if (ourPath > theirPath) {
					return false;
				}
			}
		}

		if (list[list.length - 1].to == finish) {
			return true;
		}

		int[] goodD = new int[n];
		int[] badD = new int[n];
		fill(badD, INF);
		fill(goodD, INF);

		for (int i = 0; i < list.length; i++) {
			int u = list[i].from;
			for (int v = 0; v < n; v++) {
				badD[v] = min(badD[v], d[u][v] + sumWeights[i]);
			}
		};

		int last = list[list.length - 1].to;

//		System.err.println("finish "+finish);
//		System.err.println(Arrays.toString(goodD));
//		System.err.println(Arrays.toString(badD));
//		System.err.println(Arrays.toString(sumWeights));

		boolean[] was = new boolean[n];
		for (int i = 0; i < list.length; i++) {
			was[list[i].from] = true;
			was[list[i].to] = true;
		}
		was[last] = false;
		goodD[last] = sumWeights[list.length];
		while (goodD[finish] > badD[finish]) {
			int closest = -1;
			for (int go = 0; go < n; go++) {
				if (goodD[go] > badD[go] || was[go]) {
					continue;
				}
				if (goodD[go] == INF) {
					continue;
				}
				if (closest < 0 || goodD[closest] > goodD[go]) {
					closest = go;
				}
			}
			if (closest < 0) {
				break;
			}
			was[closest] = true;

			for (Edge edge : allEdges) {
				if (edge.from != closest) {
					continue;
				}
				goodD[edge.to] = min(goodD[edge.to], goodD[closest] + edge.a);
			}
		}
		if (goodD[finish] <= badD[finish]) {
			return true;
		} else {
			return false;
		}
	}

	static class Edge {
		int from, to, a, b, id;

		public Edge(int from, int to, int a, int b, int id) {
			this.from = from;
			this.to = to;
			this.a = a;
			this.b = b;
			this.id = id;
		}

		@Override
		public String toString() {
			return "Edge [from=" + from + ", to=" + to + ", a=" + a + ", b="
					+ b + ", id=" + id + "]";
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("c.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream(new File("c.out"));
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solveMultiTest();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
}
