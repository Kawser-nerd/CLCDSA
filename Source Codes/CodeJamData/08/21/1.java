import java.io.*;
import java.util.*;

public class TrianglesFast implements Runnable {
	private final String problemID = getClass().getName() + "_small";
	private BufferedReader in;
	private PrintWriter out;
	
	private void solveSingleTest(int testNumber) throws IOException {
		Scanner sc = new Scanner(in.readLine());
		int n = sc.nextInt();
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		long d = sc.nextLong();
		long x0 = sc.nextLong();
		long y0 = sc.nextLong();
		long m = sc.nextLong();
		
		long[] x = new long[n];
		long[] y = new long[n];
		x[0] = x0;
		y[0] = y0;
		for (int i = 1; i < n; i++) {
			x0 = (a * x0 + b) % m;
			y0 = (c * y0 + d) % m;
			x[i] = x0;
			y[i] = y0;
		}
		long[] points = new long[9];
		for (int i = 0; i < n; i++) {
			int xx = (int) ((x[i] % 3) + 3) % 3;
			int yy = (int) ((y[i] % 3) + 3) % 3;
			points[3 * xx + yy]++;
		}
		
		long answer = 0;
		for (int t1 = 0; t1 < 9; t1++) {
			for (int t2 = t1 + 1; t2 < 9; t2++) {
				for (int t3 = t2 + 1; t3 < 9; t3++) {
					int xx = (t1 % 3) + (t2 % 3) + (t3 % 3);
					int yy = (t1 / 3) + (t2 / 3) + (t3 / 3);
					xx = xx % 3;
					yy = yy % 3;
					if (xx != 0 || yy != 0) {
						continue;
					}
					answer = answer + points[t1] * points[t2] * points[t3];
				}
			}
		}
		for (int t1 = 0; t1 < 9; t1++) {
			for (int t2 = 0; t2 < 9; t2++) {
				if (t1 == t2) {
					continue;
				}
				int xx = 2 * (t1 % 3) + (t2 % 3);
				int yy = 2 * (t1 / 3) + (t2 / 3);
				xx = xx % 3;
				yy = yy % 3;
				if (xx != 0 || yy != 0) {
					continue;
				}
				answer = answer + (points[t1] * (points[t1] - 1) * points[t2]) / 2; 
			}
		}
		for (int t1 = 0; t1 < 9; t1++) {
			answer = answer + (points[t1] * (points[t1] - 1) * (points[t1] - 2)) / 6;
		}
		
		out.println("Case #" + testNumber + ": " + answer);
	}

	private void solve() throws IOException {
		in = new BufferedReader(new FileReader(new File(problemID + ".in")));
		out = new PrintWriter(new File(problemID + ".out"));
		
		int testsNumber = Integer.parseInt(in.readLine());
		for (int testNumber = 1; testNumber <= testsNumber; testNumber++) {
			solveSingleTest(testNumber);
		}
		
		in.close();
		out.close();
	}
	
	public static void main(String[] args) {
		new Thread(new TrianglesFast()).start();
	}

	public void run() {
		try {
			solve();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
