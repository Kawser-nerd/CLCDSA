import java.util.*;
import java.io.*;
import java.math.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	public void solve() throws Exception {
		int tests = sc.nextInt();
		outer:
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			int k = sc.nextInt() - 1;
			
			int bitA [] = new int [32];
			int bitB [] = new int [32];
			int bitK [] = new int [32];
			
			for (int bit = 30; bit >= 0; bit--) {
				bitA[bit + 1] = (a & (1 << bit)) != 0 ? 1 : 0;
				bitB[bit + 1] = (b & (1 << bit)) != 0 ? 1 : 0;
				bitK[bit + 1] = (k & (1 << bit)) != 0 ? 1 : 0;
			}
			
			long dp[][][][] = new long [32][2][2][2];
			dp[31][1][1][1] = 1;
			for (int bit = 31; bit >= 1; bit--)
				for (int holdA = 0; holdA <= 1; holdA++)
					for (int holdB = 0; holdB <= 1; holdB++)
						for (int holdK = 0; holdK <= 1; holdK++) {
							int rA = 1; if (holdA == 1) rA = bitA[bit];
							int rB = 1; if (holdB == 1) rB = bitB[bit];
							int rK = 1; if (holdK == 1) rK = bitK[bit];
							for (int iA = 0; iA <= rA; iA++) {
								for (int iB = 0; iB <= rB; iB++) {
									int place = iA & iB;
									int nHoldA = (iA == rA && holdA == 1) ? 1 : 0;
									int nHoldB = (iB == rB && holdB == 1) ? 1 : 0;
									if (place <= rK) {
										int nHoldK = (place == rK && holdK == 1) ? 1 : 0;
										dp[bit - 1][nHoldA][nHoldB][nHoldK] += dp[bit][holdA][holdB][holdK];
									}
								}
							}
						}
			
			long result = 0;
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					for (int l = 0; l < 2; l++)
						result += dp[0][i][j][l];
			
			out.println(result);
		}
	}


	static Throwable t;

	BufferedReader in;
	FastScanner sc;
	PrintWriter out;

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(System.out);
			sc = new FastScanner(in);
			solve();
		} catch (Throwable t) {
			Solution.t = t;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread thread = new Thread(null, new Solution(), "", 1 << 26);
		thread.start();
		thread.join();
		if (Solution.t != null)
			throw t;
	}

}

class FastScanner {

	BufferedReader in;
	StringTokenizer st;

	public FastScanner(BufferedReader in) {
		this.in = in;
	}

	public String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	public int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

}