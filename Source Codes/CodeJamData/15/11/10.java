import java.io.*;
import java.util.*;

public class taskA {

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
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int y = 0;
		int z = 0;
		int minS = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) {
				y += a[i - 1] - a[i];
				minS = Math.max(minS, a[i - 1] - a[i]);
			}
		}
//		System.err.println("==");
		for (int i = 0; i < n - 1; i++) {
//			System.err.println(a[i] + " " + minS);
			z += Math.min(a[i], minS);
		}
		out.println(y + " " + z);
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			br = new BufferedReader(new FileReader("taskA.in"));
			out = new PrintWriter("taskA.out");
			int n = nextInt();
			for (int i = 0; i < n; i++) {

				out.print("Case #" + (i + 1) + ": ");
				solve();
			}
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new taskA().run();
	}
}
