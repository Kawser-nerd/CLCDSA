import java.io.*;
import java.util.*;

public class Main {

	void submit() {
		char[] s = nextToken().toCharArray();
		int k = nextInt();
		
		int n = s.length;
		
		int[][][] dp = new int[k + 1][n][n];
		for (int z = 0; z <= k; z++) {
			
			int[][] now = dp[z];
			int[][] prev = z == 0 ? null : dp[z - 1];
			
			for (int i = 0; i < n; i++) {
				now[i][i] = 1;
			}
			
			for (int i = 0; i + 1 < n; i++) {
				if (s[i] == s[i + 1]) {
					now[i][i + 1] = 2;
				} else {
					now[i][i + 1] = z > 0 ? 2 : 1;
				}
			}
			
			for (int len = 3; len <= n; len++) {
				for (int i = 0; i + len - 1 < n; i++) {
					int j = i + len - 1;
					
					now[i][j] = Math.max(now[i + 1][j], now[i][j - 1]);
					if (s[i] == s[j]) {
						now[i][j] = Math.max(now[i][j], now[i + 1][j - 1] + 2);
					}
					
					if (z > 0) {
						now[i][j] = Math.max(now[i][j], prev[i + 1][j - 1] + 2);
					}
					
				}
			}
			
		}
		
		out.println(dp[k][0][n - 1]);
	}

	void preCalc() {

	}

	void stress() {

	}

//	int lsp(char[] s) {
//		int n = s.length;
//		int[][] dp = new int[n][n];
//		for (int i = 0; i < n; i++) {
//			dp[i][i] = 1;
//		}
//		
//		for (int i = 0; i + 1 < n; i++) {
//			if (s[i] == s[i + 1]) {
//				dp[i][i + 1] = 2;
//			} else {
//				dp[i][i + 1] = 1;
//			}
//		}
//		
//		for (int len = 3; len <= n; len++) {
//			for (int i = 0; i + len - 1 < n; i++) {
//				int j = i + len - 1;
//				
//				dp[i][j] = Math.max(dp[i + 1][j], now[i + 1][j]);
//				if (s[i] == s[j]) {
//					now[i][j] = Math.max(now[i][j], now[i + 1][j - 1] + 2);
//				}
//				
//				if (z > 0) {
//					now[i][j] = Math.max(now[i][j], prev[i + 1][j - 1] + 2);
//				}
//				
//			}
//		}
//	}
	
	void test() {
//		char[] s = "atcodergrandcontest".toCharArray();
//		for (int i = 0; i < s.length; i++) {
//			for (int j = i + 1; j < s.length; j++) {
//				for (int k = j + 1; k < s.length; k++) {
//					char[] s1 = s.clone();
//					s1[i] = s1[j] = s1[k] = '?';
//					ans = Math.max(ans, lsp(s1));
//				}
//			}
//		}
//		System.err.println(ans);
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		//stress();
		//test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
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