import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Solution {

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	private String filename = "small-1";

	int n, m;
	boolean[][] g;

	int[] s, e;

	int[] stack;

	boolean check(int size) {
		for (int i = 0; i < size; ++i)
			for (int j = i + 2; j < size; ++j) {
				int v = stack[i];
				int u = stack[j];
				if (i == 0 && j == size - 1)
					continue;
				if (g[v][u])
					return false;
			}
		return true;
	}

	HashSet<ArrayList<Integer>> set = new HashSet<ArrayList<Integer>>();
	HashSet<Integer>[] cycles;

	void save(int size) {
		ArrayList<Integer> l = new ArrayList<Integer>();
		for (int i = 0; i < size; ++i) {
			l.add(stack[i]);
		}
		Collections.sort(l);
		set.add(l);
	}

	boolean[] was;

	void rec(int v, int start, int step) {
		stack[step] = v;
		if (v == start && step > 0) {
			if (step == 2)
				return;
			if (check(step)) {
				save(step);
			}
			return;
		}
		if (was[v])
			return;
		was[v] = true;
		for (int i = 0; i < n; ++i)
			if (g[v][i]) {
				int u = i;
				if (u == start || was[u] == false)
					rec(u, start, step + 1);
			}
		was[v] = false;
	}

	int[] colors;

	boolean checkColors(int max) {
		ArrayList<Integer>[] c = new ArrayList[max];
		for (int i = 0; i < c.length; i++) {
			c[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n; ++i)
			c[colors[i]].add(i);
		for (int i = 0; i < cycles.length; ++i) {
			HashSet<Integer> set = cycles[i];
			for (int j = 0; j < max; ++j) {
				boolean ok = false;
				for (int k = 0; k < c[j].size(); ++k)
					if (set.contains(c[j].get(k))) {
						ok = true;
						break;
					}
				if (ok == false)
					return false;
			}
		}
		return true;
	}

	boolean bruteColors(int max, int step, int mask) {
		if (step == n) {
			if (Integer.bitCount(mask) == max && checkColors(max))
				return true;
			return false;
		}
		for (int i = 0; i < max; ++i) {
			colors[step] = i;
			int nextMask = mask | (1 << i);
			if (bruteColors(max, step + 1, nextMask))
				return true;
		}
		return false;
	}

	void solve() throws IOException {
		int tests = ni();
		for (int test = 1; test <= tests; ++test) {
			n = ni();
			m = ni();
			g = new boolean[n][n];
			s = new int[m];
			e = new int[m];
			for (int i = 0; i < m; ++i) {
				s[i] = ni() - 1;
			}
			for (int i = 0; i < m; ++i)
				e[i] = ni() - 1;
			for (int i = 0; i < m; ++i) {
				g[s[i]][e[i]] = true;
				g[e[i]][s[i]] = true;
			}
			for (int i = 0; i < n; ++i) {
				int j = (i + 1) % n;
				g[i][j] = g[j][i] = true;
			}
			set.clear();
			stack = new int[20];
			was = new boolean[n];
			for (int i = 0; i < n; ++i)
				rec(i, i, 0);
			cycles = new HashSet[set.size()];
			Iterator<ArrayList<Integer>> it = set.iterator();
			for (int i = 0; i < set.size(); ++i) {
				cycles[i] = new HashSet<Integer>();
			}
			int step = 0;
			for (; it.hasNext(); step++) {
				ArrayList<Integer> l = it.next();
				cycles[step] = new HashSet<Integer>();
				for (int i = 0; i < l.size(); ++i)
					cycles[step].add(l.get(i));
			}
			colors = new int[n];
			int ret = -1;
			for (int i = n; i >= 1; --i) {
				if (bruteColors(i, 0, 0)) {
					ret = i;
					break;
				}
			}
			out.println("Case #" + test + ": " + ret);
			for (int i = 0; i < n; ++i) {
				if (i > 0)
					out.print(" ");
				out.print(colors[i] + 1);
			}
			out.println();
		}
	}

	public Solution() throws IOException {
		in = new BufferedReader(new FileReader(filename + ".in"));
		out = new PrintWriter(filename + ".out");
		solve();
		in.close();
		out.close();
	}

	String ns() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int ni() throws IOException {
		return Integer.valueOf(ns());
	}

	long nl() throws IOException {
		return Long.valueOf(ns());
	}

	double nd() throws IOException {
		return Double.valueOf(ns());
	}

	public static void main(String[] args) throws IOException {
		new Solution();
	}
}
