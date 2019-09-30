import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class QualA {
	
	static void solve() {
		final int MAX = 1010, INF = 1<<28;
		int i, j, k, N, Q, min;
		String s;
		int[][] dp = new int[MAX][MAX];
		String[] se = new String[MAX];
		int T = Integer.parseInt(read());
		for (int t = 1; t <= T; t++) {
			N = Integer.parseInt(read());
			for (i = 0; i < N; i++)
				se[i] = read();
			Q = Integer.parseInt(read());
			for (i = 1; i <= Q; i++) {
				s = read();
				for (j = 0; j < N; j++) {
					dp[i][j] = INF;
					if (s.indexOf( se[j] ) == -1) {
						dp[i][j] = dp[i-1][j];
						for (k = 0; k < N; k++)
							dp[i][j] = Math.min(dp[i][j], dp[i-1][k] + 1);
					}
				}
			}
			min = INF;
			for (i = 0; i < N; i++)
				min = Math.min(min, dp[Q][i]);
			out.println("Case #" + t + ": " + min);
		}
	}
	
	static String read() {
		try { return in.readLine(); } catch (IOException e) { return null; }
	}
	public static void main(String[] args) throws IOException {
//		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(new BufferedOutputStream(System.out));
		in = new BufferedReader(new FileReader("A-large.in"));
		out = new PrintWriter( new FileOutputStream("A-large.out") );
		solve(); out.flush();
	}
	static BufferedReader in; static PrintWriter out;
}
