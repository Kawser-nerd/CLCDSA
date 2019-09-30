import java.io.*;
import java.util.*;

public class B {

	int len = 35;

	int[] toArr(int k) {
		int[] ans = new int[len];
		for (int i = 0; i < len; i++) {
			ans[i] = k % 2;
			k /= 2;
		}
		return ans;
	}

	int[] max = new int[len];

	HashMap<String, Long> map = new HashMap<>();

	long eval(int[] a, int[] b, int[] k, int pos) {
		String state = Arrays.toString(a) + " " + Arrays.toString(b) + " "
				+ Arrays.toString(k) + " " + pos;
		if (pos < 0) {
			return 1;
		}
		if (map.containsKey(state)) {
			return map.get(state);
		}

		long ans = 0;
		for (int val1 = 0; val1 <= a[pos]; val1++) {
			for (int val2 = 0; val2 <= b[pos]; val2++) {
				if ((val1 & val2) <= k[pos]) {
					ans += eval(val1 == a[pos] ? a : max, val2 == b[pos] ? b
							: max, (val1 & val2) == k[pos] ? k : max, pos - 1);
				}

			}
		}
		map.put(state, ans);
		return ans;
	}

	void solve() throws IOException {
		Arrays.fill(max, 1);
		int[] a = toArr(nextInt() - 1);
		int[] b = toArr(nextInt() - 1);
		int[] k = toArr(nextInt() - 1);
		out.println(eval(a, b, k, len - 1));
	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("B.in"));
		out = new PrintWriter("B.out");
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println(i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().run();
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
