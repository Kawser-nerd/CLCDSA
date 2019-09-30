import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {

	void solve() throws Exception {
		int tc = nextInt();
		for (int tt = 0; tt < tc; tt++) {
			int x11 = nextInt();
			int y11 = nextInt();
			int x12 = nextInt();
			int y12 = nextInt();
			int x13 = nextInt();
			int y13 = nextInt();

			int x21 = nextInt();
			int y21 = nextInt();
			int x22 = nextInt();
			int y22 = nextInt();
			int x23 = nextInt();
			int y23 = nextInt();

			double v11x = x12 - x11;
			double v11y = y12 - y11;
			double v12x = x13 - x11;
			double v12y = y13 - y11;

			double v21x = x22 - x21;
			double v21y = y22 - y21;
			double v22x = x23 - x21;
			double v22y = y23 - y21;

			double a1 = v11x - v21x;
			double b1 = v12x - v22x;
			double c1 = x21 - x11;

			double a2 = v11y - v21y;
			double b2 = v12y - v22y;
			double c2 = y21 - y11;

			double d = a1 * b2 - a2 * b1;
			boolean nosol = false;
			if (Math.abs(d) < 1e-9) {
				nosol = true;
				System.out.println("No solution");
			}
			double d1 = -c1 * b2 + c2 * b1;
			double d2 = -a1 * c2 + a2 * c1;

			double alpha = -d1 / d;
			double beta = -d2 / d;

			System.out.println(alpha + " " + beta);

			double x = x11 + alpha * v11x + beta * v12x;
			double y = y11 + alpha * v11y + beta * v12y;
			if (nosol) {
				out.printf("Case #%d: No solution", tt + 1);
			} else {
				out.printf("Case #%d: %.10f %.10f", tt + 1, x, y);
			}
			out.println();

		}
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new Thread(new Solution("a")).start();
	}

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;

	public Solution(String fname) throws IOException {
		in = new BufferedReader(new FileReader(fname + ".in"));
		st = new StringTokenizer("");
		out = new PrintWriter(new FileWriter(fname + ".out"));
	}


	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}

	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	public void run() {
		try {
			solve();
		} catch (Exception e) {
			apstenu(e);
		} finally {
			out.close();
		}
	}

	private void apstenu(Exception e) {
		e.printStackTrace();
		System.exit(1);
	}

}
