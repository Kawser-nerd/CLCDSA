import java.util.*;
import java.io.*;


public class SolutionA {

	private static final class Solution implements Runnable {

		int testNum;
		
		static boolean isVowel(char c) { // a, e, i, o, and u
			return "aeiou".contains(Character.toString(c));
		}
		
		public static void init() {
		}
		
		@Override
		public void run() {
			String name;
			int n;
			synchronized (IO.lock) {
				testNum = IO.nextTest();
				name = IO.in.next();
				n = IO.in.nextInt();
			}

			long k = 0;
			int l = name.length();
			int seglen = 0, last = -1;
			for (int i = 0; i < l; i++) {
				if (isVowel(name.charAt(i)))
					seglen = 0;
				else 
					seglen++;
				if (seglen >= n)
					last = i - n + 1;
				if (last != -1)
					k += last + 1;
			}
			
			IO.add(testNum, Long.toString(k));
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
		IO.init("A-large.in", "out.txt");
		solve();
		IO.print();
	}

}


