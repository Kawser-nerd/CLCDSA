import java.io.*;
import java.util.*;

public class taskB {

	PrintWriter out;
	BufferedReader br;
	StringTokenizer st;

	String nextToken() throws IOException {
		while ((st == null) || (!st.hasMoreTokens()))
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
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
		int t = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		long l = -1;
		long r = 100000L * (t + 1);
		while (l < r - 1) {
			long c = (l + r) / 2;
			long done = 0;
		
			for (int i = 0; i < n; i++) {
				done += (c + a[i] - 1) / a[i];
			}

			if (done >= t) {
				r = c;
			} else {
				l = c;
			}
		}
		System.err.println(l);
		long done = 0;

		for (int i = 0; i < n; i++) {
			done += (l + a[i] - 1) / a[i];
		}

		int d = (int) (t - done - 1);
		for (int i = 0; i < n; i++) {
			if (l % a[i] == 0) {
				if (d == 0) {
					out.println(i + 1);
					return;
				} else {
					d--;
				}
			}
		}
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			br = new BufferedReader(new FileReader("taskB.in"));
			out = new PrintWriter("taskB.out");
			int n = nextInt();
			for (int i = 0; i < n; i++) {
				System.err.println("Case #" + (i + 1));
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new taskB().run();
	}
}
