import java.io.*;
import java.util.*;
import java.text.*;

/**
 * @author Roman Elizarov
 */
public class D extends Thread {
	public static void main(String[] args) throws FileNotFoundException, InterruptedException {
		Locale.setDefault(Locale.US);
		if (args.length == 0)
			args = new String[] { "D.in" };
		for (String infile : args)
			new D().go(infile);
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

	private static final int MOD = 10007;

	private void doCase(int caseNumber) {
		// read case
		int h = in.nextInt();
		int w = in.nextInt();
		int n = in.nextInt();
		int[] r = new int[n];
		int[] c = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = in.nextInt() - 1;
			c[i] = in.nextInt() - 1;
		}

		// solve case
		int[][] dp = new int[h][w];
		dp[0][0] = 1;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				boolean ok = true;
				for (int k = 0; k < n; k++) {
					if (r[k] == i && c[k] == j) {
						ok = false;
						break;
					}
				}
				if (!ok)
					continue;
				if (i >= 1 && j >= 2)
					dp[i][j] = (dp[i][j] + dp[i - 1][j - 2]) % MOD;
				if (i >= 2 && j >= 1)
					dp[i][j] = (dp[i][j] + dp[i - 2][j - 1]) % MOD;
			}
		}

		// write case result
		out.printf("Case #%d: %d%n", caseNumber, dp[h - 1][w - 1]);
	}
}