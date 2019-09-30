import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.LARGE;
	static final int ATTEMPT_NUMBER = 0;

	void solve() throws IOException {
		int a = nextInt();
		int b = nextInt();
		int k = nextInt();
		
		long[][][] dp = new long[2][2][2]; // 0 - less, 1 - equal
		dp[1][1][1] = 1;
		
		for (int bit = 29; bit >= 0; bit--) {
			long[][][] next = new long[2][2][2];
			
			int bitA = (a >> bit) & 1;
			int bitB = (b >> bit) & 1;
			int bitK = (k >> bit) & 1;
			
			for (int prevA = 0; prevA < 2; prevA++) {
				for (int prevB = 0; prevB < 2; prevB++) {
					for (int prevK = 0; prevK < 2; prevK++) {
						for (int putA = 0; putA < 2; putA++) {
							for (int putB = 0; putB < 2; putB++) {
								if (putA == 1 && prevA == 1 && bitA == 0) {
									continue;
								}
								if (putB == 1 && prevB == 1 && bitB == 0) {
									continue;
								}
								int putK = putA & putB;
								if (putK == 1 && prevK == 1 && bitK == 0) {
									continue;
								}
								
								int newA = prevA == 1 && putA == bitA ? 1 : 0;
								int newB = prevB == 1 && putB == bitB ? 1 : 0;
								int newK = prevK == 1 && putK == bitK ? 1 : 0;
								next[newA][newB][newK] += dp[prevA][prevB][prevK];
							}
						}
					}
				}
			}
			
			dp = next;
		}
		
		out.println(dp[0][0][0]);
		
	}

	B() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("B-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("B-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("B-large.in"));
			out = new PrintWriter("B-large.out");
			break;
		}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println("Test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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