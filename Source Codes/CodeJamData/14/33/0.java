import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class C {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;
	static Semaphore processorSemaphore = new Semaphore(Runtime.getRuntime().availableProcessors());
	static Semaphore inputSemaphore = new Semaphore(1);
	static Semaphore outputSemaphore = new Semaphore(0);
	static String[] output;
	static int[] dx = new int[]{-1,1,0,0};
	static int[] dy = new int[]{0,0,-1,1};

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new FileReader("c.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
		final int MAX_CASES = readInt();
		output = new String[MAX_CASES];
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			processorSemaphore.acquire();
			inputSemaphore.acquire();
			new WorkThread(casenum).start();
		}
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			outputSemaphore.acquire();
		}
		for(String out: output) {
			pw.println(out);
		}
		pw.close();
	}

	static class WorkThread extends Thread {
		public int casenum;

		public WorkThread(int casenum) {
			super();
			this.casenum = casenum;
		}
		public void run() {


			int n = readInt();
			int m = readInt();
			int k = readInt();

			inputSemaphore.release();

			int ret = k;
			final int INF = 1 << 25;
			int[][] dp = new int[m+1][k+1];
			for(int i = 0; i < dp.length; i++) {
				Arrays.fill(dp[i], INF);
			}
			for(int i = 1; i <= m; i++) {
				dp[i][Math.min(i, k)] = i;
			}
			for(int numRow = 2; numRow <= n; numRow++) {
				int[][] next = new int[m+1][k+1];
				for(int a = 0; a < next.length; a++) {
					Arrays.fill(next[a], INF);
				}
				for(int a = 1; a <= m; a++) {
					for(int b = 1; b <= k; b++) {
						int need = k - b;
						if(need > 0 && need <= m) {
							if(need >= a-2) {
								ret = Math.min(ret, dp[a][b] + need);
							}
						}
						for(int change = -2; change <= 2; change++) {
							int nextCol = a + change;
							if(nextCol >= 1 && nextCol <= m) {
								next[nextCol][Math.min(k, b + nextCol)] = Math.min(dp[a][b] + Math.min(2, nextCol), next[nextCol][Math.min(k, b + nextCol)]);
							}
						}
					}
				}
				dp = next;
				/*
				pw.println("ROW " + numRow);
				for(int a = 0; a < dp.length; a++) {
					for(int b = 0; b < dp[a].length; b++) {
						if(dp[a][b] < INF) {
							pw.println(a + " " + b + ": " + dp[a][b]);
						}
					}
				}
				*/
			}

			output[casenum-1] =  String.format("Case #%d: %d", casenum, ret);

			outputSemaphore.release();
			processorSemaphore.release();
		}

		static class State {
			public int x,y;

			public State(int x, int y) {
				super();
				this.x = x;
				this.y = y;
			}

		}
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
