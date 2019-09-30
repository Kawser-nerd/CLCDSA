import java.io.*;
import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "E";
//	final String filename = problem + "-sample";

	 final String filename = problem + "-small-attempt0";

	// final String filename= problem+"-small-attempt1";
	// final String filename= problem+"-large";

	public void solve() throws Exception {
		long N = lread();
		int A = iread(), B = iread();
		int MAX = 60 * B + 1;
		long[] d = new long[MAX];
		for (int i = 0; i < A; i++)
			d[i] = 1;
		if (N == 1) {
			out.write("0");
			return;
		}
		for (int i = A; i < MAX; i++) {
			d[i] = d[i - A] + (i >= B ? d[i - B] : 1);
			if (d[i] >= N) {
				out.write(i + "");
				return;
			}
		}
		out.write("FAIL");
		// out.write(df.format(res));
	}

	DecimalFormat df = new DecimalFormat("0.0000000000");

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
			out.write("\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new BufferedWriter(new FileWriter(filename + ".out"));
			solve_gcj();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		new Thread(new Main()).start();
		// new Thread(null, new Main(), "1", 1<<25).start();
	}
}