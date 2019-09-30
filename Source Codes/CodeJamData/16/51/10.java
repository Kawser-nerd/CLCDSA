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
	static final int ATTEMPT_NUMBER = 0;

	void solve() throws IOException {
		String s = nextToken();
		int[] a = new int[4];
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			int pos = i % 2;
			
			a[(c == 'C' ? 2 : 0) + pos]++;
		}
		
		int tens = Math.min(a[2], a[3]) + Math.min(a[0], a[1]);
		int rest = s.length() / 2 - tens;
		
		out.println(tens * 10 + rest * 5);
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