import java.util.*;
import java.io.*;

public class A {
	FastScanner in;
	PrintWriter out;

	int[] order = new int[] { 0, 6, 8, 3, 2, 4, 5, 7, 9, 1 };
	String[] name = new String[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

	public void solve() throws IOException {
		char[] s = in.next().toCharArray();
		int[] cnt = new int[26];
		for (char cc : s) {
			cnt[cc - 'A']++;
		}
		int[] res = new int[10];
		for (int x : order) {
			int[] need = new int[26];
			for (char c : name[x].toCharArray()) {
				need[c - 'A']++;
			}
			while (true) {
				boolean ok = true;
				for (int i = 0; i < 26; i++) {
					if (cnt[i] < need[i]) {
						ok = false;
						break;
					}
				}
				if (!ok) {
					break;
				}
				for (int i = 0; i < 26; i++) {
					cnt[i] -= need[i];
				}
				res[x]++;
			}
		}
		for (int i = 0; i < cnt.length; i++) {
			if (cnt[i] > 0) {
				throw new AssertionError();
			}
		}
		for (int i = 0; i < res.length; i++) {
			for (int j = 0; j < res[i]; j++) {
				out.print(i);
			}
		}
		out.println();
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));

			int tn = in.nextInt();
			for (int i = 0; i < tn; i++) {
				System.err.println(i);
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] arg) {
		new A().run();
	}
}