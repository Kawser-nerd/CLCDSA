import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int[][] dp;
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		N = sc.nextInt();
		int a = sc.nextInt() - 1;
		int b = sc.nextInt() - 1;
		int M = sc.nextInt();
		int[] x = new int[M];
		int[] y = new int[M];
		long MOD = 1000000007;
		dp = new int[N][N];
		for(int i = 0; i < M; i++) {
			x[i] = sc.nextInt() - 1;
			y[i] = sc.nextInt() - 1;
			dp[x[i]][y[i]] = 1;
			dp[y[i]][x[i]] = 1;
		}
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(i != j && dp[i][j] == 0) dp[i][j] = 1000;
			}
		}
		Warshall_Floyd();
		// ???DAG
		int[][] dag = new int[N][N];
		for(int i = 0; i < M; i++) {
			if(dp[a][x[i]] == dp[a][y[i]] + 1) dag[y[i]][x[i]] = 1;
			if(dp[a][x[i]] == dp[a][y[i]] - 1) dag[x[i]][y[i]] = 1;
		}
		// ???????
		HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
		for(int i = 0; i < N; i++) {
			int d = dp[a][i];
			if(map.containsKey(d)) {
				ArrayList<Integer> list = map.get(d);
				list.add(i);
				map.put(d, list);
			} else {
				ArrayList<Integer> list = new ArrayList<Integer>();
				list.add(i);
				map.put(d, list);
			}
		}
		long[] minStep = new long[N];
		minStep[a] = 1;
		for(int i = 0; i < dp[a][b]; i++) {
			ArrayList<Integer> list = map.get(i);
			for(int j = 0; j < list.size(); j++) {
				int town = list.get(j);
				for(int k = 0; k < N; k++) {
					if(dag[town][k] == 1) minStep[k] = (minStep[k] + minStep[town]) % MOD;
				}
			}
		}
		System.out.println(minStep[b]);
	}
	public static void Warshall_Floyd() {
		for(int k=0; k<N; k++) {
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
	}
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
	static class SC {
		private BufferedReader reader = null;
		private StringTokenizer tokenizer = null;
		public SC(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
		}
		public String next() {
			if (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new UncheckedIOException(e);
				}
			}
			return tokenizer.nextToken();
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
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}
	}
}