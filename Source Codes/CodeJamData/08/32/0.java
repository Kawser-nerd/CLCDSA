import java.io.*;
import java.util.*;
import java.text.*;
import java.math.BigInteger;

/**
 * @author Roman Elizarov
 */
public class B extends Thread {
	public static void main(String[] args) throws FileNotFoundException, InterruptedException {
		Locale.setDefault(Locale.US);
		if (args.length == 0)
			args = new String[] { "B.in" };
		for (String infile : args)
			new B().go(infile);
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

	private static final int MOD = 2 * 3 * 5 * 7;
	private static final BigInteger BIGMOD = BigInteger.valueOf(MOD);
	private static final boolean[] UGLY = new boolean[MOD];

	static {
		for (int i = 0; i < MOD; i++) {
			UGLY[i] = (i % 2 == 0) || (i % 3 == 0) || (i % 5 == 0) || (i % 7 == 0);
		}
	}

	private void doCase(int caseNumber) {
		// read case
		String s = in.next();
		int n = s.length();

		// solve case
		BigInteger[][] mc = new BigInteger[n + 1][MOD];
		for (int i = 0; i <= n; i++) {
			Arrays.fill(mc[i], BigInteger.ZERO);
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				BigInteger num = new BigInteger(s.substring(j, i));
				int m = num.mod(BIGMOD).intValue();
				if (j == 0) {
					mc[i][m] = mc[i][m].add(BigInteger.ONE);
				} else
					for (int k = 0; k < MOD; k++) {
						int a = (k + m) % MOD;
						int b = (k - m + MOD) % MOD;
						mc[i][a] = mc[i][a].add(mc[j][k]);
						mc[i][b] = mc[i][b].add(mc[j][k]); 						
					}
			}
		}

		// write case result
		BigInteger result = BigInteger.ZERO;
		for (int i = 0; i < MOD; i++) {
			if (UGLY[i])
				result = result.add(mc[n][i]);
		}

		out.printf("Case #%d: %d%n", caseNumber, result);
	}
}