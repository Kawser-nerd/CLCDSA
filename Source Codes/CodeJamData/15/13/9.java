import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class C {
	int n;
	Point[] p;
	
	String solve() {
		StringBuilder ans = new StringBuilder();
		for (int i = 0; i < n; i++) {
			Point[] q = new Point[n - 1];
			for (int j = 0, k = 0; j < n; j++) {
				if (j == i) {
					continue;
				}
				q[k] = p[j];
				k++;
			}
			Point z = p[i];
			int minRemove = n - 1;
			//
			Arrays.sort(q, new Comparator<Point>() {
				@Override
				public int compare(Point a, Point b) {
					int qA = quarterOrAxis(a.x - z.x, a.y - z.y);
					int qB = quarterOrAxis(b.x - z.x, b.y - z.y);
					int res = Integer.compare(qA, qB);
					if (res == 0) {
						res = orientation(z, b, a);
					}
					if (res != 0) {
						return res;
					}
					return Long.compare(a.x * 1L * a.x + a.y * 1L * a.y, b.x * 1L * b.x + b.y * 1L * b.y);
				}
			});
			for (int j = 0, k = 0; j < q.length; j++) {
				for (k = Math.min(k, j + 1);; k++) {
					if (k == j + q.length) {
						break;
					}
					if (orientation(z, q[j], q[k % q.length]) < 0) {
						break;
					}
				}
				minRemove = Math.min(minRemove, j + q.length - k);
			}
			//
			ans.append("\n").append(minRemove);
		}
		return ans.toString();
	}
	
	public C(Scanner in) {
		n = in.nextInt();
		p = new Point[n];
		for (int i = 0; i < n; i++) {
			p[i] = new Point(in);
		}
	}
	
	class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		public Point(Scanner in) {
			this(in.nextInt(), in.nextInt());
		}
	}
	
	static int orientation(Point a, Point b, Point c) {
		return orientation(a.x, a.y, b.x, b.y, c.x, c.y);
	}

	static int orientation(long xA, long yA, long xB, long yB, long xC, long yC) {
		return Long.signum(
				xA * yB - xB * yA +
				xB * yC - xC * yB +
				xC * yA - xA * yC
				);
	}
	
	static int quarterOrAxis(int x, int y) {
		if (y == 0) {
			if (x == 0) {
				return -1;
			}
			return x > 0 ? 0 : 4;
		}
		if (x == 0) {
			return y > 0 ? 2 : 6;
		}
		if (y > 0) {
			return x > 0 ? 1 : 3;
		}
		return x > 0 ? 7 : 5;
	}
	
	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	
	public static void main(String[] args) throws IOException, InterruptedException, ExecutionException {
		ExecutorService executor = Executors.newFixedThreadPool(4);
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new File(inputFileName));
		PrintWriter out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		@SuppressWarnings("unchecked")
		Future<String>[] outputs = new Future[tests];
		for (int t = 0; t < tests; t++) {
			final C testCase = new C(in);
			final int testCaseNumber = t;
			outputs[t] = executor.submit(new Callable<String>() {
				@Override
				public String call() {
					String answer = testCase.solve();
					String printed = "Case #" + (testCaseNumber + 1) + ": " + answer;
					System.out.println(printed);
					return printed;
				}
			});
		}
		for (int t = 0; t < tests; t++) {
			out.println(outputs[t].get());
		}
		in.close();
		out.close();
		executor.shutdown();
	}
}
