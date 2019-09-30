import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Locale;
import java.util.TreeSet;
import java.util.PriorityQueue;

/**
 * @author Roman Elizarov
 */
public class C extends Thread {
	private static final double EPS = 1e-8;

	public static void main(String[] args) throws FileNotFoundException, InterruptedException {
		Locale.setDefault(Locale.US);
		if (args.length == 0)
			args = new String[] { "C.in" };
		for (String infile : args)
			new C().go(infile);
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
		for (int i = 1; i <= n; i++)
			doCase(i);
	}

	private double inarea(double s, double r, double g) {
		double sum = 0;
		double g2 = g * g;
		double s2 = s * s;
		double step = 2 * r + g;
		int max = (int)(s / step);
		PriorityQueue<Double> xx = new PriorityQueue<Double>();
		for (int i = 0; i <= max; i++) {
			for (int j = 0; j <= max; j++) {
				double x1 = i * step + r;
				double y1 = j * step + r;
				double x2 = x1 + g;
				double y2 = y1 + g;
				if (len(x2, y2) <= s + EPS) {
					sum += g2;
					continue;
				}
				if (len(x1, y1) >= s - EPS)
					continue;
				xx.clear();
				xx.add(x1);
				xx.add(x2);
				if (len(x1, y2) < s - EPS) {
					xx.add(Math.sqrt(s2 - y2 * y2));
				}
				if (len(x2, y1) > s + EPS) {
					xx.add(Math.sqrt(s2 - y1 * y1));
				}
				double sum0 = 0;
				while (true) {
					double xa = xx.remove();
					if (xx.isEmpty())
						break;
					double xb = xx.peek();
					double ya = Math.sqrt(s2 - xa * xa);
					double yb = Math.sqrt(s2 - xb * xb);
					if (Double.isNaN(ya) || Double.isNaN(yb))
						continue;
					if (ya > y2 - EPS && yb > y2 - EPS) {
						sum0 += (xb - xa) * g;
						continue;
					}
					if (ya < y1 + EPS && yb < y1 + EPS)
						continue;
					sum0 += (xb - xa) * ((yb + ya) / 2 - y1);
					double area2 = xb * ya - xa * yb;
					double sina = area2 / s2;
					double alpha = Math.asin(sina);
					sum0 += s2 * alpha / 2 - area2 / 2;
				}
				assert sum0 > 0 && sum0 < g2;
				sum += sum0;
			}
		}
		return 4 * sum;
	}

	private double len(double x, double y) {
		return Math.sqrt(x * x + y * y);
	}

	private double solve(double f, double R, double t, double r, double g) {
		if (g <= 2 * f + EPS)
			return 1;
		double s = R - t - f;
		if (s <= EPS)
			return 1;
		double A = Math.PI * R * R;
		return (A - inarea(s, r + f, g - 2 * f)) / A;
	}

	private void doCase(int caseNumber) {
		double result = solve(in.nextDouble(), in.nextDouble(), in.nextDouble(), in.nextDouble(), in.nextDouble());
		out.printf("Case #%d: %f%n", caseNumber, result);
	}
}