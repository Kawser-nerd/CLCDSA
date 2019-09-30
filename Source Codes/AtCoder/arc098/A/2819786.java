import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char c[] = sc.next().toCharArray();
		int pre[] = new int[n];
		int suf[] = new int[n];
		for (int i = 0 ; i < n ; ++i) {
			pre[i] += c[i] == 'W' ? 1 : 0;
			if (i > 0) {
				pre[i] += pre[i - 1];
			}
		}
		for (int i = n - 1 ; i >= 0 ; --i) {
			suf[i] = c[i] == 'E' ? 1 : 0;
			if (i + 1 < n) {
				suf[i] += suf[i + 1];
			}
		}
		int ans = 1 << 30;
		for (int i = 0 ; i < n ; ++i) {
			int before = 0;
			int after = 0;
			if (i - 1 >= 0) {
				before += pre[i - 1];
			}
			if (i + 1 < n) {
				after += suf[i + 1];
			}
			ans = Math.min(before + after,ans);
		}
		System.out.println(ans);
	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(String s) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(s)));
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

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}
	}
}