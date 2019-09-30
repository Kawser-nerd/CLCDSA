import java.util.*;
import java.io.*;


public class SolutionB {

	private static final class Solution implements Runnable {

		int testNum;
		
		public static void init() {
		}
		
		@Override
		public void run() {
			int x, y;
			synchronized (IO.lock) {
				testNum = IO.nextTest();
				x = IO.in.nextInt();
				y = IO.in.nextInt();
			}

			String ans = null;
			int l = 1, r = (int) 1e7;
			while (l * (l + 1) / 2 % 2 != Math.abs(x + y) % 2) l++;
			while (r * (r + 1) / 2 % 2 != Math.abs(x + y) % 2) r--;
			while (l < r) {
				int m = (l + r) / 2;
				while (m * (m + 1) / 2 % 2 != Math.abs(x + y) % 2) m--;
				int tx = x, ty = y;
				StringBuffer sb = new StringBuffer(m);
				for (int i = m; i > 0; i--) {
					if (Math.abs(tx) > Math.abs(ty)) {
						if (tx > 0) {
							tx -= i;
							sb.append('E');
						} else {
							tx += i;
							sb.append('W');
						}
					} else {
						if (ty > 0) {
							ty -= i;
							sb.append('N');
						} else {
							ty += i;
							sb.append('S');
						}
					}
				}
				if (tx == 0 && ty == 0) {
					r = m;
					ans = sb.reverse().toString();
				} else {
					l = m + 1;
					while (l * (l + 1) / 2 % 2 != Math.abs(x + y) % 2) l++;
				}
			}
			
			IO.add(testNum, ans);
		}
	}

	private static class IO {
		private static int testCount;
		private static volatile int testCounter = 0;
		public static volatile Scanner in;
		private static PrintWriter out;
		private static volatile String[] output;
		
		public static volatile Object lock;
		
		static void init(String fin, String fout) {
			try {
				IO.in = new Scanner(new File(fin));
				//IO.in = new Scanner(System.in);
				IO.out = new PrintWriter(new File(fout));
				lock = IO.in;
				setTestCount(in.nextInt());
			} catch (FileNotFoundException e) {
				System.out.println(e.getMessage());
				System.exit(0);
			}
		}
		
		private static void setTestCount(int testCount) {
			IO.testCount = testCount;
			output = new String[testCount];
		}
		
		public static int getTestCount() {
			return testCount;
		}
		
		static void add(int testNum, String ans) {
			output[testNum - 1] = ans;
		}
		
		static int nextTest() {
			return ++testCounter;
		}
		
		synchronized static void print() {
			for (int t = 0; t < testCount; t++)
				out.println("Case #" + (t + 1) + ": " + output[t]);
			out.close();
		}
		
	}

	
	static final int threadCount = 4;
	
	static void solveParallel() throws InterruptedException {
		Solution.init();
		Thread thread[] = new Thread[threadCount];
		for (int i = 0; i < IO.getTestCount(); i++) {
			int threadNum = i % threadCount;
			if (thread[threadNum] != null) thread[threadNum].join();
			thread[threadNum] = new Thread(null, new Solution(), String.valueOf(i), 10000000);
			thread[threadNum].start();
		}
		for (Thread th: thread) 
			if (th != null) th.join();
	}
	
	static void solve() {
		Solution.init();
		for (int i = 0; i < IO.getTestCount(); i++)	new Solution().run();
	}
	
	public static void main(String[] args) throws InterruptedException, FileNotFoundException {
		IO.init("B-large.in", "out.txt");
		solve();
		IO.print();
	}

}


