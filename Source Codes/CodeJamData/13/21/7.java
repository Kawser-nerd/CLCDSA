package RoundB2013;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A implements Runnable {
	public static void main(String[] args) {
		new Thread(new A()).run();
	}

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens()) {
			in = new StringTokenizer(br.readLine());
		}

		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public void solve() throws IOException {
		int a = nextInt();
		int n = nextInt();
		int[] s = new int[n];

		for (int i = 0; i < s.length; i++) {
			s[i] = nextInt();
		}

		Arrays.sort(s);

		int[][] ans = new int[n + 1][n + 1];

		ans[0][0] = a;
		for (int i = 0; i < n; i++) {
			for (int get = 0; get < ans.length; get++) {
				if (ans[i][get] == 0)
					continue;

				if (get + 1 <= n)
					ans[i + 1][get + 1] = Math.max(ans[i + 1][get + 1],
							ans[i][get]);

				int now = ans[i][get];

				if (now == 1)
					continue;

				int cnt = 0;
				while (now <= s[i]) {
					cnt++;
					now = 2 * now - 1;
				}

				if (get + cnt <= n)
					ans[i + 1][get + cnt] = Math.max(ans[i + 1][get + cnt], now
							+ s[i]);
			}
		}

		for (int i = 0; i < n + 1; i++) {
			if (ans[n][i] != 0) {
				out.println(i);
				return;
			}
		}
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");

			int t = nextInt();
			for (int i = 0; i < t; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
