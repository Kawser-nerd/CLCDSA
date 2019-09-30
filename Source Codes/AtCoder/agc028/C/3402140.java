import java.io.*;
import java.util.*;

public class Main {
	long solve(int[] a) {
		int n = a.length / 2;
		long ans = 0, ansRight = 0;
		for (int i = 0; i < n; i++) {
			ans += a[2 * i];
			ansRight += a[2 * i + 1];
		}
		ans = Math.min(ans, ansRight);
		int[] c = Arrays.copyOf(a, a.length);
		Arrays.sort(c);
		long sum = 0;
		for (int i = 0; i < n - 2; i++) {
			sum += c[i];
		}
		for (int i = 0; i < n; i++) {
			int x = Math.min(a[2 * i], a[2 * i + 1]);
			int y = Math.max(a[2 * i], a[2 * i + 1]);
			ans = Math.min(ans, sum + Math.max(x, c[n - 2]) + Math.max(y, c[n - 1]));
		}
		return ans;
	}
	
	void run() {
//		stress();
		int n = in.nextInt();
		int[] a = new int[2 * n];
		for (int i = 0; i < n; i++) {
			a[2 * i] = in.nextInt();
			a[2 * i + 1] = in.nextInt();
		}
		out.println(solve(a));
	}

	void stress() {
		Random r = new Random(566);
		for (;;) {
			int[] a = new int[2 * (2 + r.nextInt(5))];
			for (int i = 0; i < a.length; i++) {
				a[i] = r.nextInt(a.length);
			}
			System.out.println(Arrays.toString(a));
			long solve = solve(a);
			long solveSlow = solveSlow(a);
			if (solve != solveSlow) {
				System.out.println("! " + solve + " " + solveSlow);
				solve(a);
				return;
			}
		}
	}
	
	long solveSlow(int[] a) {
		int n = a.length / 2;
		boolean[] mark = new boolean[n];
		return search(a, mark, 0, 0);
	}
	
	long search(int[] a, boolean[] mark, int x, long sum) {
		mark[x] = true;
		int n = a.length / 2;
		boolean last = true;
		long r = Long.MAX_VALUE;
		for (int y = 0; y < n; y++) {
			if (mark[y]) {
				continue;
			}
			last = false;
			r = Math.min(search(a, mark, y, sum + Math.min(a[2 * x], a[2 * y + 1])), r);
		}
		mark[x] = false;
		return last ? sum + Math.min(a[2 * x], a[1]) : r;
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