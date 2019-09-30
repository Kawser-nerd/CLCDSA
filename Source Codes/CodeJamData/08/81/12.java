import java.io.*;
import java.util.*;

/**
 * @author Mikhail Dvorkin
 */
public class A implements Runnable {
	private Scanner in;
	private PrintWriter out;

	class Triangle {
		double x1, y1, x2, y2, x3, y3;
		double area;

		double[] getCoord(double x, double y) {
			return new double[]{
					g(x, y, x2, y2, x3, y3),
					g(x1, y1, x, y, x3, y3),
					g(x1, y1, x2, y2, x, y)
			};
		}

		private double g(double x1, double y1, double x2, double y2,
				double x3, double y3) {
			double ar =x1 * y2 - x2 * y1 +
			  x2 * y3 - x3 * y2 +
			  x3 * y1 - x1 * y3;
			return Math.abs(ar / area);
		}

		double[] put(double[] c) {
			return new double[]{
					c[0] * x1 + c[1] * x2 + c[2] * x3,
					c[0] * y1 + c[1] * y2 + c[2] * y3
			};
		}

		public Triangle(Scanner in) {
			x1 = in.nextInt();
			y1 = in.nextInt();
			x2 = in.nextInt();
			y2 = in.nextInt();
			x3 = in.nextInt();
			y3 = in.nextInt();
			area =x1 * y2 - x2 * y1 +
			  x2 * y3 - x3 * y2 +
			  x3 * y1 - x1 * y3;
		}

		public Triangle(double x1, double y1, double x2, double y2, double x3,
				double y3) {
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
			this.x3 = x3;
			this.y3 = y3;
			area =x1 * y2 - x2 * y1 +
			  x2 * y3 - x3 * y2 +
			  x3 * y1 - x1 * y3;
		}
	}

	Triangle next(Triangle a, Triangle b) {
		double[] p1 = b.put(a.getCoord(b.x1, b.y1));
		double[] p2 = b.put(a.getCoord(b.x2, b.y2));
		double[] p3 = b.put(a.getCoord(b.x3, b.y3));
		return new Triangle(p1[0], p1[1], p2[0], p2[1], p3[0], p3[1]);
	}

	private void solve(int testCase) {
		Triangle a = new Triangle(in);
		Triangle b = new Triangle(in);
		int cnt = 5000;
		while (b.area > 1e-20 || cnt --> 0) {
			b = next(a, b);
		}
		out.println("Case #" + testCase + ": " + b.x1 + " " + b.y1);
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Thread(new A()).start();
	}

	public void run() {
		try {
			in = new Scanner(new FileReader("a.in"));
			out = new PrintWriter("a.out");
			int n = in.nextInt();
			for (int i = 1; i <= n; i++)
				solve(i);
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
