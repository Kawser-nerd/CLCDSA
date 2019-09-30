import java.io.*;
import java.util.*;
import java.text.*;

/**
 * @author Roman Elizarov
 */
public class C extends Thread {
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

	int r;
	int c;
	boolean[][] w;

	private void doCase(int caseNumber) {
		r = in.nextInt();
		c = in.nextInt();
		w = new boolean[r][c];
		in.nextLine();
		for (int i = 0; i < r; i++) {
			char[] f = in.nextLine().toCharArray();
			assert f.length == c;
			for (int j = 0; j < c; j++) {
				switch (f[j]) {
				case '.':
					break;
				case 'x':
					w[i][j] = true;
					break;
				default:
					assert false;
				}
			}
		}

		// solve case
		int mmm = 1 << c;
		int[][] dp = new int[r + 1][mmm];

		for (int i = 0; i < r; i++) {
			for (int mprev = 0; mprev < mmm; mprev++) {
				for (int mhere = 0; mhere < mmm; mhere++) {
					boolean ok = true;
					int cnt = 0;
					boolean prev = false;
					for (int j = 0; j < c; j++) {
						if (((1 << j) & mhere) != 0) {
							if (w[i][j] || prev || used(mprev, j - 1) || used(mprev, j + 1)) {
								ok = false;
								break;
							}
							cnt++;
							prev = true;
						} else
							prev = false;
					}
					if (!ok)
						continue;
					dp[i + 1][mhere] = Math.max(dp[i + 1][mhere], dp[i][mprev] + cnt);
				}
			}
		}

		int result = 0;
		for (int m = 0; m < mmm; m++) {
			result = Math.max(result, dp[r][m]);
		}

		// write case result
		out.printf("Case #%d: %d%n", caseNumber, result);
	}

	private boolean used(int m, int i) {
		return i >= 0 && i < c && ((1 << i) & m) != 0;
	}
}