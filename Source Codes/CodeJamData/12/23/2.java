import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.exit;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Element implements Comparable<Element> {
		final long value;
		final long numbers[];
		
		Element(long value) {
			this.value = value;
			numbers = new long[] {value};
		}
		
		Element(Element e1, Element e2) {
			value = e1.value - e2.value;
			numbers = new long[e1.numbers.length + e2.numbers.length];
			for (int i = 0; i < e1.numbers.length; i++) {
				numbers[i] = e1.numbers[i];
			}
			for (int i = 0; i < e2.numbers.length; i++) {
				numbers[e1.numbers.length + i] = -e2.numbers[i];
			}
		}
		
		public int compareTo(Element o) {
			return Long.signum(value - o.value);
		}
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		Element elements[] = new Element[n];
		for (int i = 0; i < n; i++) {
			elements[i] = new Element(nextLong());
		}
		int knapsack[] = new int[2000001];
		while (n > 0) {
			sort(elements, 0, n);
			fill(knapsack, -1);
			knapsack[0] = -2;
			for (int i = 0; i < n; i++) {
				long lval = elements[i].value;
				if (lval > knapsack.length - 1) {
					break;
				}
				int val = (int) lval;
				for (int j = knapsack.length - 1 - val; j >= 0; j--) {
					if (knapsack[j] == -1) {
						continue;
					}
					if (knapsack[j + val] != -1) {
						List<Long> ans = new ArrayList<>();
						for (long l: elements[i].numbers) {
							ans.add(l);
						}
						for (int pos = j; knapsack[pos] != -2; pos -= (int) elements[knapsack[pos]].value) {
							for (long l: elements[knapsack[pos]].numbers) {
								ans.add(l);
							}
						}
						for (int pos = j + val; knapsack[pos] != -2; pos -= (int) elements[knapsack[pos]].value) {
							for (long l: elements[knapsack[pos]].numbers) {
								ans.add(-l);
							}
						}
						Map<Long, Integer> cnts = new HashMap<>();
						for (long l: ans) {
							if (!cnts.containsKey(abs(l))) {
								cnts.put(abs(l), 0);
							}
							cnts.put(abs(l), cnts.get(abs(l)) + (l < 0 ? -1 : 1));
						}
						List<Long> ans1 = new ArrayList<>();
						List<Long> ans2 = new ArrayList<>();
						for (Entry<Long, Integer> e: cnts.entrySet()) {
							if (e.getValue() == 0) {
								continue;
							}
							if (e.getValue() == 1) {
								ans1.add(e.getKey());
								continue;
							}
							if (e.getValue() == -1) {
								ans2.add(e.getKey());
								continue;
							}
							throw new AssertionError();
						}
						Collections.sort(ans1);
						Collections.sort(ans2);
						printlnCase();
						for (int ii = 0; ii < ans1.size(); ii++) {
							if (ii > 0) {
								out.print(' ');
							}
							out.print(ans1.get(ii));
						}
						out.println();
						for (int ii = 0; ii < ans2.size(); ii++) {
							if (ii > 0) {
								out.print(' ');
							}
							out.print(ans2.get(ii));
						}
						out.println();
						return;
					}
					knapsack[j + val] = i;
				}
			}
			n /= 2;
			for (int i = 0; i < n; i++) {
				elements[i] = new Element(elements[2 * i + 1], elements[2 * i]);
			}
		}
		throw new AssertionError();
//		printlnCase();
//		out.println("Impossible");
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