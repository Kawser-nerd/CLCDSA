import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;

/*
		  br = new BufferedReader(new FileReader("input.txt"));
		  pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		  br = new BufferedReader(new InputStreamReader(System.in));
		  pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			boolean[] bColor = new boolean[2*n];
			int[] val = new int[2*n];
			ArrayList<Integer> bLoc = new ArrayList<>();
			ArrayList<Integer> wLoc = new ArrayList<>();
			int[] bRev = new int[n];
			int[] wRev = new int[n];
			for(int i = 0; i < 2*n; i++) {
				String s = nextToken();
				bColor[i] = s.equals("B");
				val[i] = readInt()-1;
				if(bColor[i]) {
					bRev[val[i]] = i;
					bLoc.add(i);
				}
				else {
					wRev[val[i]] = i;
					wLoc.add(i);
				}
			}
			BIT[] bbits = new BIT[n+1];
			for(int i = 0; i < bbits.length; i++) {
				bbits[i] = new BIT(2*n);
				for(int j = 0; j < i; j++) {
					bbits[i].update(bRev[j], 1);
				}
			}
			BIT[] wbits = new BIT[n+1];
			for(int i = 0; i < wbits.length; i++) {
				wbits[i] = new BIT(2*n);
				for(int j = 0; j < i; j++) {
					wbits[i].update(wRev[j], 1);
				}
			}
			long[][] dp = new long[n+1][n+1];
			for(int a = 0; a < dp.length; a++) {
				Arrays.fill(dp[a], 1L << 50);
			}
			dp[0][0] = 0;
			for(int i = 1; i <= 2*n; i++) {
				for(int a = 0; a <= n; a++) {
					int b = i-a;
					if(b >= 0 && b <= n) {
						if(a > 0) {
							dp[a][b] = Math.min(dp[a][b], dp[a-1][b] + a+b-1 - wbits[a-1].query(wRev[a-1]) - bbits[b].query(wRev[a-1]));
						}
						if(b > 0) {
							dp[a][b] = Math.min(dp[a][b], dp[a][b-1] + a+b-1 - wbits[a].query(bRev[b-1]) - bbits[b-1].query(bRev[b-1]));
						}
					}
				}
			}
			pw.println(dp[n][n]);
		}
		exitImmediately();
	}

	static class BIT {
		public int[] leaf;
		public BIT(int n) {
			leaf = new int[n+5];
		}
		public void update(int index, int val) {
			index += 2;
			while(index < leaf.length) {
				leaf[index] += val;
				index += index & -index;
			}
		}
		public int query(int index) {
			int ret = 0;
			index += 2;
			while(index > 0) {
				ret += leaf[index];
				index -= index & -index;
			}
			return ret;
		}
	}
	
	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextLine() throws IOException  {
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(nextLine().trim());
		}
		return st.nextToken();
	}
}