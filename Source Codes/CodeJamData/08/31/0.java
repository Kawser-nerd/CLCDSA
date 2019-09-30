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
		int p = in.nextInt();
		int k = in.nextInt();
		int l = in.nextInt();
		int[] f = new int[l];
		for (int i = 0; i < l; i++) {
			f[i] = in.nextInt();
		}

		// solve case
		Arrays.sort(f);
		long result = 0;
		long mul = 1;
		long cnt = 0;
		for (int i = l; --i >= 0;) {
			result += f[i] * mul;
			cnt++;
			if (cnt == k) {
				cnt = 0;
				mul++;
			}
		}

		// write case result
		out.printf("Case #%d: %d%n", caseNumber, result);
	}
}