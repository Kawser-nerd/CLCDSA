import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;

public class DFaster implements Runnable {
	public static void main(String[] args) throws IOException {
		new Thread(new DFaster()).start();
	}

	public BufferedReader br;

	public StringTokenizer in;

	public PrintWriter out;

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

	public void solve() throws IOException {
		String s = nextToken();
		int n = s.length();
		int m = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'X')
				m += 1 << i;
		}

		double[] ans = new double[1 << n];
		double[] c = new double[1 << n];
		c[m] = 1;
		for (int mask = 0; mask < ans.length - 1; mask++) {
			for (int i = 0; i < n; i++) {
				int j = i;
				int cnt = 0;
				while (((1 << j) & mask) != 0) {
					j = (j + 1) % n;
					cnt++;
				}

				ans[mask | (1 << j)] += (ans[mask] + c[mask] * (n - cnt)) / n;
				c[mask | (1 << j)] += c[mask] / n;
			}
		}

		out.println(ans[(1 << n) - 1]);
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");

			int t = nextInt();
			for (int i = 0; i < t; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
				System.err.println("Test case " + i + " ended!");
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
