import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	private void dfs(int r, int c) {
		if (f[r][c] > 0) {
			return;
		}
		f[r][c] = 2;
		for (int k = 0; k < 4; ++k) {
			int nr = r+dx[k];
			int nc = c+dy[k];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
				dfs(nr, nc);
			}
		}
	}
	
	int n, m;
	int[][] f;
	int[] dx = {-1, 0, 1, 0};
	int[] dy = {0, 1, 0, -1};
	public void run() {
		
		int cases = nextInt();
		for (int cs = 0; cs < cases; ++cs) {
			n = nextInt();
			m = nextInt();
			int K = nextInt();
			
			f = new int[n][m];
			int min = Integer.MAX_VALUE;
			for (int i = 0; i < (1 << (n*m)); ++i) {
				if (Integer.bitCount(i) >= min) {
					continue;
				}
				
				for (int j = 0; j < n; ++j) {
					Arrays.fill(f[j], 0);
				}
				for (int j = 0; j < n*m; ++j) {
					if ((i & (1 << j)) != 0) {
						f[j/m][j%m] = 1;
					}
				}
				
				for (int j = 0; j < n; ++j) {
					dfs(j, 0);
					dfs(j, m-1);
				}
				for (int j = 0; j < m; ++j) {
					dfs(0, j);
					dfs(n-1, j);
				}
				
				int cnt = 0;
				for (int j = 0; j < n; ++j) {
					for (int k = 0; k < m; ++k) {
						if (f[j][k] < 2) {
							++cnt;
						}
					}
				}
				
				if (cnt >= K) {
					if (min >= Integer.bitCount(i)) {
						min = Integer.bitCount(i);
					}
				}
			}
			out.println("Case #"+(cs+1)+": "+min);
			System.err.println(cs + ": " + min);
		}
		out.flush();
	}
	
	private static BufferedReader br = null;
	private static StringTokenizer stk = null;
	private static PrintWriter out = null;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("D:\\C.txt")));
		out = new PrintWriter("D:\\CC.txt");
		(new Thread(new C())).start();
	}
	
	public void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public String nextLine() {
		try {
			return (br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	public int nextInt() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}
	
	public long nextLong() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Long.parseLong(stk.nextToken());
	}
	
	public double nextDouble() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}
	
	public String nextWord() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return (stk.nextToken());
	}
}
