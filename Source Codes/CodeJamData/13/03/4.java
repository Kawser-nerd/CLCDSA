import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "C";
	// final String filename = problem + "-sample";

	// final String filename = problem + "-small-attempt0";

	// final String filename= problem+"-small-attempt1";
	final String filename = problem + "-large-2";

	public void solve() throws Exception {
		BigInteger A = new BigInteger(readword()), B = new BigInteger(
				readword());
		int ans = 0;
		for (BigInteger x : test1) {
			if (x.compareTo(A) >= 0 && x.compareTo(B) <= 0) {
				ans++;
			}
		}
		out.write(ans + "");
	}

	ArrayList<BigInteger> test1 = new ArrayList<BigInteger>();

	boolean check(BigInteger x) {
		String sss = x.multiply(x).toString();
		for (int j = 0; j < sss.length(); j++)
			if (sss.charAt(j) != sss.charAt(sss.length() - j - 1))
				return false;
		return true;
	}

	int n;
	boolean even;
	StringBuilder sb = new StringBuilder();

	public void rec(int pos) {
		if (pos == n) {
			return;
		}
		if (pos != 0)
			rec(pos + 1);
		cycle: for (int t = 1; t <= 2; t++) {
			char d = (char) (t + '0');
			sb.setCharAt(pos, d);
			sb.setCharAt(sb.length() - pos - 1, d);
			BigInteger x = new BigInteger(sb.toString());
			x = x.multiply(x);
			String s = x.toString();
			for (int i = 0; i < s.length(); i++)
				if (s.charAt(i) != s.charAt(s.length() - i - 1))
					break cycle;
			test1.add(x);
			rec(pos + 1);
		}
		sb.setCharAt(pos, '0');
		sb.setCharAt(sb.length() - pos - 1, '0');
	}

	public void solve_gcj() throws Exception {
		test1.add(BigInteger.valueOf(9));
		for (int len = 1; len <= 30; len++) {
			n = len;
			sb.setLength(len * 2 - 1);
			for (int i = 0; i < sb.length(); i++)
				sb.setCharAt(i, '0');
			rec(0);
			sb.setLength(len * 2);
			for (int i = 0; i < sb.length(); i++)
				sb.setCharAt(i, '0');
			rec(0);
		}
		Collections.sort(test1);

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