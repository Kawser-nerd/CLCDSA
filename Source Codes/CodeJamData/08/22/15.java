import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {

	boolean[] w;
	int n;

	ArrayList<ArrayList<Integer>> e;
	
	void prepare() {
		boolean[] w = new boolean[1500000];
		table = new boolean[1500000];

		for (int i = 2; i <= 1000000; i++) {
			if (!w[i]) {
				table[i] = true;
				for (int j = i; j <= 1000000; j += i) {
					w[j] = true;
				}
			}
		}
	}
	
	boolean[] table;
	
	boolean isPrime(long x) {
		if (x <= 1e6) {
			return table[(int) x];
		}
		if (x == 1) {
			return false;
		}
		if (x == 2) {
			return true;
		}
		for (long i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}
	
	void dfs(int x) {
		w[x] = true;
		for (int i : e.get(x)) {
			if (!w[i]) {
				dfs(i);
			}
		}
	}
	
	void solve() throws Exception {
		prepare();
		int tc = nextInt();
		for (int tt = 0; tt < tc; tt++) {
			long a = nextLong();
			long b = nextLong();
			long p = nextLong();
			n = (int) (b - a + 1);

			e = new ArrayList<ArrayList<Integer>>();
			for (int i = 0; i < n; i++) {
				e.add(new ArrayList<Integer>());
			}
			
			for (long i = p; i <= b - a + 100; i++) {
				if (!table[(int) i]) {
					continue;
				}
				long t = a / i;
				if (a % i != 0) {
					t++;
				}
				long cur = t * i;
				while (cur + i <= b) {
					long next = cur + i;
					e.get((int) (cur - a)).add((int) (next - a));
					e.get((int) (next - a)).add((int) (cur - a));
					cur += i;
				}
			}
			
			int ans = 0;
			w = new boolean[n];
			for (int i = 0; i < n; i++) {
				if (!w[i]) {
					dfs(i);
					ans++;
				}
			}
			
			out.println("Case #" + (tt + 1) + ": " + ans);
			System.out.println(tt + 1);
		}
	}
	
	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new Thread(new Solution("b")).start();
	}

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	public Solution(String fname) throws IOException {
		in = new BufferedReader(new FileReader(fname + ".in"));
		st = new StringTokenizer("");
		out = new PrintWriter(new FileWriter(fname + ".out"));
	}
	
	
	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	
	long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(nextToken());
	}

	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}
	
	public void run() {
		try {
			solve();
		} catch (Exception e) {
			apstenu(e);
		} finally {
			out.close();
		}
	}

	private void apstenu(Exception e) {
		e.printStackTrace();
		System.exit(1);
	}
	
}
