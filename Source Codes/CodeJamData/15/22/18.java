import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.LARGE;
	static final int ATTEMPT_NUMBER = 0;

	void solve() throws IOException {
		int r = nextInt();
		int c = nextInt();
		int n = nextInt();
		if (n <= r * c / 2) {
			out.println(0);
			return;
		}
		int[][] adj = new int[r][c];
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				if (i + 1 < r) {
					adj[i][j]++;
					adj[i + 1][j]++;
				}
				if (j + 1 < c) {
					adj[i][j]++;
					adj[i][j + 1]++;
				}
			}
		List<Integer> even = new ArrayList<>();
		List<Integer> odd = new ArrayList<>();
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				List<Integer> cur = ((i + j) % 2 == 0) ? even : odd;
				cur.add(adj[i][j]);
			}
		Collections.sort(even);
		Collections.reverse(even);
		Collections.sort(odd);
		Collections.reverse(odd);
		int[] se = makePref(even);
		int[] so = makePref(odd);
		int total = r * (c - 1) + (r - 1) * c;
		int bad = r * c - n;
		int val = Math.max(bad < se.length ? se[bad] : 0,
				bad < so.length ? so[bad] : 0);
		out.println(total - val);

	}

	int[] makePref(List<Integer> lst) {
		int[] ret = new int[lst.size() + 1];
		for (int i = 0; i < lst.size(); i++) {
			ret[i + 1] = ret[i] + lst.get(i);
		}
		return ret;
	}

	B() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("B-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("B-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("B-large.in"));
			out = new PrintWriter("B-large.out");
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
		new B();
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