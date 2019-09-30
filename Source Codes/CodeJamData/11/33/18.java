import static java.lang.Math.*;
import static java.lang.System.currentTimeMillis;
import static java.lang.System.exit;
import static java.lang.System.arraycopy;
import static java.util.Arrays.sort;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Main().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");

	private void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int tc = nextInt();
		for (int tn = 1; tn <= tc; tn++) {
			int n = nextInt();
			long min = nextLong();
			long max = nextLong();
			long[] fs = new long[n];
			for (int i = 0; i < n; i++)
				fs[i] = nextLong();
			
			out.print("Case #" + tn + ": ");
			boolean found = false;
			for (long f = min; f <= max; f++) {
				boolean ok = true;
				for (int i = 0; i < n; i++)
					if (!(f % fs[i] == 0 || fs[i] % f == 0)) {
						ok = false;
						break;
					}
				
				if (ok) {
					out.println(f);
					found = true;
					break;
				}
			}
			
			if (!found)
				out.println("NO");
		}
		in.close();
		out.close();
	}

	void chk(boolean b) {
		if (b)
			return;
		System.out.println(new Error().getStackTrace()[1]);
		exit(999);
	}
	void deb(String fmt, Object... args) {
		System.out.printf(fmt + "%n", args);
	}
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
}
