import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class AFast {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;
	static Semaphore processorSemaphore = new Semaphore(Runtime.getRuntime().availableProcessors());
	static Semaphore inputSemaphore = new Semaphore(1);
	static Semaphore outputSemaphore = new Semaphore(0);
	static String[] output;

	static String[][] dp;

	public static void main(String[] args) throws Exception {
		dp = new String[13][3];
		dp[0][0] = "P";
		dp[0][1] = "R";
		dp[0][2] = "S";
		for(int i = 1; i < 13; i++) {
			for(int j = 0; j < 3; j++) {
				int k = 0;
				while(j == k) k++;
				int l = 0;
				while(j == l || k == l) l++;
				String a = dp[i-1][k];
				String b = dp[i-1][l];
				if(a.compareTo(b) > 0) {
					String t = a;
					a = b;
					b = t;
				}
				dp[i][j] = a + b;
			}
		}
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
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

	static class State {
		public int level;
		public int p;
		public int r;
		public int s;
		public State(int level, int p, int r, int s) {
			super();
			this.level = level;
			this.p = p;
			this.r = r;
			this.s = s;
		}
		public State genParent() {
			return new State(level+1, p+r, r+s, s+p);
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + level;
			result = prime * result + p;
			result = prime * result + r;
			result = prime * result + s;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (level != other.level)
				return false;
			if (p != other.p)
				return false;
			if (r != other.r)
				return false;
			if (s != other.s)
				return false;
			return true;
		}

	}

	static class WorkThread extends Thread {
		public int casenum;

		public WorkThread(int casenum) {
			super();
			this.casenum = casenum;
		}
		public void run() {

			int n = readInt();
			int r = readInt();
			int p = readInt();
			int s = readInt();

			/*
			 * PUT ALL INPUT CODE BEFORE THIS COMMENT
			 */
			inputSemaphore.release();

			String ret = "IMPOSSIBLE";
			for(String amt: dp[n]) {
				int rr = 0;
				int pp = 0;
				int ss = 0;
				for(int i = 0; i < amt.length(); i++) {
					if(amt.charAt(i) == 'P') pp++;
					if(amt.charAt(i) == 'R') rr++;
					if(amt.charAt(i) == 'S') ss++;
				}
				if(r == rr && p == pp && s == ss) {
					ret = amt;
					break;
				}
			}

			output[casenum-1] = "Case #" + casenum + ": " + ret;

			/*
			 * PUT ALL WORK CODE BEFORE THIS COMMENT
			 * REMEMBER TO WRITE to output[casenum-1] the exact output
			 */
			
			outputSemaphore.release();
			processorSemaphore.release();
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
