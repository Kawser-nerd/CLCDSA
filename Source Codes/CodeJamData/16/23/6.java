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
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static List<List<Integer>> edges;
	static int matchingL[], matchingR[];

	static int hopcroftKarp() {
		fill(matchingL, -1);
		fill(matchingR, -1);
		int queue[] = new int[2 * matchingL.length];
		int size = 0;
		while (true) {
			fill(hopcroftKarpDist, -1);
			int queueHead = 0, queueTail = 0;
			for (int i = 0; i < matchingL.length; i++) {
				if (matchingL[i] < 0) {
					queue[queueTail++] = i;
					queue[queueTail++] = 0;
				}
			}
			int resDist = -1;
			while (queueHead < queueTail) {
				int cur = queue[queueHead++];
				int cdist = queue[queueHead++];
				if ((cdist + Integer.MIN_VALUE) > (resDist + Integer.MIN_VALUE)) {
					break;
				}
				for (int next: edges.get(cur)) {
					if (hopcroftKarpDist[next] != -1) {
						continue;
					}
					hopcroftKarpDist[next] = cdist;
					int next2 = matchingR[next];
					if (next2 < 0) {
						resDist = cdist;
					} else {
						queue[queueTail++] = next2;
						queue[queueTail++] = cdist + 1;
					}
				}
			}
			if (resDist == -1) {
				return size;
			}
			for (int i = 0; i < matchingL.length; i++) {
				if (matchingL[i] < 0 && hopcroftKarpDfs(i, 0)) {
					++size;
				}
			}
		}
	}
	
	static int hopcroftKarpDist[];

	static boolean hopcroftKarpDfs(int cur, int cdist) {
		for (int next: edges.get(cur)) {
			if (hopcroftKarpDist[next] != cdist) {
				continue;
			}
			hopcroftKarpDist[next] = -1;
			int next2 = matchingR[next];
			if (next2 < 0 || hopcroftKarpDfs(next2, cdist + 1)) {
				matchingR[next] = cur;
				matchingL[cur] = next;
				return true;
			}
		}
		return false;
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		edges = new ArrayList<>();
		Map<String, Integer> first = new HashMap<>();
		Map<String, Integer> second = new HashMap<>();
		for (int i = 0; i < n; i++) {
			String fi = next();
			Integer fiI = first.get(fi);
			if (fiI == null) {
				first.put(fi, fiI = first.size());
				edges.add(new ArrayList<Integer>());
			}
			String se = next();
			Integer seI = second.get(se);
			if (seI == null) {
				second.put(se, seI = second.size());
			}
			edges.get(fiI).add(seI);
		}
		matchingL = new int[first.size()];
		matchingR = new int[second.size()];
		hopcroftKarpDist = new int[second.size()];
		int ans = n - first.size() - second.size() + hopcroftKarp();
		printCase();
		out.println(ans);
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