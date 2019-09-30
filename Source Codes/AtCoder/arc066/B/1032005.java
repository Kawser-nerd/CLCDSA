import java.io.*;
import java.util.*;

public class Main {
	static final int MOD = 1_000_000_007;
	static final boolean DEBUG = !true;
	
	long n;
	Map<Long, Map<Long, Integer>> memo = new TreeMap<>();

	void run() {
		n = in.nextLong() + 1;
		if (DEBUG) {
			boolean[][] nice = new boolean[(int) n][(int) n];
			for (int a = 0; a < n; a++) {
				for (int b = 0; a + b < n; b++) {
					int u = a ^ b;
					int v = a + b;
					if (u < n) {
						nice[u][v] = true;
					}
				}			
			}
			for (int u = 0; u < n; u++) {
				for (int v = 0; v < n; v++) {
					System.out.print(nice[u][v] ? "0" : ".");
				}			
				System.out.println();
			}
		}
		long level = 1;
		while (level < n) {
			memo.put(level, new TreeMap<>());
			level *= 2;
		}
		out.println(solve(level, 0));
	}

	int solve(long level, long x) {
		if (x >= n) {
			return 0;
		}
		if (x + 2 * level - 1 <= n) {
			return size(level);
		}
		level /= 2;
		if (memo.get(level).containsKey(x)) {
			return memo.get(level).get(x);
		}
		int res = solve(level, x);
		res += solve(level, x + level);
		res %= MOD;
		res += solve(level, x + 2 * level);
		res %= MOD;
		memo.get(level).put(x, res);
		return res;
	}
	
	int size(long level) {
		if (level == 1) {
			return 1;
		}
		return (int) (3L * size(level / 2) % MOD);
	}

	static MyScanner in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		boolean stdStreams = true;
		String fileName = Main.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
		String inputFileName = fileName + ".in";
		String outputFileName = fileName + ".out";
		
		Locale.setDefault(Locale.US);
		BufferedReader br;
		if (stdStreams) {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
			br = new BufferedReader(new FileReader(inputFileName));
			out = new PrintWriter(outputFileName);
		}
		in = new MyScanner(br);
		int tests = 1;//in.nextInt();
		for (int test = 0; test < tests; test++) {
			new Main().run();
		}
		br.close();
		out.close();
	}
	
	static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		MyScanner(BufferedReader br) {
			this.br = br;
		}
		
		void findToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
		}
		
		String next() {
			findToken();
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		long nextLong() {
			return Long.parseLong(next());
		}
		
		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}