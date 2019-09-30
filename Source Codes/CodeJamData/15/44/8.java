import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class D {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("d.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			pw.printf("Case #%d: ", casenum);
			int r = readInt();
			int c = readInt();
			long[][][] dp = new long[r+1][3][13];
			dp[0][0][1] = 1;
			final long MOD = 1000000007;
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < dp[i].length; j++) {
					for(int k = 0; k < dp[i][j].length; k++) {
						if(dp[i][j][k] == 0) continue;
						if(j != 1) {
							dp[i+1][1][k] += dp[i][j][k];
							dp[i+1][1][k] %= MOD;
						}
						if(i+2 < dp.length && j != 1 && c%3 == 0) {
							int amt = 3;
							dp[i+2][1][lcm(k,3)] += amt * dp[i][j][k];
							dp[i+2][1][lcm(k,3)] %= MOD;
						}
						if(i+2 < dp.length && j != 1 && c%6 == 0) {
							int amt = 6;
							dp[i+2][1][lcm(k,6)] += amt * dp[i][j][k];
							dp[i+2][1][lcm(k,6)] %= MOD;
						}
						if(i+2 < dp.length && j != 2) {
							dp[i+2][2][k] += dp[i][j][k];
							dp[i+2][2][k] %= MOD;
						}
						if(i+3 < dp.length && j != 1 && c%4 == 0) {
							int amt = 4;
							dp[i+3][1][lcm(k,4)] += amt * dp[i][j][k];
							dp[i+3][1][lcm(k,4)] %= MOD;
						}
					}
				}
			}
			long ret = 0;
			for(int j = 0; j < dp[r].length; j++) {
				for(int k = 0; k < dp[r][j].length; k++) {
					ret += dp[r][j][k] * modpow(k, MOD-2, MOD);
					ret %= MOD;
				}
			}
			pw.println(ret);
		}
		pw.close();
	}

	public static int lcm(int a, int b) {
		return a/gcd(a,b)*b;
	}
	public static int gcd(int a, int b) {
		return a%b==0?b:gcd(b,a%b);
	}

	public static long modpow(long b, long e, long m) {
		long r = 1;
		while(e > 0) {
			if(e%2==1) {
				r*=b;
				r%=m;
			}
			b*=b;
			b%=m;
			e/=2;
		}
		return r;
	}

	public static int readInt() {
		return Integer.parseInt(nextToken());
	}

	public static long readLong() {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() {
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() {
		while(st == null || !st.hasMoreTokens())	{
			try {
				if(!br.ready())	{
					pw.close();
					System.exit(0);
				}
				st = new StringTokenizer(br.readLine());
			}
			catch(IOException e) {
				System.err.println(e);
				System.exit(1);
			}
		}
		return st.nextToken();
	}

	public static String readLine()	{
		st = null;
		try {
			return br.readLine();
		}
		catch(IOException e) {
			System.err.println(e);
			System.exit(1);
			return null;
		}
	}

}
