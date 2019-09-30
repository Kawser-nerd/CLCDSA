import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class C {
	static final String NO = "IMPOSSIBLE";
	static final String YES = "POSSIBLE";
	static final int[] DX = new int[]{1, 0, -1, 0};
	static final int[] DY = new int[]{0, 1, 0, -1};

	String solve() {
		boolean[][][] forbidden = new boolean[h][w][2];
		TreeSet<Integer>[][][] cells = new TreeSet[h][w][2];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cells[i][j][0] = new TreeSet<>();
				cells[i][j][1] = new TreeSet<>();
			}
		}
		ArrayList<Integer> sat1 = new ArrayList<>();
		ArrayList<Integer> sat2 = new ArrayList<>();
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (f[i][j] != '-') {
					continue;
				}
				for (int dir = 0; dir < 4; dir++) {
					int x = i;
					int y = j;
					int d = dir;
					for (;;) {
						x += DX[d];
						y += DY[d];
						if (x >= h || y >= w || x < 0 || y < 0) {
							break;
						}
						if (f[x][y] == '#') {
							break;
						}
						if (f[x][y] == '/') {
							d ^= 3;
							continue;
						}
						if (f[x][y] == '\\') {
							d ^= 1;
							continue;
						}
						if (f[x][y] == '-') {
							forbidden[i][j][dir % 2] = true;
							break;
						}
						cells[i][j][dir % 2].add(x * w + y);
					}
				}
				if (forbidden[i][j][0] && forbidden[i][j][1]) {
					return NO;
				}
				if (forbidden[i][j][0]) {
					sat1.add((i * w + j) * 2 + 1);
					sat2.add((i * w + j) * 2 + 1);
				} else if (forbidden[i][j][1]) {
					sat1.add((i * w + j) * 2);
					sat2.add((i * w + j) * 2);
				} else {
					sat1.add((i * w + j) * 2);
					sat2.add((i * w + j) * 2 + 1);
				}
				for (int d = 0; d < 2; d++) {
					if (forbidden[i][j][d]) {
						continue;
					}
					for (int z : cells[i][j][d]) {
						int y = z % w;
						int x = z / w;
						cells[x][y][0].add((i * w + j) * 2 + d);
					}
				}
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (f[i][j] != '.') {
					continue;
				}
				TreeSet<Integer> good = cells[i][j][0];
				if (good.isEmpty()) {
					return NO;
				}
				if (good.size() > 2) {
					throw new AssertionError();
				}
				sat1.add(good.first());
				sat2.add(good.last());
			}
		}
		boolean[] ans = TwoSat.solve(sat1, sat2);
		if (ans == null) {
			return NO;
		}
		StringBuilder sb = new StringBuilder();
		sb.append(YES);
		for (int i = 0; i < h; i++) {
			sb.append('\n');
			for (int j = 0; j < w; j++) {
				if (f[i][j] != '-') {
					sb.append(f[i][j]);
					continue;
				}
				sb.append(ans[i * w + j] ? '-' : '|');
			}
		}
		return sb.toString();
	}
	
	static class TwoSat {
		static boolean[] solve(ArrayList<Integer> sat1, ArrayList<Integer> sat2) {
//			System.out.println(sat1);
//			System.out.println(sat2);
			int n = -1;
			for (int x : sat1) {
				n = Math.max(n, x / 2);
			}
			for (int x : sat2) {
				n = Math.max(n, x / 2);
			}
			n++;
			boolean[] ans = new boolean[n];
			ArrayList<Integer>[] g = new ArrayList[2 * n];
			ArrayList<Integer>[] gt = new ArrayList[2 * n];
			for (int i = 0; i < 2 * n; i++) {
				g[i] = new ArrayList<Integer>();
				gt[i] = new ArrayList<Integer>();
			}
			for (int i = 0; i < sat1.size(); i++) {
				int a = sat1.get(i);
				int b = sat2.get(i);
//				if (a == b || a == (b ^ 1)) {
//					continue;
//				}
				g[a ^ 1].add(b);
				g[b ^ 1].add(a);
				gt[a].add(b ^ 1);
				gt[b].add(a ^ 1);
			}
			boolean[] mark = new boolean[2 * n];
			ArrayList<Integer> order = new ArrayList<Integer>();
			for (int i = 0; i < 2 * n; i++) {
				if (mark[i]) {
					continue;
				}
				dfs1(i, mark, order, g);
			}
			int[] comp = new int[2 * n];
			Arrays.fill(comp, -1);
			for (int i = 2 * n - 1, cn = 0; i >= 0; i--) {
				int v = order.get(i);
				if (comp[v] == -1) {
					dfs2(v, cn++, comp, gt);
				}
			}
			for (int i = 0; i < n; i++) {
				if (comp[2 * i] == comp[2 * i + 1]) {
					return null;
				}
				ans[i] = comp[2 * i + 1] > comp[2 * i];
			}
			return ans;
		}
		
		static void dfs1(int v, boolean[] mark, ArrayList<Integer> order, ArrayList<Integer>[] g) {
			mark[v] = true;
			for (int u : g[v]) {
				if (mark[u]) {
					continue;
				}
				dfs1(u, mark, order, g);
			}
			order.add(v);
		}
		
		static void dfs2(int v, int cn, int[] comp, ArrayList<Integer>[] g) {
			comp[v] = cn;
			for (int u : g[v]) {
				if (comp[u] != -1) {
					continue;
				}
				dfs2(u, cn, comp, g);
			}
		}
	}

	int h, w;
	char[][] f;
	
	public C(Scanner in) {
		h = in.nextInt();
		w = in.nextInt();
		f = new char[h][];
		for (int i = 0; i < h; i++) {
			f[i] = in.next().toCharArray();
			for (int j = 0; j < w; j++) {
				if (f[i][j] == '|') {
					f[i][j] = '-';
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		int nThreads = 1;//4;
		/* "Google Code Jam, Facebook Hacker Cup" */
		String fileNameSuffix = "";
		String formatOut = "Case #%2$d: %1$s";
		String formatSystemOut = formatOut;
//		/* "IPSC" */
//		String fileNameSuffix = "0";
//		String formatOut = "%s";
//		String formatSystemOut = "Case #%2$d solved.";//"Case #%2$d: %1$s";
		
		String fileName = C.class.getSimpleName().replaceFirst("_.*", "").toLowerCase() + fileNameSuffix;
		String inputFileName = fileName + ".in";
		String outputFileName = fileName + ".out";
		
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new File(inputFileName));
		PrintWriter out = new PrintWriter(outputFileName);
		int tests = in.nextInt(); in.nextLine();//1;
		nThreads = Math.min(nThreads, tests);
		@SuppressWarnings("unchecked")
		Callable<String>[] callables = new Callable[tests];
		for (int t = 0; t < tests; t++) {
			final C testCase = new C(in);
			final int testCaseNumber = t + 1;
			callables[t] = new Callable<String>() {
				@Override
				public String call() {
					String answer = testCase.solve();
					System.out.println(String.format(formatSystemOut, answer, testCaseNumber));
					return String.format(formatOut, answer, testCaseNumber);
				}
			};
		}
		try {
			if (nThreads > 1) {
				ExecutorService executor = Executors.newFixedThreadPool(4);
				@SuppressWarnings("unchecked")
				Future<String>[] outputs = new Future[tests];
				for (int t = 0; t < tests; t++) {
					outputs[t] = executor.submit(callables[t]);
				}
				for (int t = 0; t < tests; t++) {
					out.println(outputs[t].get());
				}
				executor.shutdown();
			} else {
				for (int t = 0; t < tests; t++) {
					out.println(callables[t].call());
				}
			}
		} catch (Exception e) {
			System.out.flush();
			System.err.flush();
			e.printStackTrace();
			System.exit(1);
		}
		System.out.println("COMPLETE");
		in.close();
		out.close();
	}
}
