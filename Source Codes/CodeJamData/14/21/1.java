import java.io.*;
import java.util.*;

public class Repeater {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		String[] s = new String[n];
		String[] t = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = in.nextToken();
			t[i] = unique(s[i]);
		}

		for (int i = 0; i < n; i++) {
			if (!t[i].equals(t[0])) {
				out.println("Fegla won");
				return;
			}
		}
		int ans = 0;

		for (char c : t[0].toCharArray()) {
			int[] cnt = new int[n];
			for (int j = 0; j < n; j++) {
				while (cnt[j] < s[j].length() && s[j].charAt(cnt[j]) == c) {
					cnt[j]++;
				}
			}
			ans += solve(cnt);
			for (int j = 0; j < n; j++) {
				s[j] = s[j].substring(cnt[j]);
			}
		}
		out.println(ans);

	}

	private int solve(int[] cnt) {
		cnt = cnt.clone();
		Arrays.sort(cnt);
		
		int best = Integer.MAX_VALUE;
		for (int i = 0; i < cnt.length; i++) {
			int cur = 0;
			for (int j = 0; j < cnt.length; j++) {
				cur += Math.abs(cnt[i] - cnt[j]);
			}
			best = Math.min(best, cur);
		}
		return best;
	}

	private String unique(String s) {
		StringBuilder sb = new StringBuilder();
		sb.append(s.charAt(0));
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i) != s.charAt(i - 1)) {
				sb.append(s.charAt(i));
			}
		}
		return sb.toString();
	}

	void run() {
		try {
			in = new FastScanner("input.txt");
			out = new PrintWriter("output.txt");
			int T = in.nextInt();
			for (int i = 1; i <= T; i++) {
				long time = System.currentTimeMillis();
				out.printf("Case #%d: ", i);
				solve();
				System.err.println("Test #" + i + " done in " + (System.currentTimeMillis() - time)
						+ " ms");
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new Repeater().run();
	}
}
