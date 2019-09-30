import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	public static final long MOD = 1000000007;
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		
		final int N = sc.nextInt();
		final int a = sc.nextInt() - 1;
		final int b = sc.nextInt() - 1;

		boolean[][] initial_adj_bool = new boolean[N][N];
		boolean[][] adj_bool = new boolean[N][N];
		boolean[][] next_adj_bool = new boolean[N][N];
		
		long[][] initial_adj_mod = new long[N][N];
		long[][] adj_mod = new long[N][N];
		long[][] next_adj_mod = new long[N][N];
		
		final int M = sc.nextInt();
		for(int i = 0; i < M; i++){
			final int x = sc.nextInt() - 1;
			final int y = sc.nextInt() - 1;
			initial_adj_bool[x][y] = initial_adj_bool[y][x] = adj_bool[x][y] = adj_bool[y][x] = true;
			initial_adj_mod[x][y] = initial_adj_mod[y][x] = adj_mod[x][y] = adj_mod[y][x] = 1;
		}
		
		while(!adj_bool[a][b]){
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					next_adj_bool[i][j] = false;
					next_adj_mod[i][j] = 0;
				}
			}
			
			// Matrix multiplication
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					for(int k = 0; k < N; k++){
						next_adj_bool[i][j] |= adj_bool[i][k] && initial_adj_bool[k][j];
						next_adj_mod[i][j] += (adj_mod[i][k] * initial_adj_mod[k][j]) % MOD;
						next_adj_mod[i][j] %= MOD;
					}
				}
			}
			
			// swap
			{
				boolean[][] tmp = adj_bool;
				adj_bool = next_adj_bool;
				next_adj_bool = tmp;
			}
			{
				long[][] tmp = adj_mod;
				adj_mod = next_adj_mod;
				next_adj_mod = tmp;
			}
		}
		
		System.out.println(adj_mod[a][b]);
	}

	public static class Scanner implements Closeable {
		private BufferedReader br;
		private StringTokenizer tok;

		public Scanner(InputStream is) throws IOException {
			br = new BufferedReader(new InputStreamReader(is));
		}

		private void getLine() throws IOException {
			while (!hasNext()) {
				tok = new StringTokenizer(br.readLine());
			}
		}

		private boolean hasNext() {
			return tok != null && tok.hasMoreTokens();
		}

		public String next() throws IOException {
			getLine();
			return tok.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public int[] nextIntArray(int n) throws IOException {
			final int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = this.nextInt();
			}
			return ret;
		}

		public long[] nextLongArray(int n) throws IOException {
			final long[] ret = new long[n];
			for (int i = 0; i < n; i++) {
				ret[i] = this.nextLong();
			}
			return ret;
		}

		public void close() throws IOException {
			br.close();
		}
	}
}