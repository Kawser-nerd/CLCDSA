import java.io.*;
import java.util.*;
import java.text.*;

/**
 * @author Roman Elizarov
 */
public class A extends Thread {
	public static void main(String[] args) throws FileNotFoundException, InterruptedException {
		Locale.setDefault(Locale.US);
		if (args.length == 0)
			args = new String[] { "A.in" };
		for (String infile : args)
			new A().go(infile);
	}

	private Scanner in;
	private PrintWriter out;

	private void go(String infile) throws FileNotFoundException, InterruptedException {
		open(infile);
		start();
		join();
		close();
	}

	private void open(String infile) throws FileNotFoundException {
		String outfile = infile.replaceFirst("(\\.in)?$", ".out");
		System.out.printf("Processing %s, writing %s...%n", infile, outfile);
		in = new Scanner(new File(infile));
		out = new PrintWriter(new File(outfile));
	}

	private void close() {
		if (in != null)
			in.close();
		if (out != null)
			out.close();
	}

	public void run() {
		int n = in.nextInt();
		int lastp = 0;
		boolean nl = true;
		long start = System.currentTimeMillis();
		for (int i = 1; i <= n; i++) {
			if (nl) {
				System.out.print(new SimpleDateFormat("HH:mm:ss.SSS").format(new Date()) + " : ");
				nl = false;
			}
			doCase(i);
			System.out.print(".");
			int p = i * 20 / n;
			if (lastp != p) {
				System.out.printf("%d%%, ~%d sec more to go%n", (i * 100 / n), (System.currentTimeMillis() - start) * (n - i) / i / 1000);
				lastp = p;
				nl = true;
			}
		}
	}

	private void doCase(int caseNumber) {
		// read case
		int[][] x = new int[2][3];
		int[][] y = new int[2][3];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				x[i][j] = in.nextInt();
				y[i][j] = in.nextInt();
			}
		}
		// solve case
		double xa = x[0][0];
		double ya = y[0][0];
		double xb = x[1][0];
		double yb = y[1][0];
		int vx1 = x[1][1] - x[1][0];
		int vy1 = y[1][1] - y[1][0];
		int vx0 = x[0][1] - x[0][0];
		int vy0 = y[0][1] - y[0][0];
		double len1 = len(vx1, vy1);
		double len0 = len(vx0, vy0);
		double scale = len1 / len0;
		double sina =  det(vx0, vx1, vy0, vy1) / len1 / len0;
		double cosa =  (vx0 * vx1 + vy0 * vy1) / len1 / len0;
		//  x = (x - xa) * scale * cosa - (y - ya) * scale * sina + xb
		//  y = (x - xa) * scale * sina + (y - ya) * scale * cosa + yb

		//  x * (scale * cosa - 1) + y * (scale * sina) = xa * scale * cosa - ya * scale * sina - xb
		//  x * (-scale * sina) + y  * (scale * cosa - 1) = xa * scale * sina + ya * scale * cosa - yb

		double a11 = scale * cosa - 1;
		double a12 = -scale * sina;
		double a21 = scale * sina;
		double a22 = scale * cosa - 1;
		double r1 = xa * scale * cosa - ya * scale * sina - xb;
		double r2 = xa * scale * sina + ya * scale * cosa - yb;

		double d = det(a11, a12, a21, a22);
		if (Math.abs(d) < 1e-12)
			out.printf("Case #%d: No Solution%n", caseNumber);
		else {
			double x0 = det(r1, a12, r2, a22) / d;
			double y0 = det(a11, r1, a21, r2) / d;
			// write case result
			out.printf("Case #%d: %.6f %.6f%n", caseNumber, x0, y0);
		}
	}

	static double len(double x, double y) {
		return Math.sqrt(x * x + y * y);
	}

	static double det(double a11, double a12, double a21, double a22) {
		return a11 * a22 - a12 * a21;
	}
}