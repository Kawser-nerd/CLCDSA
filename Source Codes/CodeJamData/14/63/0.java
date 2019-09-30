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
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Edge {
		final int to;
		Edge pair;
		int ident = -1;
		public Edge(int to) {
			this.to = to;
		}
	}
	
	static Map<List<Integer>, Integer> ident;
	
	static void solve() throws Exception {
		int n = nextInt();
		char color[] = new char[n];
		for (int i = 0; i < n; i++) {
			color[i] = next().charAt(0);
		}
		List<Edge> edges[] = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			Edge ea = new Edge(b);
			Edge eb = new Edge(a);
			ea.pair = eb;
			eb.pair = ea;
			edges[a].add(ea);
			edges[b].add(eb);
		}
		ident = new HashMap<>();
//		for (List<Edge> ee: edges) {
//			for (Edge e: ee) {
//				getIdent(edges, e);
//			}
//		}
		List<Integer> curRank = new ArrayList<>();
		int rank[] = new int[n];
		fill(rank, -1);
		int rankedNeighbours[] = new int[n];
		for (int i = 0; i < n; i++) {
			if (edges[i].size() == 1) {
				curRank.add(i);
			}
		}
		int cRank = 0;
		while (true) {
			List<Integer> nextRank = new ArrayList<>();
			for (int i: curRank) {
				rank[i] = cRank;
				for (Edge e: edges[i]) {
					if (++rankedNeighbours[e.to] == edges[e.to].size() - 1) {
						nextRank.add(e.to);
					}
				}
			}
			if (nextRank.isEmpty()) {
				break;
			}
			++cRank;
			curRank = nextRank;
		}
		if (curRank.size() == 1) {
			int p = curRank.get(0);
			Set<Integer> unpaired = new HashSet<>();
			for (Edge e: edges[p]) {
				int i = getIdent(edges, color, e);
				if (!unpaired.add(i)) {
					unpaired.remove(i);
				}
			}
			List<Integer> unpairedL = new ArrayList<>(unpaired);
			if (unpairedL.size() <= 2) {
				for (Edge e: edges[p]) {
					if (unpairedL.contains(getIdent(edges, color, e)) && !checkRay(edges, color, e)) {
						printCase();
						out.println("NOT SYMMETRIC");
						return;
					}
				}
				printCase();
				out.println("SYMMETRIC");
				return;
			} else {
				printCase();
				out.println("NOT SYMMETRIC");
				return;
			}
		} else if (curRank.size() == 2) {
			int p1 = curRank.get(0);
			int p2 = curRank.get(1);
			for (Edge e: edges[p1]) {
				if (e.to == p2) {
					if (getIdent(edges, color, e) == getIdent(edges, color, e.pair) ||
						(checkRay(edges, color, e) && checkRay(edges, color, e.pair))) {
						printCase();
						out.println("SYMMETRIC");
					} else {
						printCase();
						out.println("NOT SYMMETRIC");
					}
					return;
				}
			}
		}
		throw new AssertionError();
	}
	
	static int getIdent(List<Edge> edges[], char color[], Edge cur) {
		if (cur.ident >= 0) {
			return cur.ident;
		}
		List<Integer> idx = new ArrayList<>();
		for (Edge next: edges[cur.to]) {
			if (next == cur.pair) {
				continue;
			}
			idx.add(getIdent(edges, color, next));
		}
		Collections.sort(idx);
		idx.add((int) color[cur.to]);
		Integer res = ident.get(idx);
		if (res == null) {
			ident.put(idx, res = ident.size());
		}
		cur.ident = res;
		return res;
	}
	
	static boolean checkRay(List<Edge> edges[], char color[], Edge cur) {
		Set<Integer> unpaired = new HashSet<>();
		for (Edge e: edges[cur.to]) {
			if (e == cur.pair) {
				continue;
			}
			int i = getIdent(edges, color, e);
			if (!unpaired.add(i)) {
				unpaired.remove(i);
			}
		}
		List<Integer> unpairedL = new ArrayList<>(unpaired);
		if (unpairedL.size() <= 1) {
			for (Edge e: edges[cur.to]) {
				if (e == cur.pair) {
					continue;
				}
				if (unpairedL.contains(getIdent(edges, color, e)) && !checkRay(edges, color, e)) {
					return false;
				}
			}
			return true;
		} else {
			return false;
		}
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
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}