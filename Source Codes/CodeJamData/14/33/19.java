import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class ProblemC {

	public static void main(String[] args) throws IOException {
		
		ProblemC solver = new ProblemC();
		solver.init();
		solver.solve();
	}
	
	void init() {
	}
	
	private void solve() throws IOException {
		
		Reader in = new Reader(System.in);
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = in.nextInt();
			int M = in.nextInt();
			int K = in.nextInt();
			int r = find(N,M,K);
			out.println("Case #" + t + ": " + r);
		}
		out.flush();
		out.close();
	}
	
	private int find(int N, int M, int K) {
		int best = N * M;
		int B = N * M;
		for (int mask = 0; mask < (1 << B) ; mask++) {
			boolean[][] stones = convert(mask, N , M);
			boolean[][] vis = new boolean[N][M];
			for (int i = 0; i < N; i++) for(int j = 0; j < M; j++) if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
				dfs(vis,i,j,N,M,stones);
			}
			int k = 0;
			for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (vis[i][j]) k++;
			if (N * M - k >= K)
			best = Math.min(best, Integer.bitCount(mask));
		}
		return best;
	}

	private void dfs(boolean[][] vis, int i, int j, int n, int m,
			boolean[][] stones) {
		if (i < 0 || i >= n || j < 0 || j >= m) return;
		if (stones[i][j] || vis[i][j]) return;
		vis[i][j] = true;
		dfs(vis, i - 1, j, n, m, stones);
		dfs(vis, i + 1, j, n, m, stones);
		dfs(vis, i, j - 1, n, m, stones);
		dfs(vis, i, j + 1, n, m, stones);
		
	}

	private boolean[][] convert(int mask, int n, int m) {
		boolean[][] b = new boolean[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				b[i][j] = ((mask & (1 << (i * m + j))) > 0);
			}
		return b;
	}

	private static class Reader {
	    BufferedReader reader;
	    StringTokenizer tokenizer;

	    /** call this method to initialize reader for InputStream */
	    Reader(InputStream input) {
	        reader = new BufferedReader(
	                     new InputStreamReader(input) );
	        tokenizer = new StringTokenizer("");
	    }

	    public void skipLine() throws IOException {
			reader.readLine();
		}

		/** get next word */
	    public String next() throws IOException {
	        while ( ! tokenizer.hasMoreTokens() ) {
	            //TODO add check for eof if necessary
	            tokenizer = new StringTokenizer(
	                   reader.readLine() );
	        }
	        return tokenizer.nextToken();
	    }

	    public int nextInt() throws IOException {
	        return Integer.parseInt( next() );
	    }
	    
	    public double nextDouble() throws IOException {
	        return Double.parseDouble( next() );
	    }
	    
	    public long nextLong() throws IOException {
	    	return Long.parseLong(next());
	    }
	}
}
