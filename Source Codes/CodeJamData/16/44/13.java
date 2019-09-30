import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.SMALL;
	static final int ATTEMPT_NUMBER = 0;

	static int get(int mask, int i) {
		return (mask >> i) & 1;
	}

	boolean good(int mask, int n) {
		int[] know = new int[1 << n];
		
		int row = (1 << n) - 1;
		
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = (mask >> (i * n)) & row; 
		}
		
		for (int i = 0; i < (1 << n); i++) {
			for (int j = 0; j < n; j++) {
				if ((a[j] & i) != 0) {
					know[i]++;
				}
			}
			
			if (know[i] < Integer.bitCount(i)) {
				return false;
			}
		}
	
		outer: for (int i = 0; i < n; i++) {
			for (int j = 1; j < (1 << n); j++) {
				if ((j | a[i]) != a[i]) {
					continue;
				}
				if (know[j] == Integer.bitCount(j)) {
					continue outer;
				}
			}
			return false;
		}
		return true;
	}

	void solve() throws IOException {
		int n = nextInt();

		int mask = 0;

		for (int i = 0; i < n; i++) {
			String s = nextToken();
			for (int j = 0; j < n; j++) {
				mask |= (s.charAt(j) == '1') ? (1 << (i * n + j)) : 0;
			}
		}

		if (good(mask, n)) {
			out.println(0);
			return;
		}

		int ret = n * n + 1;

		int all = (1 << (n * n)) - 1;
		int init = all ^ mask;
		for (int sub = init; sub > 0; sub = (sub - 1) & init) {
			if (good(mask | sub, n)) {
				ret = Math.min(ret, Integer.bitCount(sub));
			}
		}

		out.println(ret);

	}

	D() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("D-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("D-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("D-large.in"));
			out = new PrintWriter("D-large.out");
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
		new D();
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