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

	void solve() throws IOException {
		int n = nextInt();
		int l = nextInt();
		String[] need = new String[n];
		for (int i = 0; i < n; i++) {
			need[i] = nextToken();
		}
		String bad = nextToken();
		for (int i = 0; i < n; i++) {
			if (need[i].equals(bad)) {
				out.println("IMPOSSIBLE");
				return;
			}
		}
		
		if (l == 1) {
			out.println("0? 0");
			return;
		}
		for (int i = 0; i < l; i++) {
			out.print("0?");
		}
		out.print(" ");
		for (int i = 0; i < l - 1; i++) {
			out.print("1");
		}
		out.println();
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