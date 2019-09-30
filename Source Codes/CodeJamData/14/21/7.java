import java.io.*;
import java.util.*;

public class A {

	public int eval(String[] s) {
		int[] type = new int[500];
		for (int i = 0; i < s.length; i++) {
			type[s[i].charAt(0)]++;
		}
		for (int i = 0; i < 500; i++) {
			if (type[i] > 0 && type[i] < s.length) {
				return -1;
			}
		}
		if (type['$'] > 0) {
			return 0;
		}
		int[] len = new int[s.length];
		for (int i = 0; i < s.length; i++) {
			while (s[i].charAt(len[i]) == s[i].charAt(0)) {
				len[i]++;
			}
		}
		int add = Integer.MAX_VALUE;
		for (int i = 0; i < s.length; i++) {
			int cur = 0;
			for (int j = 0; j < s.length; j++) {
				cur += Math.abs(len[i] - len[j]);
			}
			add = Math.min(add, cur);
		}
		for (int i = 0; i < s.length; i++) {
			s[i] = s[i].substring(len[i]);
		}
		int next = eval(s);
		if (next == -1) {
			return next;
		} else {
			return next + add;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = next()+"$";
		}
		int ans = eval(s);
		System.err.println(ans);
		if (ans == -1) {
			out.println("Fegla Won");
		} else {
			out.println(ans);
		}
	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("A.in"));
		out = new PrintWriter("A.out");
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println(i);
			out.print("Case #"+i+": ");
			solve();			
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String temp = in.readLine();
			if (temp == null) {
				return null;
			}
			st = new StringTokenizer(temp);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

}
