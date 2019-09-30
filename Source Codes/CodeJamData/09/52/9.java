import static java.lang.System.nanoTime;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	private static final int MOD = 10009;
	
	static class CE {
		int n;
		int k;
		int perm[];
		
		public CE(int n, int k, int perm[]) {
			this.n = n;
			this.k = k;
			this.perm = new int[perm.length];
			Arrays.fill(this.perm, -1);
			int cnt = 0;
			for (int i = 0; i < perm.length; i++) {
				if (this.perm[i] == -1) {
					for (int j = i; j < perm.length; j++) {
						if (perm[j] == perm[i]) {
							this.perm[j] = cnt;
						}
					}
					++cnt;
				}
			}
		}
		
		public boolean equals(Object o) {
			if (o instanceof CE) {
				CE ce = (CE) o;
				return ce.n == n && ce.k == k && Arrays.equals(ce.perm, perm);
			}
			return false;
		}
		
		public int hashCode() {
			return n + 31 * k + 10009 * Arrays.hashCode(perm);
		}
	}
	
	private static final Map<CE, Integer> cache = new HashMap<CE, Integer>();
	
	private static int permCount(int n, int k, int perm[]) {
		CE ce = new CE(n, k, perm);
		if (cache.containsKey(ce)) {
			return cache.get(ce);
		}
		int map[] = new int[perm.length];
		int ans = 0;
		int constr[] = new int[k];
		while (true) {
			Arrays.fill(constr, -1);
			boolean good = true;
			for (int i = 0; i < perm.length; i++) {
				int pos = map[i];
				int pp = perm[i];
				if (constr[pos] == -1 || constr[pos] == pp) {
					constr[pos] = pp;
				} else {
					good = false;
					break;
				}
			}
			if (good) {
				int prod = 1;
				for (int i = 0; i < k; i++) {
					if (constr[i] == -1) {
						prod = prod * n % MOD;
					}
				}
				ans = (ans + prod) % MOD;
			}
			for (int i = map.length - 1; ; i--) {
				if (map[i] < k - 1) {
					++map[i];
					for (int j = i + 1; j < map.length; j++) {
						map[j] = 0;
					}
					break;
				}
				if (i == 0) {
					cache.put(ce, ans);
					return ans;
				}
			}
		}
	}
	
	private static int norm(int n) {
		return (n % MOD + MOD) % MOD;
	}
	
	private static int getAns(int n, int cnts[][], int p) {
		int ans = 0;
		int ad = 1;
		List<int[]> badPerms = new ArrayList<int[]>();
		for (int i = 0; i < cnts.length; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				sum = (sum + cnts[i][j]) % MOD;
			}
			ad = (ad * sum) % MOD;
		}
		int p2[] = new int[cnts.length];
		for (int i = 0; i < p2.length; i++) {
			p2[i] = i;
		}
		if (p2.length > 1) {
			p2[1] = 0;
		}
		int p2c = permCount(n, p, p2);
		if (cnts.length > 1) {
			for (int i = 0; i < n; i++) {
				if (cnts.length > 2) {
					for (int j = 0; j < n; j++) {
						if (cnts.length > 3) {
							for (int m = 0; m < n; m++) {
								if (i == j || j == m || i == m) {
									for (int q = 0; q < n; q++) {
										int pa = 0;
										if (i == j) {
											++pa;
										}
										if (i == m) {
											++pa;
										}
										if (i == q) {
											++pa;
										}
										if (j == m) {
											++pa;
										}
										if (j == q) {
											++pa;
										}
										if (m == q) {
											++pa;
										}
										if (pa == 1) {
//											badPerms.add(new int[] {i, j, m, q});
											int cnt = cnts[0][i] * cnts[1][j] % MOD * cnts[2][m] % MOD * cnts[3][q] % MOD;
											ad = norm(ad - cnt);
											ans = norm(ans + cnt * p2c);
										} else {
											badPerms.add(new int[] {i, j, m, q});
										}
									}
								} else {
//									badPerms.add(new int[] {i, j, m, i});
//									badPerms.add(new int[] {i, j, m, j});
//									badPerms.add(new int[] {i, j, m, m});
									int cnt = cnts[0][i] * cnts[1][j] % MOD * cnts[2][m] % MOD * cnts[3][i] % MOD;
									ad = norm(ad - cnt);
									ans = norm(ans + cnt * p2c);
									cnt = cnts[0][i] * cnts[1][j] % MOD * cnts[2][m] % MOD * cnts[3][j] % MOD;
									ad = norm(ad - cnt);
									ans = norm(ans + cnt * p2c);
									cnt = cnts[0][i] * cnts[1][j] % MOD * cnts[2][m] % MOD * cnts[3][m] % MOD;
									ad = norm(ad - cnt);
									ans = norm(ans + cnt * p2c);
								}
							}
						} else {
							if (i == j) {
								for (int m = 0; m < n; m++) {
									badPerms.add(new int[] {i, j, m});
								}
							} else {
								badPerms.add(new int[] {i, j, i});
								badPerms.add(new int[] {i, j, j});
							}
						}
					}
				} else {
//					badPerms.add(new int[] {i, i});
					ad = norm(ad - cnts[0][i] * cnts[1][i]);
					ans = norm(ans + cnts[0][i] * cnts[1][i] % MOD * p2c);
				}
			}
		}
		for (int[] perm: badPerms) {
			int mul = 1;
			for (int i = 0; i < cnts.length; i++) {
				mul = (mul * cnts[i][perm[i]]) % MOD;
			}
			ad = (ad - mul + MOD) % MOD;
			ans = (ans + mul * permCount(n, p, perm)) % MOD;
		}
		{
			int perm[] = new int[cnts.length];
			for (int i = 0; i < perm.length; i++) {
				perm[i] = i;
			}
			ans = (ans + ad * permCount(n, p, perm)) % MOD;
		}
		return ans;
	}
	
	public static void main(String args[]) throws Exception {
		long time = nanoTime();
		in = new BufferedReader(new InputStreamReader(new FileInputStream("b.in")));
		out = new PrintWriter(new OutputStreamWriter(new FileOutputStream("b.out")));
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			String expr = next();
			int k = nextInt();
			int n = nextInt();
			String words[] = new String[n];
			for (int i = 0; i < n; i++) {
				words[i] = next();
			}
			StringTokenizer exprParser = new StringTokenizer(expr, "+");
			int ans[] = new int[k];
			while (exprParser.hasMoreTokens()) {
				String term = exprParser.nextToken();
				int cnts[][] = new int[term.length()][n];
				for (int i = 0; i < term.length(); i++) {
					char c = term.charAt(i);
					for (int j = 0; j < n; j++) {
						String word = words[j];
						for (int m = 0; m < word.length(); m++) {
							if (word.charAt(m) == c) {
								++cnts[i][j];
							}
						}
						cnts[i][j] %= MOD;
					}
				}
				for (int p = 1; p <= k; p++) {
					if (term.equals("a") && p == 2) {
						System.out.println();
					}
					ans[p - 1] = (ans[p - 1] + getAns(n, cnts, p)) % MOD;
				}
			}
			out.print("Case #" + (t + 1) + ":");
			for (int p = 0; p < k; p++) {
				out.print(" " + ans[p]);
			}
			out.println();
			out.flush();
		}
		in.close();
		out.close();
		System.out.println(nanoTime() - time);
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
}