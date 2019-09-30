import java.util.*;
import java.io.*;

public class SolB2 {

	public static void main(String[] args) {
		try {
			new SolB2().run();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void run() throws IOException {
		br = new BufferedReader(new FileReader(FNAME + ".in"));
		out = new PrintWriter(FNAME + ".out");
		solve();
		out.close();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}
	
	String FNAME = "B-large";
	
	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			char[][] s = new char[n][];
			for (int i = 0; i < n; i++) {
				s[i] = nextToken().toCharArray();
			}
			long ans = 1;
			
			int[] cntOnly = new int[26];
			int[] left = new int[26];
			int[] right = new int[26];
			boolean[] u = new boolean[26];
			
			for (int i = 0; i < n; i++) {
				for (char ch : s[i]) {
					u[ch - 'a'] = true;
				}
				char[] tmp = s[i].clone();
				Arrays.sort(tmp);
				if (tmp[0] == tmp[tmp.length  - 1]) {
					cntOnly[tmp[0] - 'a']++;
				} else {
					for (int j = 0; j < s[i].length - 1; j++) {
						u[s[i][j] - 'a'] = true;
						if (s[i][j] != s[i][j + 1]) {
							if (left[s[i][j + 1] - 'a'] != 0) {
								ans = 0;
							} else {
								left[s[i][j + 1] - 'a'] = s[i][j];
							}
							if (right[s[i][j] - 'a'] != 0) {
								ans = 0;
							} else {
								right[s[i][j] - 'a'] = s[i][j + 1];
							}
						}
					}
					u[s[i][s[i].length - 1] - 'a'] = true;
				}
				
			}
			
			if (ans != 0) {
				int cnt1 = 0;
				int cnt2 = 0;
				for (int i = 0; i < 26; i++) {
					if (u[i]) {
						for (int j = 1; j <= cntOnly[i]; j++) {
							ans *= j;
							ans %= MOD;
						}
						if (left[i] == 0) {
							cnt1++;
						}
						if (right[i] == 0) {
							cnt2++;
						}
					}
				}
				if (cnt1 != cnt2 || cnt1 == 0) {
					ans = 0;
				} else {
					for (int j = 1; j <= cnt1; j++) {
						ans *= j;
						ans %= MOD;
					}
				}
			}
			
			out.println(ans);
		}
	}
	
	long MOD = 1000000007;
}

