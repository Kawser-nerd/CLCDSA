import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;


public class Main {



	static int mod = 998244353;
	static HashMap<String,Long> dp = new HashMap();
	public static long solve(String s) {
		if (s.length() == 0) return 1;
		if (s.length() == 1) {
			return s.charAt(0) == '1' ? 2 : 1;
		}
		if (dp.containsKey(s)) {
			return dp.get(s);
		}
		long ret = (s.charAt(0) == '1' ? 2 : 1) * (solve(s.substring(1,s.length())));
		ret %= mod;
		for (int i = 0 ; i < s.length(); ++i) {
			int lst = i + 1;
			int len = i + 1;
			StringBuilder cur = new StringBuilder(s.substring(0, lst));
			while (lst + len - 1 < s.length()) {
				for (int k = lst , p = 0; k <= lst + len - 1 ; ++k, ++p) {
					if (s.charAt(k) == '0') {
						cur.setCharAt(p, '0');
					}
				}

				lst += len;
				ret += (1L*solve(cur.toString()) * solve(s.substring(lst,s.length())))%mod;
				ret %= mod;

			}
		}
		dp.put(s, ret);
		return ret;

	}
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		System.out.println(solve(sc.next()));
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.