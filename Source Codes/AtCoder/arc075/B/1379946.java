import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static long A, B;
	static long[] a;

	static boolean p(long mid) {
		long extra = 0;
		for (int i = 0; i < N; i++) {
			long leftHealth = a[i] - (mid * B);
			if (leftHealth > 0)
				extra += leftHealth % (A - B) == 0 ? leftHealth / (A - B) : (leftHealth / (A - B)) + 1;
		}
		return extra <= mid;
	}

	static long BinarySearch() {
		long low = 0, high = (int) 1e9, ans = 0;
		while (low <= high) {
			long mid = low + ((high - low) >> 1);
			if (p(mid)) {
				high = mid - 1;
				ans = mid;
			} else
				low = mid + 1;
		}
		return ans;
	}

	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		N = sc.nextInt();
		A = sc.nextLong();
		B = sc.nextLong();
		a = new long[N];
		for (int i = 0; i < N; i++)
			a[i] = sc.nextLong();
		out.println(BinarySearch());
		out.flush();
		out.close();
	}

	static class MyScanner {
		StringTokenizer st;
		BufferedReader br;

		public MyScanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public MyScanner(String file) throws IOException {
			br = new BufferedReader(new FileReader(new File(file)));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public boolean ready() throws IOException {
			return br.ready();
		}
	}
}