import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Roman Elizarov
 */
public class A extends Thread {
	public static void main(String[] args) throws FileNotFoundException, InterruptedException {
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
		for (int i = 1; i <= n; i++)
			doCase(i);
	}

	private void doCase(int caseNumber) {
		// read case
		int sn = in.nextInt();
		String[] s = new String[sn];
		in.nextLine();
		for (int i = 0; i < sn; i++) {
			s[i] = in.nextLine();
		}
		int qn = in.nextInt();
		String[] q = new String[qn];
		in.nextLine();
		for (int i = 0; i < qn; i++) {
			q[i] = in.nextLine();
		}

		// solve case
		int[][] a = new int[qn + 1][sn];
		for (int i = qn; --i >= 0;) {
			for (int j = 0; j < sn; j++) {
				if (q[i].equals(s[j])) {
					int best = Integer.MAX_VALUE;
					for (int k = 0; k < sn; k++) {
						if (k != j)
							best = Math.min(best, a[i + 1][k]);
					}
					a[i][j] = best + 1;
				} else
					a[i][j] = a[i + 1][j];
			}
		}

		int result = Integer.MAX_VALUE;
		for (int j = 0; j < sn; j++) {
			result = Math.min(result, a[0][j]);
		}

		// write case result
		out.printf("Case #%d: %d%n", caseNumber, result);
	}
}