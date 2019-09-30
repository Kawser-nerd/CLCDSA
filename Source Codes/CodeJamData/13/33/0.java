import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Attack implements Comparable<Attack> {
		int time, left, right, strength;

		Attack(int time, int left, int right, int strength) {
			this.time = time;
			this.left = left;
			this.right = right;
			this.strength = strength;
		}
		
		public int compareTo(Attack o) {
			return time - o.time;
		}
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		List<Attack> attacksL = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int di = nextInt();
			int ni = nextInt();
			int wi = nextInt();
			int ei = nextInt();
			int si = nextInt();
			int ddi = nextInt();
			int dpi = nextInt();
			int dsi = nextInt();
			for (int j = 0; j < ni; j++) {
				attacksL.add(new Attack(di, wi, ei, si));
				di += ddi;
				wi += dpi;
				ei += dpi;
				si += dsi;
			}
		}
		Attack attacks[] = (Attack[]) attacksL.toArray(new Attack[attacksL.size()]);
		sort(attacks);
		int points[] = new int[2 * attacks.length];
		for (int i = 0; i < attacks.length; i++) {
			points[2 * i] = attacks[i].left;
			points[2 * i + 1] = attacks[i].right;
		}
		sort(points);
		int numPoints = 0;
		for (int i = 0, prev = Integer.MIN_VALUE; i < points.length; i++) {
			if (points[i] != prev) {
				points[numPoints++] = points[i];
			}
		}
		for (int i = 0; i < attacks.length; i++) {
			attacks[i].left = binarySearch(points, 0, numPoints, attacks[i].left);
			attacks[i].right = binarySearch(points, 0, numPoints, attacks[i].right);
		}
		treeSize = 1;
		while (treeSize < numPoints - 1) {
			treeSize *= 2;
		}
		treeMin = new int[treeSize * 2];
		int ans = 0;
		for (int i = 0; i < attacks.length;) {
			int j;
			for (j = i; j < attacks.length && attacks[j].time == attacks[i].time; j++) {
				if (treeMin(attacks[j].left, attacks[j].right) < attacks[j].strength) {
					++ans;
				}
			}
			for (int jj = i; jj < j; jj++) {
				treeUpdate(attacks[jj].left, attacks[jj].right, attacks[jj].strength);
			}
			i = j;
		}
		printCase();
		out.println(ans);
	}

	static int treeSize;
	static int treeMin[];

	static int treeMin(int from, int to) {
		return treeMin(1, 0, treeSize, from, to);
	}
	
	static int treeMin(int cur, int l, int r, int from, int to) {
		if (from >= r || to <= l) {
			return Integer.MAX_VALUE;
		}
		int ans = treeMin[cur];
		if (from > l || to < r) {
			int mid = (l + r) >>> 1;
			ans = max(ans, min(treeMin(cur << 1, l, mid, from, to), treeMin((cur << 1) + 1, mid, r, from, to)));
		}
		return ans;
	}

	static void treeUpdate(int from, int to, int value) {
		treeUpdate(1, 0, treeSize, from, to, value);
	}
	
	static void treeUpdate(int cur, int l, int r, int from, int to, int value) {
		if (from >= r || to <= l) {
			return;
		}
		if (from <= l && r <= to) {
			treeMin[cur] = max(treeMin[cur], value);
		} else {
			int mid = (l + r) >>> 1;
			treeUpdate(cur << 1, l, mid, from, to, value);
			treeUpdate((cur << 1) + 1, mid, r, from, to, value);
			treeMin[cur] = max(treeMin[cur], min(treeMin[cur << 1], treeMin[(cur << 1) + 1]));
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