import java.util.*;
import java.io.*;

public class Main {

	class Trie {
		int[][] next;
		int states;

		public Trie() {
			next = new int[2][(int) 2e5];
			states = 1;
			for (int[] i : next) {
				Arrays.fill(i, -1);
			}
		}

		void add(String s) {
			int cur = 0;
			for (char c : s.toCharArray()) {
				c -= '0';
				if (next[c][cur] == -1) {
					next[c][cur] = states++;
				}
				cur = next[c][cur];
			}
		}

		long get(long len) {
			return get(0, len);
		}

		long get(int cur, long len) {
			if (len < 0) {
				return 0;
			}
			if (cur == -1) {
				len++;
				return 1L << (Long.numberOfTrailingZeros(len));
			}

			return get(next[0][cur], len - 1) ^ get(next[1][cur], len - 1);
		}
	}

	void solve() {
		int n = in.nextInt();
		long l = in.nextLong();
		Trie t = new Trie();
		int[] grundy = new int[100];
		grundy[0] = 1;
//		for (int i = 1; i < grundy.length; i++) {
//			Set<Integer> set = new HashSet<>();
//			set.add(0);
//			for (int d = i - 1; d >= 0; d--) {
//				int cur = 0;
//				for (int j = d; j <= i + 1; j++) {
//					cur ^= grundy[j];
//				}
//				set.add(cur);
//			}
//			while (set.contains(grundy[i])) {
//				grundy[i]++;
//			}
//			System.err.println(i + " " + grundy[i]);
//		}

		for (int i = 0; i < n; i++) {
			t.add(in.nextToken());
		}
		out.println(t.get(l) == 0 ? "Bob" : "Alice");
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