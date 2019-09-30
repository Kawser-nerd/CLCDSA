import java.util.*;
import java.io.*;

public class Main {

	static int mod = 998244353;
	
	Map<String, Integer> memo = new HashMap<>();
	Map<String, Integer> compMemo = new HashMap<>();
	static int[] pow2 = new int[200];
	static {
		pow2[0] = 1;
		for (int i = 1; i < 200; i++) {
			pow2[i] = pow2[i - 1] * 2 % mod;
		}
	}
	
	int go(String s) {
		if (memo.containsKey(s)) {
			return memo.get(s);
		}
		if (s.length() == 0) {
			return 1;
		}
		int result = 0;
		for (int len = 2; len <= s.length(); len++) {
			result += (1L * compress(s.substring(0, len)) * go(s.substring(len)) % mod);
			if (result >= mod){ 
				result -= mod;
			}
		}
		result += go(s.substring(1)) * (s.charAt(0) - '0' + 1) % mod;
		if (result >= mod){
			result -= mod;
		}
		memo.put(s, result);
		return result;
	}
	
	int compress(String s) {
		int result = 0;
		if (compMemo.containsKey(s)) {
			return compMemo.get(s);
		}
		for (int k = 2; k <= s.length(); k++) {
			if (s.length() % k == 0) {
				char[] a = new char[s.length() / k];
				Arrays.fill(a, '1');
				for (int j = 0; j < s.length(); j++) {
					if (s.charAt(j) == '0') {
						a[j % a.length] = '0';
					}
				}
				result += go(new String(a));
				if (result >= mod) {
					result -= mod;
				}
			}
		}
		compMemo.put(s, result);
		return result;
	}
	
	void solve() {
		out.println(go(in.nextToken()));
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}