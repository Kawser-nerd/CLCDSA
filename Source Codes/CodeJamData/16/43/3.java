import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class C {
	static final String NO = "IMPOSSIBLE";
	
	int hei, wid;
	int[] a;
	
	String solve() {
		int p = 2 * (hei + wid);
		int[] bx = new int[p];
		int[] by = new int[p];
		for (int i = 0; i < wid; i++) {
			bx[i] = 2 * i + 1;
			by[i] = 0;
			bx[hei + wid + i] = 2 * wid - 2 * i - 1;
			by[hei + wid + i] = 2 * hei;
		}
		for (int i = 0; i < hei; i++) {
			bx[wid + i] = 2 * wid;
			by[wid + i] = 2 * i + 1;
			bx[hei + 2 * wid + i] = 0;
			by[hei + 2 * wid + i] = 2 * hei - 2 * i - 1;
		}
		char[][] ans = new char[hei][wid];
		boolean[] connected = new boolean[p];
		int[] pair = new int[p];
		for (int i = 0; i < p; i += 2) {
			a[i]--;
			a[i + 1]--;
			pair[a[i]] = a[i + 1];
			pair[a[i + 1]] = a[i];
		}
		for (int turn = 0; turn < p / 2; turn++) {
			int from = -1, to = -1;
			for (int i = 0; i < p; i++) {
				if (connected[i]) {
					continue;
				}
				int j = i;
				for (;;) {
					j = (j + 1) % p;
					if (connected[j]) {
						continue;
					}
					break;
				}
				if (j == pair[i]) {
					from = i;
					to = j;
					break;
				}
			}
			if (from == -1) {
				return NO;
			}
			connected[from] = connected[to] = true;
			int x = bx[from];
			int y = by[from];
			int dx, dy;
			if (x == 0) {
				dx = 1; dy = -1;
			} else if (y == 0) {
				dx = dy = 1;
			} else if (x == 2 * wid) {
				dx = -1; dy = 1;
			} else {
				dx = dy = -1;
			}
			while (x != bx[to] || y != by[to]) {
				boolean ok = false;
				for (int t = 0; t <= 2; t++) {
					if (x + dx < 0 || x + dx > 2 * wid || y + dy < 0 || y + dy > 2 * hei) {
						int dxNew = -dy;
						int dyNew = dx;
						dx = dxNew;
						dy = dyNew;
						continue;
					}
					int xMin = Math.min(x, x + dx);
					int yMin = Math.min(y, y + dy);
					boolean obstacle = false;
					char drawn;
					if (dx == dy) {
						drawn = '\\';
						if (ans[yMin / 2][xMin / 2] == '/') {
							obstacle = true;
						}
					} else {
						drawn = '/';
						if (ans[yMin / 2][xMin / 2] == '\\') {
							obstacle = true;
						}
					}
					if (!obstacle) {
						ans[yMin / 2][xMin / 2] = drawn;
						ok = true;
						break;
					}
					int dxNew = -dy;
					int dyNew = dx;
					dx = dxNew;
					dy = dyNew;
				}
				if (!ok) {
					return NO;
				}
				x += dx;
				y += dy;
				int dxNew = dy;
				int dyNew = -dx;
				dx = dxNew;
				dy = dyNew;
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < hei; i++) {
			sb.append(new String(ans[i]).replace((char) 0, '/')).append("\n");
		}
		return sb.toString().trim();
	}
	
	public C(Scanner in) {
		hei = in.nextInt();
		wid = in.nextInt();
		a = new int[2 * (hei + wid)];
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
		}
	}
	
	public static void main(String[] args) throws Exception {
		int nThreads = 1;
		/* "Google Code Jam, Facebook Hacker Cup" */
		String fileNameSuffix = "";
		String formatOut = "Case #%2$d:\n%1$s";
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
