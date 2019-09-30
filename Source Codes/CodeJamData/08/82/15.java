import java.io.*;
import java.util.*;
import java.text.*;

/**
 * @author Roman Elizarov
 */
public class B extends Thread {
	private static final int INF = Integer.MAX_VALUE / 2;

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

	static final int MAX = 10000;

	private void doCase(int caseNumber) {
		// read case
		int n = in.nextInt();
		int[] c = new int[n];
		int[] aa = new int[n];
		int[] bb = new int[n];
		Map<String, Integer> ci = new HashMap<String, Integer>();
		Map<Integer, Integer> ki = new TreeMap<Integer, Integer>();
		ki.put(0, null);
		ki.put(1, null);
		ki.put(MAX, null);
		int cc = 0;
		for (int i = 0; i < n; i++) {
			String col = in.next();
			Integer cii = ci.get(col);
			if (cii == null)
				ci.put(col, cii = cc++);
			c[i] = cii;
			aa[i] = in.nextInt();
			bb[i] = in.nextInt();
			ki.put(aa[i] - 1, null);
			ki.put(aa[i], null);
			ki.put(bb[i], null);
		}

		// preprocess
		int[] a = new int[n];
		int[] b = new int[n];
		int m = 0;
		for (Map.Entry<Integer, Integer> e : ki.entrySet())
			e.setValue(m++);
		for (int i = 0; i < n; i++) {
			a[i] = ki.get(aa[i]);
			b[i] = ki.get(bb[i]);
		}

		// solve case
		boolean[] f = new boolean[n];
		int[] fse = new int[m + 1];
		int[] dp = new int[m + 1];
		int result = INF;
		for (int i0 = 0; i0 < cc; i0++) {
			for (int i1 = i0; i1 < cc; i1++) {
				for (int i2 = i1; i2 < cc; i2++) {
					// fill f
					for (int i = 0; i < n; i++) {
						f[i] = (c[i] == i0) || (c[i] == i1) || (c[i] == i2);
					}
					// fill fse
					Arrays.fill(fse, INF);
					for (int i = 0; i < n; i++)
						if (f[i]) {
							for (int j = b[i]; j >= a[i]; j--) {
								fse[j] = Math.min(fse[j], a[i]);
							}
//							Integer next = ki.get(bb[i] + 1);
//							if (next != null)
//								fse[next] = Math.min(fse[next], a[i]);
						}
					// fill dp
					dp[0] = 0;
					for (int k = 1; k < m; k++) {
						if (fse[k] == INF)
							dp[k] = INF;
						else
							dp[k] = dp[fse[k] - 1] + 1;
					}
					result = Math.min(result, dp[m - 1]);
				}
			}
		}

		// write case result
		if (result == INF)
			out.printf("Case #%d: IMPOSSIBLE%n", caseNumber);
		else
			out.printf("Case #%d: %d%n", caseNumber, result);
	}
}