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

	static Semaphore processorSemaphore = new Semaphore(
			Runtime.getRuntime().availableProcessors()
			//1
			);

	static Semaphore inputSemaphore = new Semaphore(1);
	static Semaphore outputSemaphore = new Semaphore(0);
	static String[] output;
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("d.out")));
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
		public int n;

		public WorkThread(int casenum) {
			super();
			this.casenum = casenum;
		}
		public void run() {

			n = readInt();
			boolean[][] can = new boolean[n][n];
			int on = 0;
			for(int i = 0; i < n; i++) {
				String s = nextToken();
				for(int j = 0; j < n; j++) {
					can[i][j] = s.charAt(j) == '1';
					if(can[i][j]) {
						on++;
					}
				}
			}

			/*
			 * PUT ALL INPUT CODE BEFORE THIS COMMENT
			 */
			inputSemaphore.release();

			int ret = Integer.MAX_VALUE;

			outer: for(int mask = 0; mask < 1<<(n*n); mask++) {
				if(Integer.bitCount(mask) >= ret) continue;
				if(Integer.bitCount(mask) < on) continue;
				for(int index = 0; index < n*n; index++) {
					if(can[index/n][index%n] && (mask&(1<<index)) == 0) {
						continue outer;
					}
				}
				if(dfs(mask, (1<<n)-1, (1<<n)-1)) {
					ret = Integer.bitCount(mask);
				}
			}

			/*
			 * PUT ALL WORK CODE BEFORE THIS COMMENT
			 * REMEMBER TO WRITE to output[casenum-1] the exact output
			 */

			output[casenum-1] = "Case #" + casenum + ": " + (ret - on);

			outputSemaphore.release();
			processorSemaphore.release();
		}

		public boolean dfs(int grid, int people, int squares) {
			// grid[a][b] means person a can operate thing b
			if(people == 0 && squares == 0) {
				return true;
			}
			int lowOrder = 0;
			while((people&(1<<lowOrder)) == 0) {
				lowOrder++;
			}
			outer: for(int mask = 0; mask <= people; mask++) {
				if((mask&(1<<lowOrder)) == 0) continue;
				int numOp = Integer.bitCount(mask);
				int[] on = new int[n];
				for(int i = 0; i < n; i++) {
					if((mask&(1<<i)) == 0) {
						continue;
					}
					for(int j = 0; j < n; j++) {
						boolean can = (grid&(1<<(n*i+j))) != 0;
						if(can && (squares & (1<<j)) == 0) { 
							continue outer;
						}
						if(can) {
							on[j]++;
						}
					}
				}
				int matchCount = 0;
				for(int out: on) {
					if(out != 0 && out != numOp) {
						continue outer;
					}
					if(out == numOp) {
						matchCount++;
					}
				}
				if(matchCount != numOp) {
					continue outer;
				}
				int newSquare = 0;
				for(int a = 0; a < n; a++) {
					if(on[a] == numOp) {
						newSquare |= 1 << a;
					}
				}
				if(dfs(grid, people ^ mask, squares ^ newSquare)) {
					return true;
				}
			}
			return false;
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
