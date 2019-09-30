import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class B {
	static class Point {
		long x, y;

		Point sub(Point p) {
			return new Point(x - p.x, y - p.y);
		}

		long vect(Point p) {
			return x * p.y - y * p.x;
		}

		long sqAbs() {
			return x * x + y * y;
		}

		public Point(long x, long y) {
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}
	}

	static class ByAngle implements Comparator<Point> {

		public int compare(Point o1, Point o2) {
			long q = o1.x * o2.y - o2.x * o1.y;
			if (q > 0)
				return -1;
			if (q < 0)
				return 1;
			return Long.signum(o1.sqAbs() - o2.sqAbs());
		}
	}

	static long vect(long x1, long y1, long x2, long y2) {
		return x1 * y2 - x2 * y1;
	}

	static boolean isRight(Point p, Point p1, Point p2) {
		long t = vect(p1.x - p.x, p1.y - p.y, p2.x - p.x, p2.y - p.y);
		return t > 0;
	}

	static Point[] hull(Point[] p) {
		int n = p.length;
		if (n < 3)
			return p;
		int min = 0;
		for (int i = 0; i < n; i++) {
			if (p[i].y < p[min].y || p[i].y == p[min].y && p[i].x < p[min].x)
				min = i;
		}
		Point tmp = p[min];
		p[min] = p[0];
		p[0] = tmp;
		long xx = p[0].x, yy = p[0].y;
		for (int i = 0; i < p.length; i++) {
			p[i].x -= xx;
			p[i].y -= yy;
		}
		Arrays.sort(p, 1, n, new ByAngle());
		List<Point> ans = new ArrayList<Point>();
		ans.add(p[0]);
		ans.add(p[1]);
		for (int i = 2; i < n; i++) {
			while (ans.size() > 1) {
				Point p1 = ans.remove(ans.size() - 1);
				Point p2 = ans.get(ans.size() - 1);
				if (isRight(p2, p1, p[i])) {
					ans.add(p1);
					break;
				}
			}
			ans.add(p[i]);
		}
		for (int i = 0; i < p.length; i++) {
			p[i].x += xx;
			p[i].y += yy;
		}
		return ans.toArray(new Point[0]);
	}

	static Output solveOneTest(Input input) {
		return input.solve();
	}

	static class Input {
		int n;
		int[] values;

		Input() throws IOException {
			n = nextInt();
			values = new int[n];
			for (int i = 0; i < n; i++) {
				values[i] = nextInt();
			}
		}

		Output solve() {
			if (n <= 2) {
				return new Output(0);
			}
			Point[] points = new Point[n];
			for (int i = 0; i < n; i++) {
				points[i] = new Point(i, values[i]);
			}
			Point[] hull = hull(points);
			if (hull.length <= 2) {
				return new Output(0);
			}
			double answer = Double.POSITIVE_INFINITY;
			for (int i = 0; i < hull.length; i++) {
				long x1 = hull[i].x, y1 = hull[i].y;
				long x2 = hull[(i + 1) % hull.length].x, y2 = hull[(i + 1)
						% hull.length].y;
				double k = (y2 - y1) * 1.0 / (x2 - x1);
				answer = Math.min(answer, getError(k));
			}
			return new Output(answer);
		}

		private double getError(double k) {
			double low = Double.POSITIVE_INFINITY, high = Double.NEGATIVE_INFINITY;
			for (int i = 0; i < n; i++) {
				double cur = values[i] - k * i;
				low = Math.min(low, cur);
				high = Math.max(high, cur);
			}
			return (high - low) * 0.5;
		}
	}

	static class Output {
		double answer;

		public Output(double answer) {
			this.answer = answer;
		}

		void writeOutput() {
			out.println(answer);
		}
	}

	public static void main(String[] args) throws IOException,
			InterruptedException, ExecutionException {
		br = new BufferedReader(new FileReader("b.in"));
		out = new PrintWriter("b.out");
		ExecutorService executor = Executors.newFixedThreadPool(6);
		int testCases = nextInt();
		final Input[] inputs = new Input[testCases];
		for (int i = 0; i < testCases; i++) {
			inputs[i] = new Input();
		}

		@SuppressWarnings("unchecked")
		Future<Output> outputs[] = new Future[testCases];

		for (int i = 0; i < testCases; i++) {
			final int testCase = i;
			outputs[i] = executor.submit(new Callable<Output>() {
				@Override
				public Output call() throws Exception {
					return solveOneTest(inputs[testCase]);
				}
			});
		}

		for (int i = 0; i < testCases; i++) {
			out.print("Case #" + (i + 1) + ": ");
			outputs[i].get().writeOutput();
		}

		out.close();
		executor.shutdown();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}
