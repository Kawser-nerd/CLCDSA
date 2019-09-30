import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "D-small-attempt0";

	public void solve(int test) throws IOException {
		out.print("Case #" + (test + 1) + ": ");
		int n = nextInt();
		int m = nextInt();
		long[][] edges = new long[n][(n + 63) / 64];
		for (int i = 0; i < m; ++i) {
			int u = nextInt();
			int v = nextInt();
			edges[u][v >> 6] |= 1L << (v & 63);
			edges[v][u >> 6] |= 1L << (u & 63);
		}
		int[] dist = new int[n];
		Arrays.fill(dist, -1);
		int[] q = new int[n];
		int qe = 1;
		q[0] = 0;
		dist[0] = 0;
		for (int qs = 0; qs < qe; ++qs) {
			int i = q[qs];
			for (int j = 0; j < n; ++j) {
				if (edge(edges, i, j) && dist[j] == -1) {
					q[qe++] = j;
					dist[j] = dist[i] + 1;
				}
			}
		}
		int d = dist[1];
		long[][] layers = new long[d + 1][(n + 63) / 64];
		for (int i = 0; i < n; ++i) {
			if (dist[i] != -1 && dist[i] <= d) {
				layers[dist[i]][i >> 6] |= 1L << (i & 63);
			}
		}
		if (d == 1) {
			out.println(0 + " " + (countAndOr(layers[0], edges[0]) + countAndOr(layers[1], edges[0])));
			return;
		}
		int[][] din = new int[n][n];
		for (int[] ar : din) {
			Arrays.fill(ar, -1);
		}
		for (int i = 0; i < n; ++i) {
			if (dist[i] == 1 && edge(edges, 0, i)) {
				din[0][i] = countAndOr(layers[0], edges[0], edges[i]) - 1;
			}
		}
		for (int l = 2; l < d; ++l) {
			for (int i = 0; i < n; ++i) {
				if (dist[i] != l - 2) {
					continue;
				}
				for (int j = 0; j < n; ++j) {
					if (dist[j] != l - 1 || din[i][j] == -1) {
						continue;
					}
					for (int k = 0; k < n; ++k) {
						if (dist[k] != l || !edge(edges, j, k)) {
							continue;
						}
						din[j][k] = Math.max(din[j][k], din[i][j] + countAndOr(layers[l - 1], edges[i], edges[j], edges[k]) - 1);
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (dist[i] != d - 2) {
				continue;
			}
			for (int j = 0; j < n; ++j) {
				if (dist[j] != d - 1 || din[i][j] == -1) {
					continue;
				}
				ans = Math.max(ans, din[i][j] + countAndOr(layers[d - 1], edges[i], edges[j]) - 1 + countAndOr(layers[d], edges[j]));
			}
		}
//		System.err.println(Arrays.toString(dist));
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < n; ++j) {
//				if (din[i][j] != -1) {
//					System.err.println(i + " " + j + " " + din[i][j]);
//				}
//			}
//		}
//		System.err.println();
		out.println((d - 1) + " " + ans);
	}

	private boolean edge(long[][] edges, int i, int j) {
		return (edges[i][j >> 6] & (1L << (j & 63))) != 0;
	}
	
	int countAndOr(long[] a, long[]... b) {
		int r = 0;
		for (int i = 0; i < a.length; ++i) {
			long v = 0;
			for (long[] bb : b) {
				v |= bb[i];
			}
			r += Long.bitCount(v & a[i]);
		}
		return r;
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(file + ".in"));
			out = new PrintWriter(file + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				solve(test);
			}
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			failed = true;
		}
	}
	
	void eat(String s) {
		st = new StringTokenizer(s, " \t,");
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	static boolean failed = false;
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Thread th = new Thread(new Solution());
		th.start();
		try {
			th.join();
		} catch (InterruptedException iex) {
		}
		if (failed) {
			throw new RuntimeException();
		}
	}
	
}
