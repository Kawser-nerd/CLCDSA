import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Solution {
	
	final String f = "D-large";
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	final long mod = 1000000007;

	void solve() throws IOException {
		long n0 = nextLong();
		int b = nextInt();
		ArrayList<Integer> list = new ArrayList<Integer>();
		while (n0 > 0) {
			list.add((int) (n0 % b));
			n0 /= b;
		}
		int n = list.size();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = list.get(i);
		}
		long[][] d0 = new long[b + 1][b * b + 1];
		d0[0][0] = 1;
		for (int i = 1; i < b; ++i) {
			long[][] t = new long[b + 1][b * b + 1];
			for (int u = 0; u <= b; ++u) {
				for (int v = 0; v <= b * b; ++v) {
					t[u][v] = (t[u][v] + d0[u][v]) % mod;
					if (d0[u][v] != 0) {
						t[u + 1][v + i] = (t[u + 1][v + i] + d0[u][v]) % mod;
					}
				}
			}
			d0 = t;
		}
		long[][] c = new long[b + 1][b + 1];
		for (int i = 0; i <= b; ++i) {
			for (int j = 1; j < i; ++j) {
				c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
			}
			c[i][0] = c[i][i] = 1;
		}
		long[] fact = new long[b + 1];
		fact[0] = 1;
		for (int i = 1; i <= b; ++i) {
			fact[i] = (fact[i - 1] * i) % mod;
		}
		long[][][] d = new long[2][b + 1][b];
		for (int i = 0; i <= b; ++i) {
			d[0][i][0] = 1;
		}
		for (int i = 0; i < n; ++i) {
			long[][][] t = new long[2][b + 1][b];
			for (int u = 0; u <= b; ++u) {
				for (int v = 0; v < b; ++v) {
					for (int uu = i == 0 ? u : 0; uu <= u; ++uu) {
						for (int w = (a[i] + b - v) % b; w < b * b; w += b) {
							long add = (d[0][u][v] * c[u][uu]) % mod;
							if (uu > 0) {
								add = (add + d[1][u][v] * c[u - 1][uu - 1]) % mod;
							}
							if (i != 0) {
								add = (add * fact[uu]) % mod;
							}
							if ((w + v - a[i]) % b != 0) {
								throw new AssertionError();
							}
							int vv = (w + v - a[i]) / b;
							if (vv >= b) {
								continue;
							}
							t[0][uu][vv] = (t[0][uu][vv] + add * d0[uu][w]) % mod;
							if (uu > 0) {
								t[1][uu][vv] = (t[1][uu][vv] + add * d0[uu - 1][w]) % mod;
							}
						}
					}
				}
			}
			d = t;
		}
		long ans = 0;
		for (int i = 0; i <= b; ++i) {
			ans = (ans + d[0][i][0]) % mod;
		}
//		long inv2 = BigInteger.valueOf(2).modInverse(BigInteger.valueOf(mod)).longValue();
//		ans = (ans * inv2) % mod;
		out.println(ans);
	}

	Solution() throws IOException {
		in = new BufferedReader(new FileReader(f + ".in"));
		out = new PrintWriter(f + ".out");
		
		eat("");
		
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			System.out.println("Test #" + (test + 1));
			out.print("Case #" + (test + 1) + ": ");
			solve();
		}
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
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

	public static void main(String[] args) throws IOException {
		new Solution();
	}
}
