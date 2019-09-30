import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Pair {
		final char a, b;

		Pair(char a, char b) {
			this.a = a;
			this.b = b;
		}

		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + a;
			result = prime * result + b;
			return result;
		}

		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (a != other.a)
				return false;
			if (b != other.b)
				return false;
			return true;
		}
	}
	
	static final String FROM = "oieastbg";
	static final String TO = "01345789";
	
	static char trans(char c) {
		int pos = FROM.indexOf(c);
		return pos < 0 ? c : TO.charAt(pos);
	}
	
	static <K> void add(Map<K, Integer> map, K key, int add) {
		Integer value = map.get(key);
		map.put(key, value == null ? add : value + add);
	}
	
	static void solve() throws Exception {
		int k = nextInt();
		String s = next();
		if (k != 2) {
			throw new AssertionError();
		}
		Set<Pair> pairs = new HashSet<Pair>();
		for (int i = 0; i < s.length() - 1; i++) {
			char a = s.charAt(i);
			char b = s.charAt(i + 1);
			pairs.add(new Pair(a, b));
			pairs.add(new Pair(trans(a), b));
			pairs.add(new Pair(a, trans(b)));
			pairs.add(new Pair(trans(a), trans(b)));
		}
		Map<Character, Integer> disballance = new HashMap<Character, Integer>();
		for (Pair p: pairs) {
			add(disballance, p.a, -1);
			add(disballance, p.b, 1);
		}
		int ans = 0;
		for (int v: disballance.values()) {
			ans += abs(v);
		}
		ans /= 2;
		if (ans == 0) {
			ans = 1;
		}
		printCase();
		out.println(pairs.size() + ans);
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}