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

	private static final int MOD = 1000000007;
	private static final int SHM = 31;

	private void doCase(int caseNumber) {
		// read case
		int n = in.nextInt();
		int m = in.nextInt();
		long x = in.nextInt();
		long y = in.nextInt();
		int z = in.nextInt();

		int[] a = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = in.nextInt();
		}

		int[] d = new int[n];
		for (int i = 0; i < n; i++) {
			int j = i % m;
			d[i] = a[j];
			a[j] = (int)((x * a[j] + y * (i + 1)) % z); 
		}

		// solve case
		int[] e = d.clone();
		Arrays.sort(e);
		int[] f = new int[n];
		int fc = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0 || e[i] > e[i - 1])
				f[fc++] = e[i];
		}

		FenvickTree ft = new FenvickTree(fc);

		for (int i = 0; i < n; i++) {
			int r = 1;
			int j = Arrays.binarySearch(f, 0, fc, d[i]);
			assert j >= 0;
			if (j > 0)
				r = (r + ft.sumt(j - 1)) % MOD;
			ft.add(j, r);
		}

		int res = ft.sumt(fc - 1);

		// write case result
		out.printf("Case #%d: %d%n", caseNumber, res);
	}

	class FenvickTree {
		int n;
		int[] a;

		FenvickTree(int n) {
			this.n = n;
			a = new int[n];
		}

		// Returns sum of elements in range [0, i];
		int sumt(int i) {
			int res = 0;
			while (i >= 0) {
				res = (res + a[i]) % MOD;
				i = (i & (i + 1)) - 1;
			}
			return res;
		}

		// Adds x to the i-th element
		void add(int i, int x) {
			while (i < n) {
				a[i] = (a[i] + x) % MOD;
				i = i | (i + 1);
			}
		}
	}
}