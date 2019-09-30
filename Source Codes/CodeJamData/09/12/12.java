import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;

public class B {
	static int N, M;
	static int[][] S, W, T;
	static long[][][] mem;
	
	public static int dist (int p1, int p2) {
		int t = p1 ^ p2;
		if (t == 0)
			return 0;
		if (t == 3)
			return 4;
		return 2;
	}
	//0 sw, 1 se, 2 nw, 3 ne
	public static void dfs (int r, int c, int p, long t) {
//		System.out.println(r + " " + c + " " + p + " " + t);
		if (t >= mem[r][c][p])
			return;
		
		mem[r][c][p] = t;
		
		if (r == 0 && c == M)
			return;
		
		if (r > 0) {
			if (c > 0) {
				//nw
				long t2 = t + dist(p, 2);
				long ct = t2 % (S[r-1][c-1]+W[r-1][c-1]);
				if (ct < T[r-1][c-1]) {
					if (ct < T[r-1][c-1]-W[r-1][c-1]) {
						dfs(r-1, c, 0, t2+1);
						dfs(r, c-1, 3, t2+1+T[r-1][c-1]-W[r-1][c-1]-ct);
					}
					else {
						dfs(r-1, c, 0, t2+1+T[r-1][c-1]-ct);
						dfs(r, c-1, 3, t2+1);
					}
				}
				else {
					if (ct < T[r-1][c-1]+S[r-1][c-1]) {
						dfs(r-1, c, 0, t2+1);
						dfs(r, c-1, 3, t2+1+T[r-1][c-1]+S[r-1][c-1]-ct);
					}
					else {
						dfs(r-1, c, 0, t2+1+T[r-1][c-1]+S[r-1][c-1]+W[r-1][c-1]-ct);
						dfs(r, c-1, 3, t2+1);
					}
				}
			}
			if (c < M) {
				//ne
				long t2 = t + dist(p, 3);
				long ct = t2 % (S[r-1][c]+W[r-1][c]);
				if (ct < T[r-1][c]) {
					if (ct < T[r-1][c]-W[r-1][c]) {
						dfs(r-1, c, 1, t2+1);
						dfs(r, c+1, 2, t2+1+T[r-1][c]-W[r-1][c]-ct);
					}
					else {
						dfs(r-1, c, 1, t2+1+T[r-1][c]-ct);
						dfs(r, c+1, 2, t2+1);
					}
				}
				else {
					if (ct < T[r-1][c]+S[r-1][c]) {
						dfs(r-1, c, 1, t2+1);
						dfs(r, c+1, 2, t2+1+T[r-1][c]+S[r-1][c]-ct);
					}
					else {
						dfs(r-1, c, 1, t2+1+T[r-1][c]+S[r-1][c]+W[r-1][c]-ct);
						dfs(r, c+1, 2, t2+1);
					}
				}
			}
		}
		if (r < N) {
			if (c > 0) {
				//sw
				long t2 = t + dist(p, 0);
				long ct = t2 % (S[r][c-1]+W[r][c-1]);
				if (ct < T[r][c-1]) {
					if (ct < T[r][c-1]-W[r][c-1]) {
						dfs(r+1, c, 2, t2+1);
						dfs(r, c-1, 1, t2+1+T[r][c-1]-W[r][c-1]-ct);
					}
					else {
						dfs(r+1, c, 2, t2+1+T[r][c-1]-ct);
						dfs(r, c-1, 1, t2+1);
					}
				}
				else {
					if (ct < T[r][c-1]+S[r][c-1]) {
						dfs(r+1, c, 2, t2+1);
						dfs(r, c-1, 1, t2+1+T[r][c-1]+S[r][c-1]-ct);
					}
					else {
						dfs(r+1, c, 2, t2+1+T[r][c-1]+S[r][c-1]+W[r][c-1]-ct);
						dfs(r, c-1, 1, t2+1);
					}
				}
			}
			if (c < M) {
				//se
				long t2 = t + dist(p, 1);
				long ct = t2 % (S[r][c]+W[r][c]);
				if (ct < T[r][c]) {
					if (ct < T[r][c]-W[r][c]) {
						dfs(r+1, c, 3, t2+1);
						dfs(r, c+1, 0, t2+1+T[r][c]-W[r][c]-ct);
					}
					else {
						dfs(r+1, c, 3, t2+1+T[r][c]-ct);
						dfs(r, c+1, 0, t2+1);
					}
				}
				else {
					if (ct < T[r][c]+S[r][c]) {
						dfs(r+1, c, 3, t2+1);
						dfs(r, c+1, 0, t2+1+T[r][c]+S[r][c]-ct);
					}
					else {
						dfs(r+1, c, 3, t2+1+T[r][c]+S[r][c]+W[r][c]-ct);
						dfs(r, c+1, 0, t2+1);
					}
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("B-small.in"));
		PrintStream ps = new PrintStream(new FileOutputStream("B-small.out"));
		
		int cases = Integer.parseInt(br.readLine());
		
		for (int itr = 1; itr <= cases; itr++) {
			String[] sp = br.readLine().split(" ");
			N = Integer.parseInt(sp[0]);
			M = Integer.parseInt(sp[1]);
			
			S = new int [N][M];
			W = new int [N][M];
			T = new int [N][M];
			
			for (int i = 0; i < N; i++) {
				sp = br.readLine().split(" ");
				for (int j = 0; j < M; j++) {
					S[i][j] = Integer.parseInt(sp[3*j]);
					W[i][j] = Integer.parseInt(sp[3*j+1]);
					T[i][j] = Integer.parseInt(sp[3*j+2]) % (S[i][j]+W[i][j]);
				}
			}
			
			mem = new long [N+2][M+2][4];
			for (int i = 0; i < mem.length; i++)
				for (int j = 0; j < mem[i].length; j++)
					Arrays.fill(mem[i][j], 1L<<60);
			
			dfs(N, 0, 3, 0);
			long out = mem[0][M][0];
			ps.println("Case #" + itr + ": " + out);
			System.out.println("Case #" + itr + ": " + out);
		}
		
		br.close();
		ps.close();
	}

}
