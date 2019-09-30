import java.util.*;
import java.io.*;

public class D {
	FastScanner in;
	PrintWriter out;

	final long mod = (long) (1e9 + 7);
	
	long[][] result;
	int maxR = 6, maxC = 6;
	
	int[][] a;
	
	int[] di = new int[]{-1, 0, 1, 0};
	int[] dj = new int[]{0, 1, 0, -1};
	
	TreeSet<String> ss;
	
	boolean check() {
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				if (a[i][j] != 0) {
					int[] count = new int[5];
					for (int ii = 0; ii < 4; ii++) {
						int ni = i + di[ii], nj = j + dj[ii];
						if (nj >= a[i].length)
							nj = 0;
						if (nj < 0)
							nj = a[i].length - 1;
						if (ni < 0 || ni >= a.length)
							continue;
						count[a[ni][nj]]++;
					}
					if (count[a[i][j]] > a[i][j] || count[a[i][j]] + count[0] < a[i][j])
						return false;
				}
			}
		}
		return true;
	}
	
	void go(int ci, int cj) {
		if (ci >= a.length) {
			if (check()) {
				String[] cs = new String[a[0].length];
				for (int sj = 0; sj < a[0].length; sj++) {
					cs[sj] = "";
					for (int j = 0; j < a[0].length; j++) {
						int rj = (sj + j) % a[0].length;
						for (int i = 0; i < a.length; i++) {
							cs[sj] += "" + a[i][rj];
						}
					}
				}
				Arrays.sort(cs);
				ss.add(cs[0]);
			}
			return;
		}
		for (int i = 1; i <= 4; i++) {
			a[ci][cj] = i;
			if (!check()) {
				a[ci][cj] = 0;
				continue;
			}
			int ni = ci, nj = cj + 1;
			if (nj >= a[0].length) {
				nj = 0;
				ni++;
			}
			go(ni, nj);
			a[ci][cj] = 0;
		}
	}
	
	long f(int r, int c) {
		System.err.println(r + " " + c);
		a = new int[r][c];
		ss = new TreeSet<>();
		go(0, 0);
		return ss.size();
	}
	
	void calcResult() {
		result = new long[maxR + 1][maxC + 1];
		for (int r = 2; r <= maxR; r++) {
			for (int c = 3; c <= maxC; c++) {
				result[r][c] = f(r, c);
			}
		}
	}
	
	public void solve() throws IOException {
		int r = in.nextInt(), c = in.nextInt();
		out.println(result[r][c]);
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));

			calcResult();
			
			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
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

	public static void main(String[] arg) {
		new D().run();
	}
}