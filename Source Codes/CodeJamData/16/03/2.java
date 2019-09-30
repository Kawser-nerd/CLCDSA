import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "C";
	// final String filename = problem + "-sample";
//	 final String filename = problem + "-small-attempt0";

	// final String filename= problem+"-small-attempt1";
	final String filename = problem + "-large";

	public void solve() throws Exception {
		int N = iread(), J = iread();

		HashSet<String> hash = new HashSet<String>();

		ArrayList<BigInteger> ints = new ArrayList<BigInteger>();
		cycle: for (int i = 3; i < 10000; i += 2) {
			for (int j = 2; j * j <= i; j++) {
				if (i % j == 0)
					continue cycle;
			}
			ints.add(BigInteger.valueOf(i));
		}

		StringBuilder sb = new StringBuilder();
		sb.append('1');
		for (int i = 1; i < N - 1; i++) {
			sb.append('0');
		}
		sb.append('1');

		ArrayList<String> ans = new ArrayList<String>();
		Random r = new Random(12345);

		while (ans.size() < J) {
			for (int i = 1; i < N - 1; i++)
				sb.setCharAt(i, r.nextInt(2) > 0 ? '1' : '0');
			String s = sb.toString();
			if (hash.contains(s))
				continue;
			String t = s;
			int k;
			cycle2: for (k = 2; k <= 10; k++) {
				BigInteger b = new BigInteger(s, k);
				for (int i = 0; i < ints.size(); i++) {
					if (b.mod(ints.get(i)).equals(BigInteger.ZERO)) {
						t += " " + ints.get(i);
						continue cycle2;
					}
				}
				break;
			}
			if (k == 11) {
				ans.add(t);
				hash.add(t);
				out.write(t + "\n");
				out.flush();
			}
		}
	}

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			out.write("\n");
			solve();
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