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
		int n1 = nextInt();
		int n2 = nextInt();
		int m = nextInt();
		
		int[] vs = new int[m];
		int[] us = new int[m];
		
		int[] deg1 = new int[n1];
		int[] deg2 = new int[n2];

		for (int i = 0; i < m; i++) {
			vs[i] = nextInt() - 1;
			us[i] = nextInt() - 1;
			deg1[vs[i]]++;
			deg2[us[i]]++;
		}
		
		int maxDeg2 = 0;
		for (int i = 0; i < n2; i++) {
			maxDeg2 = Math.max(maxDeg2, deg2[i]);
		}
		
		int low = maxDeg2 - 1; // can't
		int high = m; // can
		
		binSearch: while (high - low > 1) {
			int mid = (low + high) >> 1;
			
			int haveFree = 0;
			for (int i = 0; i < n1; i++) {
				haveFree += mid;
				if (haveFree < deg1[i]) {
					low = mid;
					continue binSearch;
				}
				haveFree -= deg1[i];
			}
			
			high = mid;
		}
			
		int ans1 = high;
		
		int ans2 = 0;
		for (int i = 0; i < n1; i++) {
			ans2 += deg1[i] - Math.min(deg1[i], ans1);
		}
		
		out.println(ans1 + " " + ans2);
		
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