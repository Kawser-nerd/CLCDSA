import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	private int[] p;
	
	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; ++test) {
			int k = nextInt();
			char[] s = next().toCharArray();
			int[][] diff = new int[k][k];
			for (int i = 0; i < s.length; i += k) {
				for (int u = 0; u < k; ++u) {
					for (int v = 0; v < k; ++v) {
						diff[u][v] += s[i + u] != s[i + v] ? 1 : 0;
					}
				}
			}
			int[][] diff2 = new int[k][k];
			for (int i = 0; i < s.length - k; i += k) {
				for (int u = 0; u < k; ++u) {
					for (int v = 0; v < k; ++v) {
						diff2[u][v] += s[i + u] != s[i + k + v] ? 1 : 0;
					}
				}
			}
			int[][][] d = new int[1 << k][k][k];
			for (int[][] ar : d) {
				for (int[] br : ar) {
					Arrays.fill(br, s.length + 1);
				}
			}
			for (int u = 0; u < k; ++u) {
				d[1 << u][u][u] = 0;
			}
			for (int m = 0; m < 1 << k; ++m) {
				for (int u = 0; u < k; ++u) {
					for (int v = 0; v < k; ++v) {
						if (d[m][u][v] == s.length + 1) {
							continue;
						}
						for (int w = 0; w < k; ++w) {
							if ((m & (1 << w)) != 0) {
								continue;
							}
							d[m ^ (1 << w)][u][w] = Math.min(d[m ^ (1 << w)][u][w], d[m][u][v] + diff[v][w]);
						}
					}
				}
			}
			int ans = s.length + 1;
			for (int u = 0; u < k; ++u) {
				for (int v = 0; v < k; ++v) {
					ans = Math.min(ans, d[(1 << k) - 1][u][v] + diff2[v][u] + 1);
				}
			}
			out.println("Case #" + test + ": " + ans);
		}
	}

	private int rec(int i, int k, char[] s) {
		if (i == k) {
			char[] ss = new char[s.length];
			for (int a = 0; a < s.length; a += k) {
				for (int b = 0; b < k; ++b) {
					ss[a + b] = s[a + p[b]];
				}
			}
			int res = 1;
			for (int a = 0; a < ss.length - 1; ++a) {
				if (ss[a] != ss[a + 1]) {
					res++;
				}
			}
			return res;
		}
		int res = Integer.MAX_VALUE;
		loop: for (p[i] = 0; p[i] < k; ++p[i]) {
			for (int j = 0; j < i; ++j) {
				if (p[i] == p[j]) {
					continue loop;
				}
			}
			res = Math.min(res, rec(i + 1, k, s));
		}
		return res;
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			st = new StringTokenizer("");
			out = new PrintWriter(System.out);
			
			solve();
			
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
			System.exit(-1);
		}
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}

	private void ass(boolean b) {
		if (!b) {
			throw new RuntimeException("Assertion failed");
		}
	}
	
	static final boolean Ъ = true;
}