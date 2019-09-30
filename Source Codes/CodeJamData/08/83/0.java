import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;


public class TaskC {

	public static void main(String[] args) throws IOException {
		new TaskC().run();
	}

	BufferedReader br;
	PrintWriter pw;

	private void run() throws IOException {
		Locale.setDefault(Locale.US);
		br = new BufferedReader(new FileReader("c.in"));
		pw = new PrintWriter("c.out");

		sons = new int[600][600];
		sonc = new int[600];
		pre = new int[600];
		col = new int[600];

		int tests = Integer.parseInt(br.readLine().trim());
		for (int test = 1; test <= tests; test++) {
			pw.print("Case #" + test + ": ");
			runtest();
		}

		br.close();
		pw.close();
	}

	long modulo = 1000000009;
	int[][] sons;
	int[] sonc;
	int[] pre;
	int[] col;

	private void runtest() throws IOException {

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		long k = Long.parseLong(st.nextToken());

		Arrays.fill(sonc, 0);

		for (int i = 1; i <= n - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			sons[a][sonc[a]] = b;
			sonc[a]++;
			sons[b][sonc[b]] = a;
			sonc[b]++;
		}

		Arrays.fill(pre, -1);
		Arrays.fill(col, 0);

		pw.println(go(0, k, k));

	}

	private long go(int v, long k, long p) {
		int cs = 0;
		col[v] = 1;
		for (int i = 0; i < sonc[v]; i++) {
			if (col[sons[v][i]] == 0) {
				cs++;
			}
		}

		if (p < cs) {
			return 0;
		}
		long r = cnk(p, cs);

		for (int i = 0; i < sonc[v]; i++) {
			int u = sons[v][i];
			if (col[u] == 1) {
				continue;
			}

			long remain = k - cs;
			if (pre[v] != -1) {
				remain--;
			}

			pre[u] = v;
			r = (r * go(u, k, remain)) % modulo;
		}

		return r;
	}

	private long cnk(long a, int b) {
		long res = 1;
		for (long x = a - b + 1; x <= a; x++) {
			res = (res * x) % modulo;
		}
		return res;
	}

}
