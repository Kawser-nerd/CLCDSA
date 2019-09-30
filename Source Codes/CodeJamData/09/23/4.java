import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	private static class Pair {
		final int i, j, value;

		Pair(int i, int j, int value) {
			this.i = i;
			this.j = j;
			this.value = value;
		}
		
		public boolean equals(Object o) {
			if (!(o instanceof Pair)) {
				return false;
			}
			Pair oo = (Pair) o;
			return i == oo.i && j == oo.j && value == oo.value;
		}
		
		public int hashCode() {
			return i + j * 257 + value * 65537;
		}
	}
	
	private static class Formula implements Comparable<Formula> {
		final char c;
		final Formula prev;
		final int length;
		
		Formula(char c) {
			this.c = c;
			prev = null;
			length = 1;
		}
		
		Formula(char c, Formula prev) {
			this.c = c;
			this.prev = prev;
			length = prev.length + 1;
		}
		
		public int compareTo(Formula o) {
			int ans = length - o.length;
			if (ans != 0) {
				return ans;
			}
			if (prev != null) {
				ans = prev.compareTo(o.prev);
				if (ans != 0) {
					return ans;
				}
			}
			ans = c - o.c;
			return ans;
		}
		
		private StringBuilder toStringBuilder() {
			StringBuilder out;
			if (prev == null) {
				out = new StringBuilder();
			} else {
				out = prev.toStringBuilder();
			}
			out.append(c);
			return out;
		}
		
		public String toString() {
			return toStringBuilder().toString();
		}
	}
	
	private static void propagate(int fromI, int fromJ, int fromValue, int toI, int toJ) {
		char from = map[fromI][fromJ];
		char to = map[toI][toJ];
		int add;
		if (from == '+') {
			add = to - '0';
		} else if (from == '-') {
			add = '0' - to;
		} else {
			add = 0;
		}
		int toValue = fromValue + add;
		if (toValue < -100 || toValue > 1000) {
			return;
		}
		Formula fromFormula = solutions[fromI][fromJ].get(fromValue);
		Formula toFormula = new Formula(to, fromFormula);
		proposeSolution(toI, toJ, toValue, toFormula);
	}
	
	private static Queue<Pair> queue;
	private static Set<Pair> onQueue;
	
	private static void addToQueue(Pair pair) {
		if (!onQueue.contains(pair)) {
			queue.add(pair);
			onQueue.add(pair);
		}
	}
	
	private static char map[][];
	private static Map<Integer, Formula> solutions[][];
	
	private static void proposeSolution(int i, int j, int value, Formula formula) {
		Map<Integer, Formula> solutions = C.solutions[i][j];
		if (solutions.containsKey(value)) {
			Formula have = solutions.get(value);
			if (have.compareTo(formula) <= 0) {
				return;
			}
		}
		solutions.put(value, formula);
		addToQueue(new Pair(i, j, value));
	}
	
	public static void main(String args[]) throws Exception {
		in = new BufferedReader(new InputStreamReader(new FileInputStream("c.in")));
		out = new PrintWriter(new OutputStreamWriter(new FileOutputStream("c.out")));
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			int w = nextInt();
			int q = nextInt();
			map = new char[w][];
			for (int i = 0; i < w; i++) {
				map[i] = next().toCharArray();
			}
			solutions = (Map<Integer, Formula>[][]) new Map<?, ?>[w][w];
			queue = new ArrayDeque<Pair>();
			onQueue = new HashSet<Pair>();
			for (int i = 0; i < w; i++) {
				for (int j = 0; j < w; j++) {
					solutions[i][j] = new HashMap<Integer, Formula>();
					if (map[i][j] >= '0' && map[i][j] <= '9') {
						proposeSolution(i, j, map[i][j] - '0', new Formula(map[i][j]));
					}
				}
			}
			while (!queue.isEmpty()) {
				Pair p = queue.remove();
				onQueue.remove(p);
				int i = p.i;
				int j = p.j;
				int value = p.value;
				if (i > 0) {
					propagate(i, j, value, i - 1, j);
				}
				if (i < w - 1) {
					propagate(i, j, value, i + 1, j);
				}
				if (j > 0) {
					propagate(i, j, value, i, j - 1);
				}
				if (j < w - 1) {
					propagate(i, j, value, i, j + 1);
				}
			}
			Map<Integer, Formula> ans = new HashMap<Integer, Formula>();
			for (int i = 0; i < w; i++) {
				for (int j = 0; j < w; j++) {
					if (map[i][j] == '+' || map[i][j] == '-') {
						continue;
					}
					Map<Integer, Formula> solution = solutions[i][j];
					for (int value: solution.keySet()) {
						Formula formula = solution.get(value);
						if (ans.containsKey(value)) {
							Formula have = ans.get(value);
							if (have.compareTo(formula) <= 0) {
								continue;
							}
						}
						ans.put(value, formula);
					}
				}
			}
			out.println("Case #" + (t + 1) + ":");
			for (int i = 0; i < q; i++) {
				out.println(ans.get(nextInt()));
			}
		}
		in.close();
		out.close();
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
}