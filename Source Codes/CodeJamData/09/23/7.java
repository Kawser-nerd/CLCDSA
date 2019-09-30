import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;

public class Task {
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		
		new Task().run();
		out.close();
	}
	
	static BufferedReader br;
	static PrintWriter out;
	StringTokenizer st;
	static String taskName = "";
	
	String nline() {
		try {
			return br.readLine();
		} catch (Exception exc) {
			return  null;
		}
	}
	
	String ns() {
		try {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(nline());
			}
			return st.nextToken();
		} catch (Exception exc) {
			return null;
		}
	}
	
	int ni() {
		return Integer.valueOf(ns());
	}

	double nd() {
		return Double.valueOf(ns());
	}
	
	void pf(String format, Object ... obj) {
		out.printf(format, obj);
	}
	
	void pln() {
		out.println();
	}
	
	void pt(Object obj) {
		out.print(obj);
	}
	
	char[][] map;
	String[][][] memo;
	final int MAX = 400;
	
	boolean better(String what, String then) {
		if (then == null)
			return true;
		if (what.length() < then.length())
			return true;
		if (what.length() > then.length())
			return false;
		if (what.compareTo(then) < 0)
			return true;
		return false;
	}
	
	int[][] dirs = {
			{0, -1},
			{0, 1},
			{-1, 0},
			{1, 0}
	};
	
	int n;
	
	boolean ok(int r, int c) {
		return r >= 0 && r < n && c >= 0 && c < n;
	}
	
	void run() {
		//Place your code here
		
		int T = ni();
		
		for (int t = 1; t <= T; t++) {
			n = ni();
			int q = ni();
			map = new char[n][];
			for (int i = 0; i < n; i++)
				map[i] = ns().toCharArray();
			
			memo = new String[n][n][2 * MAX];
			
			ArrayDeque<int[]> deque = new ArrayDeque<int[]>();
			
			for (int r = 0; r < n; r++)
				for (int c = 0; c < n; c++)
					if (Character.isDigit(map[r][c])) {
						int x = map[r][c] - '0' + MAX;
						memo[r][c][x] = "" + map[r][c];
						deque.add(new int[] { r, c, x });
					}
			
			String[] best = new String[2 * MAX];
			
			boolean[][][] inQ = new boolean[n][n][2 * MAX];
			
			while (!deque.isEmpty()) {
				int[] arr = deque.remove();
				int r = arr[0];
				int c = arr[1];
				int sum = arr[2];
				inQ[r][c][sum] = false;
				
				if (better(memo[r][c][sum], best[sum]))
					best[sum] = memo[r][c][sum];
				for (int[] d1 : dirs) {
					int sr = r + d1[0];
					int sc = c + d1[1];
					if (ok(sr, sc))
						for (int[] d2: dirs) {
							int nr = sr + d2[0];
							int nc = sc + d2[1];
							if (ok(nr, nc)) {
								int nextSum = sum;
								if (map[sr][sc] == '+')
									nextSum += map[nr][nc] - '0';
								else
									nextSum -= map[nr][nc] - '0';
								if (nextSum >= 0 && nextSum < 2 * MAX) {
									String nextString = memo[r][c][sum] + map[sr][sc] + map[nr][nc];
									if (better(nextString, memo[nr][nc][nextSum])) {
//										System.out.printf("%d %d %d\n", nr, nc, nextSum);
//										System.out.println("from");
//										System.out.println(memo[nr][nc][nextSum]);
//										System.out.println("to");
//										System.out.println(nextString);
										
										memo[nr][nc][nextSum] = nextString;
										
										if (!inQ[nr][nc][nextSum]) {
											inQ[nr][nc][nextSum] = true;
											deque.add(new int[] {nr, nc, nextSum});
										}
									}
								}
							}
						}
				}
				
			}
			out.printf("Case #%d:", t);
			out.println();
			
			for (int i = 0; i < q; i++) {
				int x = ni() + MAX;
				out.println(best[x]);
				out.flush();
			}
			
			System.out.printf("Test %d of %d done.", t, T);
			System.out.println();
			System.out.flush();
			
		}
		
	}
}