import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {
		int nTests = nextInt();
		for (int test = 1; test <= nTests; test++) {
			char[] s = next().toCharArray();
			int k = nextInt();
			out.println("Case #" + test + ": " + solve(s, k));
		}
	}

	final String vowels = "aeiou";
	
	private boolean isConsonant(char c) {
		return vowels.indexOf(c) < 0;
	}
	
	private long solve(char[] s, int k) {
		l = 0;
		r = 0;
		long res = 0;
		for (int i = 0; i < s.length; i++) {
			advance(s, k, i);
			res += s.length - r;
		}
		return res;
	}

	int l, r;

	private void advance(char[] s, int k, int pos) {
		while (l < pos) {
			++l;
		}
		while (l < s.length) {
			while (l < s.length && !isConsonant(s[l])) {
				++l;
			}
			if (r < l) {
				r = l;
			}
			while (r < s.length && r - l + 1 < k) {
				if (r + 1 < s.length && isConsonant(s[r + 1])) {
					++r;
				} else {
					l = r + 1;
					r = l;
					break;
				}
			}
			if (r - l + 1 >= k) {
				break;
			}
		}
	}

	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String rl = in.readLine();
			if (rl == null)
				return null;
			st = new StringTokenizer(rl);
		}
		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.UK);
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			in = new BufferedReader(new FileReader("A-large.in"));
			out = new PrintWriter(new FileWriter("A-large.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
