import java.util.*;
import java.io.*;

class IO {
	int testNum;
	static volatile int testCounter = 0;
	static volatile Scanner in;
	static volatile PrintWriter out;
	static void setIO(Scanner in, PrintWriter out) {
		IO.in = in;
		IO.out = out;
	}
}
/*
final class SolutionC extends IO implements Runnable {

	@Override
	public void run() {
		synchronized (in) {
			testNum = ++testCounter;
		}

			
		synchronized (out) {
			out.println("Case #" + testNum + ": ");

			out.println();
			out.flush();
		}
	}
}
*/

final class SolutionC extends IO implements Runnable {
	
	@Override
	public void run() {
		testNum = ++testCounter;
		int n = in.nextInt(), m = in.nextInt();
		long[] a = new long[n + 1], b = new long[m + 1];
		int[] A = new int[n + 1], B = new int[m + 1];
		for (int i = 1; i <= n; i++) {
			a[i] = in.nextLong();
			A[i] = in.nextInt();
		}
		for (int i = 1; i <= m; i++) {
			b[i] = in.nextLong();
			B[i] = in.nextInt();
		}
		
		long[][] x = new long[n + 1][m + 1];
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				long t = Math.max(x[i][j - 1], x[i - 1][j]), c = 0;
				int u = i, v = j, type = B[j];
				long uk = a[i], vk = b[j];
				while (u > 0 && v > 0) {
					if (A[u] == B[v]) {
						if (uk < vk) {
							c += uk;
							vk -= uk;
							uk = a[--u];
						} else if (uk > vk) {
							c += vk;
							uk -= vk;
							vk = b[--v];
						} else {
							t = Math.max(t, c + uk + x[u - 1][v - 1]);
							break;
						}
					} else if (A[u] == type) {
						t = Math.max(t, c + x[u - 1][v]);
						vk = b[--v];
					} else if (B[v] == type) {
						t = Math.max(t, c + x[u][v - 1]);
						uk = a[--u];
					} else System.out.println("WTF?!");
					t = Math.max(t, c);
				};
				x[i][j] = t;
			}
		out.println("Case #" + testNum + ": " + x[n][m]);
	}
}

public class Solution {
	
	static final int threadCount = 4;
	
	static void solveParallel(int testCount) throws InterruptedException {
		Thread thread[] = new Thread[threadCount];
		for (int i = 0; i < testCount; i++) {
			int threadNum = i % threadCount;
			if (thread[threadNum] != null) thread[threadNum].join();
			thread[threadNum] = new Thread(null, new SolutionC(), String.valueOf(i), 1000000);
			thread[threadNum].start();
		}
		for (Thread th: thread) 
			if (th != null) th.join();
	}
	
	static void solve(int testCount) {
		for (int i = 0; i < testCount; i++)	new SolutionC().run();
	}
	
	public static void main(String[] args) throws InterruptedException, FileNotFoundException {
		Scanner in = new Scanner(new FileInputStream("C-large.in"));
		PrintWriter out = new PrintWriter(new File("out.txt"));
		//Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		IO.setIO(in, out);
		
		int testCount = in.nextInt();
		solve(testCount);
		
		out.close();
	}

}
