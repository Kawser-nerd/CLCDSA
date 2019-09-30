package round3;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	private static final String TASKNAME = "input";

	private char change(char c) {
		if (c == 'o') {
			return '0';
		} else if (c == 'i') {
			return '1';
		} else if (c == 'e') {
			return '3';
		} else if (c == 'a') {
			return '4';
		} else if (c == 's') {
			return '5';
		} else if (c == 't') {
			return '7';
		} else if (c == 'b') {
			return '8';
		} else if (c == 'g') {
			return '9';
		} else {
			return c;
		}
	}

	private boolean changable(char c) {
		return c != change(c);
	}
	
	private class Str implements Comparable<Str> {
		char first;
		char last;
		boolean[] contains = new boolean[128];
		
		Str(char first, char last) {
			this.first = first;
			this.last = last;
		}

		@Override
		public int compareTo(Str o) {
			if (first == o.first) {
				return last - o.last;
			} else {
				return first - o.first;
			}
		}
		
		@Override
		public String toString() {
			return first + "" + last;
		}
	}

	private void solve() throws IOException {
		int tests = nextInt();
		for (int t = 1; t <= tests; t++) {
			int k = nextInt();
			char[] s = nextToken().toCharArray();

			int res = 0;
			
			int[] a = new int[128];
			int[] b = new int[128];

			TreeSet<Str> set = new TreeSet<Str>();
			for (int i = 1; i < s.length; i++) {
				set.add(new Str(s[i - 1], s[i]));
				if (changable(s[i - 1])) {
					set.add(new Str(change(s[i - 1]), s[i]));
				}
				if (changable(s[i])) {
					set.add(new Str(s[i - 1], change(s[i])));
				}
				if (changable(s[i]) && changable(s[i - 1])) {
					set.add(new Str(change(s[i - 1]), change(s[i])));
				}
			}
			
			for (Str str: set) {
				a[str.first]++;
				a[str.last]--;
			}
			
			int m = 0;
			for (int i = 0; i < 128; i++) {
				if (a[i] > 0) {
					m += a[i];
				}
//				m += Math.abs(a[i]);
			}
//			m--;
			if (m == 0) {
				m = 1;
			}
			
			res = set.size() + m;
			
			println("Case #" + t + ": " + res);
		}
	}

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	private int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	private double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private void print(Object o) {
		writer.print(o);
	}

	private void println(Object o) {
		writer.println(o);
	}

	private void printf(String format, Object... o) {
		writer.printf(format, o);
	}

	public static void main(String[] args) {
		long time = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		new Main().run();
		System.err.printf("%.3f\n", 1e-3 * (System.currentTimeMillis() - time));
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	private void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new PrintWriter(System.out);
			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
			writer = new PrintWriter(TASKNAME + ".out");
			solve();
			reader.close();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(13);
		}
	}
}