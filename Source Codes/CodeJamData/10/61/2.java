import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	/*static class Stack {
		
		final char letter;
		Stack next;
		Stack nextA, nextB, nextC;
		final int hash;
		
		private Stack() {
			letter = 0;
			hash = 1;
		}
		
		static final Stack BOTTOM = new Stack();
		
		public Stack(char letter, Stack next) {
			super();
			this.letter = letter;
			this.next = next;
			hash = (next == null ? 0 : 31 * next.hash) + letter;
			if (letter == 'A') {
				nextA = this;
			} else if (next == null) {
				nextA = null;
			} else {
				nextA = next.nextA;
			}
			if (letter == 'B') {
				nextB = this;
			} else if (next == null) {
				nextB = null;
			} else {
				nextB = next.nextB;
			}
			if (letter == 'C') {
				nextC = this;
			} else if (next == null) {
				nextC = null;
			} else {
				nextC = next.nextC;
			}
		}
		
		Stack next(char c) {
			switch (c) {
			case 'A':
				return nextA;
			case 'B':
				return nextB;
			case 'C':
				return nextC;
			}
			throw new AssertionError();
		}
		
		public boolean equals(Object o) {
			if (this == o) {
				return true;
			}
			if (!(o instanceof Stack)) {
				return false;
			}
			Stack s = (Stack) o;
			if (letter != s.letter || hash != s.hash) {
				return false;
			}
			if (next == s.next) {
				return true;
			}
			if (next == null || s.next == null) {
				return false;
			}
			if (next.equals(s.next)) {
				s.next = next;
				return true;
			}
			return false;
		}
		
		public int hashCode() {
			return hash;
		}
	}*/
	
	static int mod3(int i) {
		return ((i % 3) + 3) % 3;
	}
	
	static void solveTest() throws Exception {
		String s = in.readLine();
//		Map<Stack, Integer> stacks = new HashMap<Stack, Integer>();
//		stacks.put(Stack.BOTTOM, 0);
		int n = s.length();
		if (n <= 0) {
			out.println(0);
			return;
		}
		int cost[][] = new int[6][n + 1];
		int newCost[][] = new int[6][n + 1];
		for (int[] c: cost) {
			fill(c, Integer.MAX_VALUE);
		}
		for (int i = 0; i < 6; i++) {
			cost[i][0] = 0;
		}
		for (int i = 0; i < n; i++) {
			char c = s.charAt(i);
			c -= 'A';
			if (c >= 3) {
				throw new AssertionError();
			}
			for (int[] nc: newCost) {
				fill(nc, Integer.MAX_VALUE);
			}
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k <= n; k++) {
					int val = cost[j][k];
					if (val == Integer.MAX_VALUE) {
						continue;
					}
					int dir = j >= 3 ? -1 : 1;
					if (c == mod3(j + k * dir)) {
						newCost[j][k + 1] = min(newCost[j][k + 1], val + 1);
					}
					if (k > 0 && c == mod3(j + (k - 1) * dir)) {
						newCost[j][k] = min(newCost[j][k], val);
					}
					if (k > 1 && c == mod3(j + (k - 2) * dir)) {
						newCost[j][k - 1] = min(newCost[j][k - 1], val);
					}
					if (k > 2 && c == mod3(j + k * dir)) {
						newCost[j][k - 2] = min(newCost[j][k - 2], val);
					}
				}
			}
			int val = Integer.MAX_VALUE;
			for (int j = 0; j < 6; j++) {
				val = min(val, newCost[j][0]);
			}
			for (int j = 0; j < 6; j++) {
				newCost[j][0] = val;
			}
			for (int j = 0; j < 3; j++) {
				val = min(newCost[j][1], newCost[j + 3][1]);
				newCost[j][1] = val;
				newCost[j + 3][1] = val;
			}
			int tmpCost[][] = cost;
			cost = newCost;
			newCost = tmpCost;
//			Map<Stack, Integer> newStacks = new HashMap<A.Stack, Integer>();
//			for (Entry<Stack, Integer> e: stacks.entrySet()) {
//				Stack stack = e.getKey();
//				int val = e.getValue();
//				Stack newStack = new Stack(c, stack);
//				int newVal = val + 1;
//				if (stack.next(c) != stack && (stack.next == null || stack.next(c) != stack.next) && (!newStacks.containsKey(newStack) || newStacks.get(newStack) > newVal)) {
//					newStacks.put(newStack, newVal);
//				}
//				newStack = stack.next(c);
//				newVal = val;
//				if (newStack != null && (!newStacks.containsKey(newStack) || newStacks.get(newStack) > newVal)) {
//					newStacks.put(newStack, newVal);
//				}
//			}
//			stacks = newStacks;
		}
		int ans = Integer.MAX_VALUE;
//		for (int val: stacks.values()) {
//			ans = min(ans, val);
//		}
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j <= n; j++) {
				ans = min(ans, cost[i][j]);
			}
		}
		if (ans == Integer.MAX_VALUE) {
			throw new AssertionError();
		}
		out.println(s.length() + 2 * ans);
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
			System.out.print('.');
		}
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		System.out.print("Enter filename: ");
		System.out.flush();
		String filename = new BufferedReader(new InputStreamReader(System.in)).readLine();
		in = new BufferedReader(new InputStreamReader(
			new FileInputStream(new File(filename + ".in"))));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
			new FileOutputStream(new File(filename + ".out")))));
		solve();
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
		return parseInt(next());
	}
	
	static long nextLong() throws IOException {
		return parseLong(next());
	}
	
	static double nextDouble() throws IOException {
		return parseDouble(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}