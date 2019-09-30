import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.util.Arrays.fill;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Answer {
		final int conq, threat;

		Answer(int conq, int threat) {
			this.conq = conq;
			this.threat = threat;
		}
	}
	
	static Answer getAnswer(int n, boolean conn[][]) {
		if (conn[0][1]) {
			int ans = 0;
			for (int i = 1; i < n; i++) {
				if (conn[0][i]) {
					++ans;
				}
			}
			return new Answer(0, ans);
		}
		int dist0[] = bfs(n, 0, conn);
//		int dist1[] = bfs(n, 1, conn);
		int dist = dist0[1];
		int dyn[][] = new int[n][n];
		for (int dd[]: dyn) {
			fill(dd, Integer.MIN_VALUE);
		}
		for (int i = 0; i < n; i++) {
			if (!conn[0][i]) {
				continue;
			}
			int ans = 0;
			for (int j = 0; j < n; j++) {
				if (conn[0][j] || conn[i][j]) {
					++ans;
				}
			}
			dyn[i][0] = ans;
		}
		for (int cdist = 1; cdist < dist - 1; ++cdist) {
			for (int i = 0; i < n; i++) {
				if (dist0[i] != cdist - 1) {
					continue;
				}
				for (int j = 0; j < n; j++) {
					if (dist0[j] != cdist || !conn[i][j]) {
						continue;
					}
					for (int k = 0; k < n; k++) {
						if (dist0[k] != cdist + 1 || !conn[j][k]) {
							continue;
						}
						int ans = dyn[j][i];
						for (int c = 0; c < n; c++) {
							if (conn[k][c] && !conn[i][c] && !conn[j][c]) {
								++ans;
							}
						}
						dyn[k][j] = max(dyn[k][j], ans);
					}
				}
			}
		}
		int ans = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			if (!conn[1][i]) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (dist0[j] != dist - 2 || !conn[i][j]) {
					continue;
				}
				ans = max(ans, dyn[i][j]);
			}
		}
		return new Answer(dist - 1, ans - dist);		
	}
	
	static void solveTest() throws Exception {
		int n = nextInt();
		int m = nextInt();
		boolean conn[][] = new boolean[n][n];
		for (int i = 0; i < m; i++) {
			int x = nextInt();
			int y = nextInt();
			conn[x][y] = true;
			conn[y][x] = true;
		}
		Answer ans = getAnswer(n, conn);
		out.println(ans.conq + " " + ans.threat);
	}
	
	static int[] bfs(int n, int start, boolean conn[][]) {
		int dist[] = new int[n];
		fill(dist, Integer.MAX_VALUE);
		dist[start] = 0;
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(start);
		do {
			int cur = q.remove();
			for (int i = 0; i < n; i++) {
				if (conn[cur][i] && dist[i] == Integer.MAX_VALUE) {
					dist[i] = dist[cur] + 1;
					q.add(i);
				}
			}
		} while (!q.isEmpty());
		return dist;
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
		}
	}

	public static void main(String[] args) throws Exception {
		System.out.print("Enter filename: ");
		System.out.flush();
		String filename = new BufferedReader(new InputStreamReader(System.in)).readLine();
		in = new BufferedReader(new InputStreamReader(
			new FileInputStream(new File(filename + ".in"))));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
			new FileOutputStream(new File(filename + ".out")))));
		solve();
		in.close();
		out.close();
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine(), " ,");
		}
		return tok.nextToken();
	}
	
	static char nextChar() throws IOException {
		String token = next();
		if (token.length() != 1) {
			throw new IllegalArgumentException("String \"" + token + "\" is not a single character");
		}
		return token.charAt(0);
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}
	
	static long nextLong() throws IOException {
		return parseLong(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}