import java.util.*;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

	void solve() {
		if (ask((long) 1e12)) {
			for (int i = 0; i <= 10; i++) {
				long ans = (long) (Math.pow(10, i) + 1);
				if (ask(ans)) {
					answer(ans - 1);
					return;
				}
			}
			throw new AssertionError();
		}

		for (int len = 10; len >= 0; len--) {
			out.print("? 1");
			for (int i = 0; i < len; i++) {
				out.print('0');
			}
			out.println();
			out.flush();

			boolean res = get();
			if (res) {
				go(len + 1);
				return;
			}
		}
	}

	private void answer(long i) {
		out.println("! " + i);
		out.flush();
		return;
	}

	private void go(int i) {
		long left = (long) Math.pow(10, i - 1), right = (long) (Math.pow(10, i) - 1);
		left--;
		right++;

		while (left < right - 1) {
			long mid = (left + right) >>> 1;
			out.println("? " + mid + "0");
			out.flush();
			if (get()) {
				right = mid;
			} else {
				left = mid;
			}
		}
		answer(right);
	}

	boolean ask(long x) {
		out.println("? " + x);
		out.flush();
		return get();
	}

	private boolean get() {
		char res = in.nextToken().charAt(0);
		return res == 'Y';
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}