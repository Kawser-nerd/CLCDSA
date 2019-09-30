import java.util.*;
import java.math.*;
import java.io.*;

public class d {
	
	char[] s;
	int qMarks, n;
	ArrayList<Integer> places;

	private void solve() throws Exception {
		s = nextToken().toCharArray();
		n = s.length;
		qMarks = 0;
		places = new ArrayList<Integer>();
		for (int i = 0; i < n; ++i) {
			if (s[i] == '?') {
				places.add(i);
				++qMarks;
			}
		}
		for (int mask = 0; mask < (1 << qMarks); ++mask) {
			long cur = 0;
			int cMask = mask;
			for (int i = 0; i < n; ++i) {
				if (s[i] == '?') {
					cur = cur * 2 + (cMask % 2);
					cMask /= 2;
				} else {
					cur = cur * 2 + (s[i] - '0');
				}
			}
			long sq = (long)Math.round(Math.sqrt(cur)) - 2;
			for (int it = 0; it < 5; ++it) {
				if (sq * sq == cur) {
					out.println(Long.toBinaryString(cur));
					return;
				}
				++sq;
			}
		}
	}

	public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private d(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	private d() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			St = new StringTokenizer("");
			out = new PrintWriter(System.out);
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new d("d").run();
	}
}
