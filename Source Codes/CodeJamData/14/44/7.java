import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class TrieShardingLarge {

	FastScanner in;
	PrintWriter out;

	final int INF = Integer.MIN_VALUE / 2;
	final int MOD = (int) (1e9 + 7);

	long[] fact;
	long[] invFact;

	void precalc() {
		final int MAX = 100_000;
		fact = new long[MAX + 1];
		invFact = new long[MAX + 1];
		fact[0] = invFact[0] = 1;
		for (int i = 1; i <= MAX; i++) {
			fact[i] = (fact[i - 1] * i) % MOD;
			invFact[i] = BigInteger.valueOf(fact[i]).modInverse(BigInteger.valueOf(MOD))
					.longValue();
		}
	}
	
	long choose(int n, int k) {
		if (k < 0 || k > n) {
			return 0;
		}
		long ans = fact[n];
		ans = (ans * invFact[k]) % MOD;
		ans = (ans * invFact[n - k]) % MOD;
		return ans;
	}

	class Trie {
		int[][] next;
		int[] term;
		int states;

		public Trie(String[] s) {
			int len = 1;
			for (String str : s) {
				len += str.length();
			}

			next = new int[26][len];
			term = new int[len];
			states = 1;
			for (int[] i : next) {
				Arrays.fill(i, -1);
			}

			for (String str : s) {
				int st = 0;

				for (char c : str.toCharArray()) {
					if (next[c - 'A'][st] == -1) {
						next[c - 'A'][st] = states++;
					}
					st = next[c - 'A'][st];
				}
				term[st]++;
			}
		}

		long ans;
		long[][] dp;
		int n;

		void dp(int n) {
			this.n = n;
			this.dp = new long[states][n + 1];
			calc(0);
		}

		void calc(int u) {
			int sum = term[u];
			for (int i = 0; i < 26; i++) {
				if (next[i][u] != -1) {
					calc(next[i][u]);
					sum += term[next[i][u]];
				}
			}

			long[] auxDp = new long[n + 1];
			long[] tmpDp = new long[n + 1];
			auxDp[0] = 1;

			for (int i = 0; i < 26; i++) {
				if (next[i][u] != -1) {
					int child = next[i][u];
					int count = Math.min(n, term[child]);

					for (int prev = 0; prev <= n; prev++) {
						if (auxDp[prev] == 0) {
							continue;
						}

						for (int inter = 0; inter <= count && inter <= prev; inter++) {
							int newSize = prev + count - inter;
							if (newSize > n) {
								continue;
							}
							
							long mul = (choose(newSize, prev) * choose(prev, inter)) % MOD;
							mul = (mul * dp[child][count]) % MOD;
							
							tmpDp[newSize] = (tmpDp[newSize] + mul * auxDp[prev]) % MOD;
						}
					}

					System.arraycopy(tmpDp, 0, auxDp, 0, n + 1);
					Arrays.fill(tmpDp, 0);
				}
			}
			
			for (int i = 0; i < term[u]; i++) {
				int count = 1;

				for (int prev = 0; prev <= n; prev++) {
					if (auxDp[prev] == 0) {
						continue;
					}

					for (int inter = 0; inter <= count && inter <= prev; inter++) {
						int newSize = prev + count - inter;
						if (newSize > n) {
							continue;
						}
						
						long mul = (choose(newSize, prev) * choose(prev, inter)) % MOD;
						tmpDp[newSize] = (tmpDp[newSize] + mul * auxDp[prev]) % MOD;
					}
				}

				System.arraycopy(tmpDp, 0, auxDp, 0, n + 1);
				Arrays.fill(tmpDp, 0);
			}
			
			dp[u] = auxDp;
			
			term[u] = sum;
			ans += Math.min(n, sum);
		}
	}

	long[][] dp;

	void solve() {
		int m = in.nextInt(), n = in.nextInt();
		String[] s = new String[m];
		for (int i = 0; i < m; i++) {
			s[i] = in.nextToken();
		}

		Trie trie = new Trie(s);
		trie.dp(n);

		out.println(trie.ans + " " + trie.dp[0][n]);
	}

	void run() {
		try {
			in = new FastScanner("input.txt");
			out = new PrintWriter("output.txt");

			int T = in.nextInt();
			precalc();

			for (int i = 1; i <= T; i++) {
				long time = System.currentTimeMillis();
				out.printf("Case #%d: ", i);
				solve();
				System.err.println("Test #" + i + " done in " + (System.currentTimeMillis() - time)
						+ " ms");
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new TrieShardingLarge().run();
	}
}
