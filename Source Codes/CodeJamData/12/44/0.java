import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Map {
		final long data[];
		
		Map(long data[]) {
			this.data = data;
		}
		
		Map goLeft(Map cave) {
			int n = data.length;
			long newData[] = new long[n];
			for (int i = 0; i < n; i++) {
				long cur = data[i];
				long curCave = cave.data[i];
				newData[i] = (cur >> 1) & curCave | (((cur >> 1) & ~curCave) << 1);
			}
			return new Map(newData);
		}

		Map goRight(Map cave) {
			int n = data.length;
			long newData[] = new long[n];
			for (int i = 0; i < n; i++) {
				long cur = data[i];
				long curCave = cave.data[i];
				newData[i] = (cur << 1) & curCave | (((cur << 1) & ~curCave) >> 1);
			}
			return new Map(newData);
		}
		
		Map goDown(Map cave) {
			int n = data.length;
			long newData[] = new long[n];
			for (int i = 0; i < n; i++) {
				long cur = data[i];
				if (i < n - 1) {
					long nextCave = cave.data[i + 1];
					newData[i + 1] |= cur & nextCave;
					newData[i] |= cur & ~nextCave;
				} else {
					newData[i] |= cur;
				}
			}
			return new Map(newData);
		}
		
		public boolean equals(Object obj) {
			if (!(obj instanceof Map)) {
				return false;
			}
			return Arrays.equals(data, ((Map) obj).data);
		}
		
		public int hashCode() {
			return Arrays.hashCode(data);
		}
	}
	
	static void solve() throws Exception {
		int h = nextInt();
		int w = nextInt();
		boolean passable[][] = new boolean[h][w];
		int caveX[] = new int[10];
		int caveY[] = new int[10];
		fill(caveX, Integer.MIN_VALUE);
		fill(caveY, Integer.MIN_VALUE);
		for (int y = 0; y < h; y++) {
			String l = next();
			for (int x = 0; x < w; x++) {
				char c = l.charAt(x);
				if (c != '#') {
					passable[y][x] = true;
				}
				if (c >= '0' && c <= '9') {
					if (caveX[c - '0'] != Integer.MIN_VALUE) {
						throw new AssertionError();
					}
					caveX[c - '0'] = x;
					caveY[c - '0'] = y;
				}
			}
		}
		Map cave;
		{
			long data[] = new long[h];
			for (int y = 0; y < h; y++) {
				for (int x = 0; x < w; x++) {
					if (passable[y][x]) {
						if (x == 0 || y == 0 || x == w - 1 || y == h - 1) {
							throw new AssertionError();
						}
						data[y] |= 1L << x;
					}
				}
			}
			cave = new Map(data);
		}
		printlnCase();
		i: for (int i = 0; i < 10; i++) {
			if (caveX[i] == Integer.MIN_VALUE) {
				continue;
			}
			out.print(i + ":");
			Map finish;
			{
				long data[] = new long[h];
				data[caveY[i]] = 1L << caveX[i];
				finish = new Map(data);
			}
			Set<Map> states = new HashSet<>();
			Queue<Map> queue = new ArrayDeque<>();
			{
				long data[] = new long[h];
				out.print(" " + dfs(passable, data, caveX[i], caveY[i]));
				Map vis = new Map(data);
				if (vis.equals(finish)) {
					out.println(" Lucky");
					continue i;
				}
				states.add(vis);
				queue.add(vis);
			}
			do {
				Map map = queue.remove();
				Map next = map.goLeft(cave);
				if (next.equals(finish)) {
					out.println(" Lucky");
					continue i;
				}
				if (states.add(next)) {
					queue.add(next);
				}
				next = map.goRight(cave);
				if (next.equals(finish)) {
					out.println(" Lucky");
					continue i;
				}
				if (states.add(next)) {
					queue.add(next);
				}
				next = map.goDown(cave);
				if (next.equals(finish)) {
					out.println(" Lucky");
					continue i;
				}
				if (states.add(next)) {
					queue.add(next);
				}
			} while (!queue.isEmpty());
			out.println(" Unlucky");
		}
	}
	
	static int dfs(boolean passable[][], long data[], int x, int y) {
		if ((data[y] & (1L << x)) != 0) {
			return 0;
		}
		int ans = 1;
		data[y] |= 1L << x;
		if (x > 0 && passable[y][x - 1]) {
			ans += dfs(passable, data, x - 1, y);
		}
		if (x < passable[y].length - 1 && passable[y][x + 1]) {
			ans += dfs(passable, data, x + 1, y);
		}
		if (y > 0 && passable[y - 1][x]) {
			ans += dfs(passable, data, x, y - 1);
		}
		return ans;
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}