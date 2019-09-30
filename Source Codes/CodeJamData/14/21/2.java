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
	
	static class Word {
		int[] cnt;
		char[] chr;
		public Word(String s) {
			int sz = 1;
			for (int i = 1; i < s.length(); i++) {
				if (s.charAt(i) != s.charAt(i - 1)) {
					sz++;
				}
			}
			
			cnt = new int[sz];
			chr = new char[sz];
			
			cnt[0] = 1;
			chr[0] = s.charAt(0);
			
			for (int i = 1, j = 0; i < s.length(); i++) {
				if (s.charAt(i) == s.charAt(i - 1)) {
					cnt[j]++;
				} else {
					j++;
					cnt[j] = 1;
					chr[j] = s.charAt(i);
				}
			}
		}
		
		String basicString() {
			return new String(chr);
		}
		
	}

	void solve() throws IOException {
		int n = nextInt();
		Word[] a = new Word[n];
		String[] ss = new String[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Word(nextToken());
			ss[i] = a[i].basicString();
		}
		
		for (int i = 1; i < n; i++) {
			if (!ss[i].equals(ss[0])) {
				out.println("Fegla Won");
				return;
			}
		}
		
		int ans = 0;
		
		for (int i = 0; i < a[0].cnt.length; i++) {
			int[] tmp = new int[n];
			for (int j = 0; j < n; j++) {
				tmp[j] = a[j].cnt[i];
			}
			Arrays.sort(tmp);
			int opt = tmp[n / 2];
			for (int j = 0; j < n; j++) {
				ans += Math.abs(tmp[j] - opt);
			}
		}
		
		out.println(ans);
		
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