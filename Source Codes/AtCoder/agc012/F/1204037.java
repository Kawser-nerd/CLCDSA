import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int f(int x) {
		x = Math.abs(x);
		return Math.max(x - 1, 0);
	}
	
	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[2 * n - 1];
		for (int i = 0; i < 2 * n - 1; i++) {
			a[i] = nextInt();
		}
		Arrays.sort(a);
		int[][] dp = {{}, {1} };
		for (int i = 1; i < n; i++) {
			int addL = a[n - i] != a[n - 1 - i] ? 1 : 0;
			int addR = a[n - 1 + i] != a[n - 2 + i] ? 1 : 0;
			
			int[][] nxt = new int[2 * i + 2][2 * i + 2];
			for (int cnt = 1; cnt <= 2 * i - 1; cnt++) {
				for (int place = 0; place < cnt; place++) {
					
					int realCnt = cnt + addL + addR;
					int realPlace = place + addL;
					
					for (int toPlace = 0; toPlace < realCnt; toPlace++) {
						int newCnt = realCnt - f(toPlace - realPlace);
						int newPlace = toPlace <= realPlace ? toPlace : realPlace + 1;
						
						nxt[newCnt][newPlace] += dp[cnt][place];
						if (nxt[newCnt][newPlace] >= P) {
							nxt[newCnt][newPlace] -= P;
						}
					}
					
				}
			}
			dp = nxt;
		}
		
		long ret = 0;
		for (int[] row : dp) {
			for (int val : row) {
				ret += val;
			}
		}
		
		out.println(ret % P);
	}
	
	static final int P = 1_000_000_007;

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}