import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Edge {
		final int from, to;
		int reverseCap;
		
		Edge(int from, int to) {
			this.from = from;
			this.to = to;
		}
	}

	static List<Edge> edges1[]; // End to sentence
	static List<Edge> rEdges1[]; // Sentence to end
	static List<Edge> edges2[]; // Sentence to start
	static List<Edge> rEdges2[]; // Start to sentence
	static boolean iEdges[];
	static boolean seen1[]; // Start
	static boolean seen2[]; // Sentence
	static boolean seen3[]; // End
	static boolean sink[];

	static String i2w(int i) {
		char res[] = new char[5];
		for (int j = 0; j < 5; j++) {
			res[j] = (char) ('a' + (i % 26));
			i /= 26;
		}
		return new String(res);
	}
	
	static void solve() throws Exception {
//		StringBuilder sb = new StringBuilder();
//		sb.append("200\n");
//		for (int i = 0; i < 200; i++) {
//			if (i < 2) {
//				for (int j = 0; j < 1000; j++) {
//					if (j > 0) {
//						sb.append(' ');
//					}
//					sb.append(i2w(i * 3000 + j));
//				}
//			} else {
//				for (int j = 0; j < 10; j++) {
//					if (j > 0) {
//						sb.append(' ');
//					}
//					sb.append(i2w(j < 5 ? i * 5 + j : i * 5 + j + 3000));
//				}
//			}
//			sb.append('\n');
//		}
//		in = new BufferedReader(new StringReader(sb.toString()));
		int n = nextInt();
		Map<String, Integer> wordMap = new HashMap<>();
		List<List<Edge>> edges1L = new ArrayList<>();
		rEdges1 = new List[n];
		edges2 = new List[n];
		List<List<Edge>> rEdges2L = new ArrayList<>();
		List<Integer> sourceL = new ArrayList<>();
		List<Integer> sinkL = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			rEdges1[i] = new ArrayList<>();
			edges2[i] = new ArrayList<>();
			for (String word: in.readLine().split(" +")) {
				Integer id = wordMap.get(word);
				if (id == null) {
					wordMap.put(word, id = wordMap.size());
					edges1L.add(new ArrayList<Edge>());
					rEdges2L.add(new ArrayList<Edge>());
				}
				Edge e = new Edge(id, i);
				edges1L.get(id).add(e);
				rEdges1[i].add(e);
				e = new Edge(i, id);
				edges2[i].add(e);
				rEdges2L.get(id).add(e);
				if (i == 0) {
					sourceL.add(id);
				} else if (i == 1) {
					sinkL.add(id);
				}
			}
		}
		seen2 = new boolean[n];
		n = wordMap.size();
		edges1 = edges1L.toArray(new List[n]);
		rEdges2 = rEdges2L.toArray(new List[n]);
		iEdges = new boolean[n];
		seen1 = new boolean[n];
		seen3 = new boolean[n];
		sink = new boolean[n];
		for (int id: sinkL) {
			sink[id] = true;
		}
		int flow = 0;
		for (int source: sourceL) {
			fill(seen1, false);
			fill(seen2, false);
			fill(seen3, false);
			if (dfs1(source)) {
				++flow;
			}
		}
		printCase();
		out.println(flow);
	}
	
	static boolean dfs1(int cur) {
		if (seen1[cur]) {
			return false;
		}
		seen1[cur] = true;
		if (!iEdges[cur]) {
			iEdges[cur] = true;
			if (dfs3(cur)) {
				return true;
			}
			iEdges[cur] = false;
		}
		for (Edge e: rEdges2[cur]) {
			if (e.reverseCap > 0) {
				--e.reverseCap;
				if (dfs2(e.from)) {
					return true;
				}
				++e.reverseCap;
			}
		}
		return false;
	}
	
	static boolean dfs2(int cur) {
		if (seen2[cur]) {
			return false;
		}
		seen2[cur] = true;
		for (Edge e: rEdges1[cur]) {
			if (e.reverseCap > 0) {
				--e.reverseCap;
				if (dfs3(e.from)) {
					return true;
				}
				++e.reverseCap;
			}
		}
		for (Edge e: edges2[cur]) {
			++e.reverseCap;
			if (dfs1(e.to)) {
				return true;
			}
			--e.reverseCap;
		}
		return false;
	}	
	
	static boolean dfs3(int cur) {
		if (seen3[cur]) {
			return false;
		}
		seen3[cur] = true;
		if (sink[cur]) {
			return true;
		}
		if (iEdges[cur]) {
			iEdges[cur] = false;
			if (dfs1(cur)) {
				return true;
			}
			iEdges[cur] = true;
		}
		for (Edge e: edges1[cur]) {
			++e.reverseCap;
			if (dfs2(e.to)) {
				return true;
			}
			--e.reverseCap;
		}
		return false;
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
				System.err.println("TEST " + test);
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}