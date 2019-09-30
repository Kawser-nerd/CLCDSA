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

	void canonize(int[] a, int l, int r) {
		if (r - l == 1) {
			return;
		}
		
		int mid = (l + r) >> 1;
		canonize(a, l, mid);
		canonize(a, mid, r);
		
		int cmp = 0;
		for (int i = l, j = mid; i < mid; i++, j++) {
			if (a[i] != a[j]) {
				cmp = a[i] < a[j] ? -1 : 1;
				break;
			}
		}
		
		if (cmp > 0) {
			for (int i = l, j = mid; i < mid; i++, j++) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}			
		}
	}
	
	String go(int win, int n, int c0, int c1, int c2) {
		int[] a = { win };
		for (int i = 0; i < n; i++) {
			int[] b = new int[a.length * 2];
			for (int j = 0; j < a.length; j++) {
				b[2 * j] = a[j];
				b[2 * j + 1] = (a[j] + 1) % 3;
			}
			a = b;
		}
		
		int[] cc = new int[3];
		for (int x : a) {
			cc[x]++;
		}
		
		if (cc[0] != c0 || cc[1] != c1 || cc[2] != c2) {
			return null;
		}
		
		canonize(a, 0, a.length);
		char[] ret = new char[a.length];
		for (int i = 0; i < a.length; i++) {
			ret[i] = "PRS".charAt(a[i]);
		}
		
		return new String(ret);
	}

	void solve() throws IOException {
		int n = nextInt();
		int c1 = nextInt();
		int c0 = nextInt();
		int c2 = nextInt();

		for (int win = 0; win < 3; win++) {
			String tmp = go(win, n, c0, c1, c2);
			if (tmp != null) {
				out.println(tmp);
				return;
			}
		}

		out.println("IMPOSSIBLE");
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