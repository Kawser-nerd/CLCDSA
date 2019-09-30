import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class Main {

	void solve() {
		int R = sc.nextInt();
		int C = sc.nextInt();
		int Q = sc.nextInt();

		char[][] S = new char[R][];
		for (int r = 0; r < R; r++) {
			S[r] = sc.next().toCharArray();
		}
		
		int[][] vs = new int[R+1][C+1];
		int[][] e0 = new int[R+1][C+1];
		int[][] e1 = new int[R+1][C+1];
		
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				vs[r+1][c+1] = vs[r][c+1] + vs[r+1][c] - vs[r][c] + (S[r][c] =='1' ? 1 : 0);
			}
		}
		
		for (int r = 0; r < R; r++) {
			for (int c = 0; c + 1 < C; c++) {
				e0[r+1][c+1] = e0[r][c+1] + e0[r+1][c] - e0[r][c] + 
					(S[r][c] =='1' && S[r][c+1] =='1' ? 1 : 0);
			}
		}

		for (int r = 0; r + 1 < R; r++) {
			for (int c = 0; c < C; c++) {
				e1[r+1][c+1] = e1[r][c+1] + e1[r+1][c] - e1[r][c] + 
					(S[r][c] =='1' && S[r+1][c] == '1' ? 1 : 0);
			}
		}

		for (int q = 0; q < Q; q++) {
			int x1 = sc.nextInt() - 1;
			int y1 = sc.nextInt() - 1;
			int x2 = sc.nextInt();
			int y2 = sc.nextInt();
			int V = vs[x2][y2] - vs[x2][y1] - vs[x1][y2] + vs[x1][y1];
			int E0 = e0[x2][y2-1] - e0[x2][y1] - e0[x1][y2-1] + e0[x1][y1];
			int E1 = e1[x2-1][y2] - e1[x2-1][y1] - e1[x1][y2] + e1[x1][y1];
			int ans = V - (E0 + E1);
			out.println(ans);
		}

	}

	static void tr(Object... os) { System.err.println(deepToString(os)); }

	public static void main(String[] args) throws Exception {
		new Main().run();
	}

	MyScanner sc = null;
	PrintWriter out = null;
	public void run() throws Exception {
		sc = new MyScanner(System.in);
		out = new PrintWriter(System.out);
		for (;sc.hasNext();) {
			solve();
			out.flush();
		}
		out.close();
	}

	class MyScanner {
		String line;
		BufferedReader reader;
		StringTokenizer tokenizer;

		public MyScanner(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}
		public void eat() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					line = reader.readLine();
					if (line == null) {
						tokenizer = null;
						return;
					}
					tokenizer = new StringTokenizer(line);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
		}
		public String next() {
			eat();
			return tokenizer.nextToken();
		}
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		public boolean hasNext() {
			eat();
			return (tokenizer != null && tokenizer.hasMoreElements());
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) a[i] = nextInt();
			return a;
		}
	}
}