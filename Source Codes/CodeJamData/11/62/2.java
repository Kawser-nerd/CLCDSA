import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.arraycopy;
import static java.lang.System.nanoTime;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static long get(long arr[][], int i, int j) {
		if (i < 0 || i >= arr.length || j < 0 || j >= arr[0].length) {
			return 0;
		}
		return arr[i][j];
	}
	
	static class Cell {
		final int i, j;

		Cell(int i, int j) {
			this.i = i;
			this.j = j;
		}
	}
	
	static final int dx[] = {1, 0, -1, 0};
	static final int dy[] = {0, 1, 0, -1};
	
	static void calculateLevel(long map[][], long level[][]) {
		Queue<Cell> queue = new ArrayDeque<Cell>();
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[0].length; j++) {
				level[i][j] = Long.MAX_VALUE;
				queue.add(new Cell(i, j));
			}
		}
		while (!queue.isEmpty()) {
			Cell cur = queue.remove();
			int i = cur.i;
			int j = cur.j;
			long nlevel = Long.MAX_VALUE;
			for (int d = 0; d < 4; d++) {
				nlevel = min(nlevel, get(level, i + dx[d], j + dy[d]));
			}
			nlevel = max(nlevel, map[i][j]);
			if (level[i][j] > nlevel) {
				level[i][j] = nlevel;
				for (int d = 0; d < 4; d++) {
					int ni = i + dx[d];
					int nj = j + dy[d];
					if (ni >= 0 && ni < map.length && nj >= 0 && nj < map[0].length) {
						queue.add(new Cell(ni, nj));
					}
				}
			}
		}
	}
	
	static void erode(long map[][], long level[][], long limit) {
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[0].length; j++) {
				long min = level[i][j];
				for (int d = 0; d < 4; d++) {
					min = min(min, get(level, i + dx[d], j + dy[d]));
				}
				min = level[i][j] - min;
				if (min > 0) {
					min = min(min, limit);
					map[i][j] -= min;
				}
			}
		}
	}
	
	static long days(long map[][], long mapDiff[][], long level[][], long levelDiff[][], long limit) {
		long days = Long.MAX_VALUE;
		int n = map.length;
		int m = map[0].length;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (level[i][j] > map[i][j]) {
					if (mapDiff[i][j] != 0) {
						throw new AssertionError();
					}
					if (levelDiff[i][j] > 0) {
						days = min(days, (level[i][j] - map[i][j]) / levelDiff[i][j]);
						if (days <= 0) {
							throw new AssertionError();
						}
					}
					for (int d = 0; d < 4; d++) {
						int ni = i + dx[d];
						int nj = j + dy[d];
						if (get(levelDiff, ni, nj) != levelDiff[i][j] && get(level, ni, nj) > level[i][j]) {
							long ndays = (get(level, ni, nj) - level[i][j]) / (get(levelDiff, ni, nj) - levelDiff[i][j]);
							if (ndays > 0) {
								days = min(days, ndays);
							}
						}
					}
				} else if (level[i][j] == map[i][j]) {
					if (levelDiff[i][j] != mapDiff[i][j]) {
						throw new AssertionError();
					}
					if (mapDiff[i][j] < limit) {
						for (int d = 0; d < 4; d++) {
							int ni = i + dx[d];
							int nj = j + dy[d];
							if (get(levelDiff, ni, nj) != mapDiff[i][j]) {
								long ndays = (get(level, ni, nj) - map[i][j] + mapDiff[i][j]) / (get(levelDiff, ni, nj) - mapDiff[i][j]) + 1;
								if (ndays > 0) {
									days = min(days, ndays);
								}
							}
						}
					} else if (mapDiff[i][j] == limit) {
						for (int d = 0; d < 4; d++) {
							int ni = i + dx[d];
							int nj = j + dy[d];
							if (get(levelDiff, ni, nj) != limit) {
								long ndays = (map[i][j] - limit - get(level, ni, nj)) / (limit - get(levelDiff, ni, nj)) + 1;
								if (ndays > 0) {
									days = min(days, ndays);
								}
							}
						}
					} else {
						throw new AssertionError();
					}
				} else {
					throw new AssertionError();
				}
			}
		}
		if (days <= 0) {
			throw new AssertionError();
		}
		return days;
	}
	
	static void print(long arr[][]) {
		for (long ar[]: arr) {
			for (long a: ar) {
				System.err.printf("%2d ", a);
			}
			System.err.println();
		}
		System.err.println();
	}

	static void copy(long from[][], long to[][]) {
		for (int i = 0; i < from.length; i++) {
			arraycopy(from[i], 0, to[i], 0, from[0].length);
		}
	}

	static void diff(long from[][], long to[][]) {
		for (int i = 0; i < from.length; i++) {
			for (int j = 0; j < from[0].length; j++) {
				to[i][j] = from[i][j] - to[i][j];
			}
		}
	}
	
	static void subMul(long to[][], long what[][], long mul) {
		for (int i = 0; i < to.length; i++) {
			for (int j = 0; j < to[0].length; j++) {
				to[i][j] -= what[i][j] * mul;
			}
		}
	}

//	static final Random rng = new Random(42);
	
	static void solveTest() throws Exception {
		int n = nextInt();
		int m = nextInt();
		long d = nextLong();
//		int n = 20;
//		int m = 20;
//		long d = 100000000000000L;
		long map[][] = new long[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = nextLong();
//				map[i][j] = abs(rng.nextLong() % 1000000000000000L);
			}
		}
		long level[][] = new long[n][m];
		calculateLevel(map, level);
		long newMap[][] = new long[n][m];
		long newLevel[][] = new long[n][m];
		long day = 0;
		while (true) {
			check: for (int i = 0; ; i++) {
				if (i >= n) {
					out.println(day);
					return;
				}
				for (int j = 0; j < m; j++) {
					if (map[i][j] != 0) {
						break check;
					}
				}
			}
//			System.err.println("Day " + day);
			copy(map, newMap);
			copy(level, newLevel);
			erode(newMap, newLevel, d);
			calculateLevel(newMap, newLevel);
			diff(map, newMap);
			diff(level, newLevel);
//			print(map);
//			print(newMap);
//			print(level);
//			print(newLevel);
			long days = days(map, newMap, level, newLevel, d);
//			System.err.println("Processing " + days + " days");
			subMul(map, newMap, days);
			subMul(level, newLevel, days);
			day += days;
		}
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			long t = nanoTime();
			out.print("Case #" + test + ": ");
			solveTest();
			System.err.println("Solved test " + test + " in " + (nanoTime() - t) * 1e-9 + " seconds");
		}
	}

	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		solve();
		in.close();
		out.close();
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
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