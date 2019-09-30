import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class CMultithreaded {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;
	static Semaphore processorSemaphore = new Semaphore(Runtime.getRuntime().availableProcessors());
	static Semaphore inputSemaphore = new Semaphore(1);
	static Semaphore outputSemaphore = new Semaphore(0);
	static String[] output;
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
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
			String[] list = new String[n];
			for(int i = 0; i < n; i++) {
				list[i] = readLine();
			}
			
			/*
			 * PUT ALL INPUT CODE BEFORE THIS COMMENT
			 */
			inputSemaphore.release();
			
			ArrayList<String>[] tokenized = new ArrayList[n];
			for(int i = 0; i < n; i++) {
				tokenized[i] = new ArrayList<String>();
				StringTokenizer su = new StringTokenizer(list[i]);
				while(su.hasMoreTokens()) {
					tokenized[i].add(su.nextToken());
				}
			}
			
			int ret = Integer.MAX_VALUE;
			for(int mask = 2; mask < (1<<n); mask+=4) {
				Set<String> eng = new HashSet<String>();
				Set<String> fra = new HashSet<String>();
				for(int i = 0; i < n; i++) {
					boolean e = i == 0 || (mask&(1<<i)) == 0;
					Set<String> dest = e ? eng : fra;
					for(String out: tokenized[i]) {
						dest.add(out);
					}
				}
				int curr = 0;
				for(String out: eng) {
					if(fra.contains(out)) {
						curr++;
					}
				}
				ret = Math.min(ret, curr);
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
