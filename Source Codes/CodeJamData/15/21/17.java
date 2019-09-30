import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.LARGE;
	static final int ATTEMPT_NUMBER = 1;

	long rev(long x) {
		return Long.parseLong(new StringBuilder(Long.toString(x)).reverse()
				.toString());
	}

	long pow(long x, int y) {
		long ret = 1;
		for (int i = 0; i < y; i++) {
			ret *= x;
		}
		return ret;
	}

	long f(long n) {
		if (n <= 20) {
			return n;
		}
		if (n < 100) {
			long x = n / 10 * 10 + 1;
			if (x > n) {
				x -= 10;
			}
			return n - x + f(rev(x)) + 1;
		}
		if (n < 201) {
			return (n - 99) + f(99);
		}
		if (n < 1000) {
			long x = n / 10 * 10 + 1;
			if (x > n) {
				x -= 10;
			}
//			System.err.println(x);
			return n - x + f(rev(x)) + 1;
		}
		int len = Long.toString(n).length();
		long low = pow(10, len - 1) + pow(10, (len + 1) / 2) + 1;
//		System.err.println(n + " " + low);
		if (n < low) {
//			System.err.println("?");
			return (n - pow(10, len - 1) + 1) + f(pow(10, len - 1) - 1);
		}
		long x = pow(10, len / 2);
		long y = n / x * x + 1;
		if (y > n) {
			y -= x;
		}
//		System.err.println(x + " " + y);
		return (n - y) + 1 + f(rev(y));
	}

	void solve() throws IOException {
		out.println(f(nextLong()));
	}

	A() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("A-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("A-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("A-large.in"));
			out = new PrintWriter("A-large.out");
			break;
		}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println("Test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
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
}