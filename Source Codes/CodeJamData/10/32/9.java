import java.io.*;
import java.util.*;
import java.math.*;

public class B2 implements Runnable {

	
	private void solve() throws IOException {
		int T = in.nextInt();
		for (int tn = 1; tn <= T; ++tn) {
			long l = in.nextInt();
			long r = in.nextInt();
			long c = in.nextInt();
			
			int ans = 0;
			long tc = c;
			while (tc * l < r) {
				tc *= tc;
				++ans;
			}
			out.println("Case #" + tn + ": " + ans);
		}
	}
	
	final String FILE_NAME = "B-large";

	SimpleScanner in;
	PrintWriter out;

	@Override
	public void run() {
		try {
			in = new SimpleScanner(new FileReader(FILE_NAME + ".in"));
			out = new PrintWriter(FILE_NAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	public static void main(String[] args) {
		new Thread(new B2()).start();
	}

	void myAssert(boolean e) {
		if (!e) {
			throw new Error("assertion failed");
		}
	}

	int assertBounds(int l, int m, int r) {
		myAssert(l <= m && m <= r);
		return m;
	}

	class SimpleScanner extends BufferedReader {

		private StringTokenizer st;
		private boolean eof;

		public SimpleScanner(Reader a) {
			super(a);
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(readLine());
				} catch (Exception e) {
					eof = true;
					return "";
				}
			}
			return st.nextToken();
		}

		boolean seekEof() {
			String s = next();
			if ("".equals(s) && eof)
				return true;
			st = new StringTokenizer(s + " " + st.toString());
			return false;
		}

		private String cnv(String s) {
			if (s.length() == 0)
				return "0";
			return s;
		}

		int nextInt() {
			return Integer.parseInt(cnv(next()));
		}

		double nextDouble() {
			return Double.parseDouble(cnv(next()));
		}

		long nextLong() {
			return Long.parseLong(cnv(next()));
		}
	}
}