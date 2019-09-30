package RoundB2013;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class B implements Runnable {
	public static void main(String[] args) {
		new Thread(new B()).run();
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
		int n = nextInt();
		int x = nextInt();
		int y = nextInt();

		int c = 0;
		while (n >= 4 * c + 1) {
			n -= 4 * c + 1;
			c++;
		}

		if (x < 0) {
			x = -x;
		}

		if (x + y <= 2 * (c - 1)) {
			out.println(1);
			return;
		}

		if (x + y > 2 * c) {
			out.println(0);
			return;
		}

		double[] p = new double[2 * c + 1];
		double[] tp = new double[2 * c + 1];

		p[0] = 1;

		double ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < tp.length; j++) {
				if (i - j >= 2 * c) {
					tp[j + 1] += p[j];
					continue;
				}

				if (j == 2 * c) {
					tp[j] += p[j];
					continue;
				}
				tp[j] += p[j] / 2;
				tp[j + 1] += p[j] / 2;
			}
			for (int j = 0; j < tp.length; j++) {
				p[j] = tp[j];
				tp[j] = 0;
			}
		}

		for (int i = y + 1; i < tp.length; i++) {
			ans += p[i];
		}

		out.println(ans);
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
