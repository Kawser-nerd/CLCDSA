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

	private static final int MAXABS = 3001;
	private static final int NN = 2 * MAXABS + 1;

	private void doCase(int caseNumber) {
		// read case
		int k = in.nextInt();
		int dx = 0;
		int dy = 1;
		int[] x = new int[NN * NN];
		int[] y = new int[NN * NN];
		int n = 0;
		x[0] = 0;
		y[0] = 0;
		for (int i = 0; i < k; i++) {
			String s = in.next();
			int t = in.nextInt();
			for (int j = 0; j < t; j++) {
				for (int q = 0; q < s.length(); q++) {
					char c = s.charAt(q);
					int z;
					switch (c) {
					case 'L':
						z = dx;
						dx = -dy;
						dy = z;
						break;
					case 'R':
						z = dx;
						dx = dy;
						dy = -z;
						break;
					case 'F':
						n++;
						x[n] = x[n - 1] + dx;
						y[n] = y[n - 1] + dy;
						//System.out.println(x[n] + " " + y[n]);
						break;
					default:
						assert false;
					}
				}
			}
		}
		assert x[n] == x[0];
		assert y[n] == y[0];

		// solve case
		int[] minx = new int[NN];
		int[] maxx = new int[NN];
		int[] miny = new int[NN];
		int[] maxy = new int[NN];
		Arrays.fill(minx, NN);
		Arrays.fill(maxx, 0);
		Arrays.fill(miny, NN);
		Arrays.fill(maxy, 0);

		int inner = 0;
		for (int i = 0; i < n; i++) {
			inner += (x[i + 1] - x[i]) * (y[i + 1] + y[i]);
			int x1 = Math.min(x[i + 1], x[i]) + MAXABS;
			int x2 = Math.max(x[i + 1], x[i]) + MAXABS;
			int y1 = Math.min(y[i + 1], y[i]) + MAXABS;
			int y2 = Math.max(y[i + 1], y[i]) + MAXABS;
			for (int xx = x1; xx < x2; xx++) {
				minx[xx] = Math.min(minx[xx], y1);
				maxx[xx] = Math.max(maxx[xx], y2);
			}
			for (int yy = y1; yy < y2; yy++) {
				miny[yy] = Math.min(miny[yy], x1);
				maxy[yy] = Math.max(maxy[yy], x2);
			}
		}
		inner = Math.abs(inner) / 2;

		int outer = 0;
		boolean[][] fill = new boolean[NN][NN];
		for (int xx = 0; xx < NN; xx++) {
			for (int yy = minx[xx]; yy < maxx[xx]; yy++) {
				if (!fill[xx][yy]) {
					fill[xx][yy] = true;
					outer++;
				}
			}
		}
		for (int yy = 0; yy < NN; yy++) {
			for (int xx = miny[yy]; xx < maxy[yy]; xx++) {
				if (!fill[xx][yy]) {
					fill[xx][yy] = true;
					outer++;
				}
			}
		}

		//System.out.println(inner +  " " + outer);
		// write case result
		out.printf("Case #%d: %d%n", caseNumber, outer - inner);
	}
}