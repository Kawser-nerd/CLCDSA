import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		
		try {
			inputStream = new FileInputStream("a.in");
			outputStream = new FileOutputStream("a.out");
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		solver.count(1000000);
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			out.format("Case #%d: ", i + 1);
			solver.solve(in, out);
		}
		
		out.close();
	}
}

class Solver {
	double[][] dp;
	double[][] dp1;
	int[] h;
	int[] sum;
	public void count(int n) {
		h = new int [n + 1];
		sum = new int [n + 1];
		int s = 1;
		int c = 1;
		h[0] = 0;
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			while (s <= i) {
				c++;
				s += c;
				c++;
				s += c;
			}
			s -= c;
			c--;
			s -= c;
			c--;
			h[i] = c + 1;
			sum[i] = s;
		}
		int maxh = h[n];
		dp = new double[maxh + 1][maxh + 1];
		dp[0][0] = 1.0;
		for (int i = 0; i <= maxh; i++) {
			for (int j = 0; j <= maxh; j++) {
				if (i == 0 && j == 0)
					continue;
				if (i == 0)
					dp[i][j] = 0.5 * dp[i][j - 1];
				if (j == 0)
					dp[i][j] = 0.5 * dp[i - 1][j];
				if (i != 0 && j != 0)
					dp[i][j] = 0.5 * (dp[i][j - 1] + dp[i - 1][j]);
			}
		}
		dp1 = new double[maxh + 1][maxh + 1];
		dp1[0][0] = 1.0;
		for (int i = 2; i <= maxh; i += 2) {
			dp1[i][0] = 0.5 * dp[i - 1][0];
			for (int j = 1; j < i; j++) {
				dp1[i][j] = dp1[i][j - 1] + 0.5 * dp[i - 1][j];
			}
			dp1[i][i] = 1.0;
		}
		return;
	}
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int x = in.nextInt();
		int y = in.nextInt();
		if (x < 0)
			x = -x;
		int d = (x + y) / 2;
		int dn = h[n] / 2 - 1;
		double ans = 1.0;
		if (d == dn + 1) {
			int c = n - sum[n]; 
			int nm = 2 * d - x + 1;
			if (nm <= 0 || nm > c || nm > 2 * d)
				ans = 0.0;
			else {
				ans = 0.0;
				//int rem = c - nm;
				for (int i = Math.max(nm, c - 2 * d); i <= Math.min(2 * d, c); ++i) {
					if (i == 2 * d)
						ans += dp1[i][c - i];
					else
						if (c - i == 2 * d)
							ans += dp1[c - i][i];
						else
							ans += dp[i][c - i];
							
				}
			}
		} else {
			if (d <= dn)
				ans = 1.0;
			else {
				ans = 0.0;
			}
		}
		if (ans > 1.0 + 1e-10)
			System.err.println("!!!");
		out.format("%.8f\n", ans);
		
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
