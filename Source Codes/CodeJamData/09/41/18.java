import java.io.*;
import java.util.*;

public class A implements Runnable {

	public static void main(String[] args) {
		new Thread(new A()).start();
	}

	BufferedReader br;

	StringTokenizer st;

	PrintWriter out;

	public final String FN = "A-large";

	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FN + ".in"));
			out = new PrintWriter(FN + ".out");
			int T = nextInt();
			for (int i = 0; i < T; i++) {
				solve(i + 1);
			}
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
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

	private void solve(int T) throws IOException {
		int N = nextInt();
		int a[][] = new int[N][N];
		int b[] = new int[N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				a[i][j] = br.read() - '0';
				if (a[i][j] == 1)
					b[i] = j;
			}
			br.readLine();
		}
		int res = 0;
		for (int i = 0; i < N; i++) {
			if (b[i] > i) {
				int j = i + 1;
				while (j < N) {
					if (b[j] <= i) {
						res += j - i;
						for (int k = j; k > i; k--) {
							b[k] = b[k - 1];
						}
						break;
					}
					j++;
				}
				if (j == N)
					System.err.println("FUCK");
			}
		}
		out.println("Case #" + T + ": " + res);
	}
}