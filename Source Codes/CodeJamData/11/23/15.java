package gcj20011r1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	private static final String TASKNAME = "c";

	private void solve() throws Exception {
		int tN = nextInt();
		for (int test = 1; test <= tN; ++test) {
			printf("Case #%d: ", test);
			System.err.println("test " + test);
			int n = nextInt();
			int m = nextInt();
			int[] us = new int[m];
			int[] vs = new int[m];
			for (int i = 0; i < m; ++i) {
				us[i] = nextInt() - 1;
			}
			for (int i = 0; i < m; ++i) {
				vs[i] = nextInt() - 1;
				if (us[i] > vs[i]) {
					int t = us[i];
					us[i] = vs[i];
					vs[i] = t;
				}
			}
			ArrayList<HashSet<Integer>> masks = new ArrayList<HashSet<Integer>>();
			HashSet<Integer> all = new HashSet<Integer>();
			for (int i = 0; i < n; ++i) {
				all.add(i);
			}
			dfs(n, 0, all, us, vs, masks);
			int min = 100000;
			for (HashSet<Integer> mask : masks) {
				min = Math.min(min, mask.size());
			}
			println(min);
			int[] col = new int[n];
		
			this.min = min;
			rec(col, 0, n, masks);

//			final HashSet<Integer>[] comps = new HashSet[n];
//			for (int i = 0; i < comps.length; ++i) {
//				comps[i] = new HashSet<Integer>();
//			}
//
//			System.err.println(masks);
//			for (int c = 1; c <= min; ++c) {
//				for (int i = 0; i < n; ++i) {
//					comps[i].clear();
//				}
//				for (int i = 0; i < masks.size(); ++i) {
//					HashSet<Integer> set = masks.get(i);
//					for (int v : set) {
//						comps[v].add(i);
//					}
//				}
//				TreeSet<Integer> ver = new TreeSet<Integer>(new Comparator<Integer>() {
//					public int compare(Integer o1, Integer o2) {
//						int d = -(comps[o1].size() - comps[o2].size());
//						if (d == 0) {
//							return o1 - o2;
//						}
//						return d;
//					}
//				});
//				for (int i = 0; i < n; ++i) {
//					if (col[i] == 0) {
//						ver.add(i);
//					}
//				}
////				System.err.println(ver);
//				while (!ver.isEmpty()) {
//					int v = ver.first();
//					ver.remove(v);
//					if (comps[v].isEmpty()) {
//						break;
//					}
//					System.err.println("col " + (v+1) + " ?= " + c);
////					for (int i = 0; i < n; ++i) {
////						System.err.println(comps[i]);
////					}
//					col[v] = c;
//					for (int ind : comps[v]) {
//						for (int u : masks.get(ind)) {
//							if (u != v) {
//								if (!comps[u].remove(ind)) {
//									 throw new AssertionError(c + " " + masks.get(ind) + " " + u);
//								}
//							}
//						}
//					}
//				}
//			}
//
//			for (int i = 0; i < n; ++i) {
//				if (col[i] == 0) {
////					col[i] = 1;
//				}
//			}
			for (int i : col) {
				print(i + " ");
			}
			println("");
			writer.flush();

			for (HashSet<Integer> mask : masks) {
				HashSet<Integer> used = new HashSet<Integer>();
				for (int i : mask) {
					used.add(col[i]);
//					System.err.println("mask " + mask + " " + i + " " + col[i]);
				}
				if (used.size() != min) {
					throw new AssertionError(mask + " " + used);
				}
			}
		}
	}
	
	private int min;

	private boolean rec(int[] col, int pos, int n, ArrayList<HashSet<Integer>> masks) {
		if (pos == n) {
			for (HashSet<Integer> set : masks) {
				int c = 0;
				for (int u : set) {
					c |= 1 << col[u];
				}
				if (Integer.bitCount(c) != min) {
					return false;
				}
			}
			return true;
		}
		for (int i = 1; i <= min; ++i) {
			col[pos] = i;
			if (rec(col, pos + 1, n, masks)) {
				return true;
			}
		}
		return false;
	}

	private void dfs(int n, int pos, HashSet<Integer> set, int[] us, int[] vs, ArrayList<HashSet<Integer>> masks) {
		if (set.size() <= 2) {
			return;
		}
		if (pos == vs.length) {
			masks.add(set);
			return;
		}
		HashSet<Integer> set1 = new HashSet<Integer>();
		HashSet<Integer> set2 = new HashSet<Integer>();
		for (int i : set) {
			if (i >= us[pos] && i <= vs[pos]) {
				set1.add(i);
			}
			if (i <= us[pos] || i >= vs[pos]) {
				set2.add(i);
			}
		}
		dfs(n, pos + 1, set1, us, vs, masks);
		dfs(n, pos + 1, set2, us, vs, masks);
	}

	private void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new PrintWriter(new OutputStreamWriter(System.out));
			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
			writer = new PrintWriter(new File(TASKNAME + ".out"));

			solve();

			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(13);
		}
	}

	public static void main(String[] args) {
		long time = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		new Main().run();
		System.err.printf("%.3f\n", (System.currentTimeMillis() - time) * 1e-3);
	}

	private StringTokenizer tokenizer;
	private PrintWriter writer;
	private BufferedReader reader;

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private void print(Object o) {
		writer.print(o);
	}

	private void println(Object o) {
		writer.println(o);
	}

	private void printf(String format, Object... args) {
		writer.printf(format, args);
	}
}
