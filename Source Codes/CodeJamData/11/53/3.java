import java.io.*;
import java.util.*;

public class C {
	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	static final int MOD = 1000003;

	private void solve() {
		int hei = in.nextInt();
		int wid = in.nextInt();
		int[][] di = new int[hei][wid];
		int[][] dj = new int[hei][wid];
		int[][] nn = new int[hei][wid];
		int n = 0;
		for (int i = 0; i < hei; i++) {
			String s = in.next();
			for (int j = 0; j < wid; j++) {
				nn[i][j] = n++;
				switch (s.charAt(j)) {
				case '|':
					di[i][j] = 1;
					dj[i][j] = 0;
					break;
				case '-':
					di[i][j] = 0;
					dj[i][j] = 1;
					break;
				case '/':
					di[i][j] = -1;
					dj[i][j] = 1;
					break;
				case '\\':
					di[i][j] = 1;
					dj[i][j] = 1;
					break;
				default:
					throw new RuntimeException();
				}
			}
		}
		ArrayList<Integer>[] from = new ArrayList[n];
		ArrayList<Integer>[] to = new ArrayList[n];
		int[] f = new int[n];
		int[] t = new int[n];
		Arrays.fill(f, -1);
		Arrays.fill(t, -1);
		for (int i = 0; i < n; i++) {
			from[i] = new ArrayList<Integer>();
			to[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < hei; i++) {
			for (int j = 0; j < wid; j++) {
				for (int d = -1; d <= 1; d += 2) {
					int a = nn[i][j];
					int ii = (i + d * di[i][j] + hei) % hei;
					int jj = (j + d * dj[i][j] + wid) % wid;
					int b = nn[ii][jj];
					from[a].add(b);
					to[b].add(a);
				}
			}
		}
		for (;;) {
			boolean change = false;
			for (int b = 0; b < n; b++) {
				if (t[b] == -1 && to[b].size() == 0) {
					out.println(0);
					return;
				}
				if (t[b] == -1 && to[b].size() == 1) {
					int a = to[b].get(0);
					if (f[a] != -1) {
						out.println(0);
						return;
					}
//					System.out.println(b);
					change = true;
					f[a] = b;
					t[b] = a;
					to[b] = null;
					for (int c : from[a]) {
						if (to[c] != null) {
							to[c].remove((Integer) a);
						}
					}
					from[a] = null;
				}
			}
			if (change) {
				continue;
			}
			break;
		}
		int ans = 1;
		for (;;) {
			int a = 0;
			while (a < n && f[a] != -1) {
				a++;
			}
			if (a == n) {
				break;
			}
			ans *= 2;
			ans %= MOD;
			int b = a;
			int c = from[a].get(0);
			for (;;) {
				f[b] = n;
				b = to[c].get(0) ^ to[c].get(1) ^ b;
				c = from[b].get(0) ^ from[b].get(1) ^ c;
				if (b == a) {
					break;
				}
			}
		}
		out.println(ans);
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new C().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
