import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;


public class TaskD {

	public static void main(String[] args) throws IOException {
		new TaskD().run();
	}

	BufferedReader br;
	PrintWriter pw;

	private void run() throws IOException {
		Locale.setDefault(Locale.US);
		br = new BufferedReader(new FileReader("d.in"));
		pw = new PrintWriter("d.out");

		int tests = Integer.parseInt(br.readLine().trim());
		for (int test = 1; test <= tests; test++) {
			pw.print("Case #" + test + ": ");
			runtest();
			System.out.println(test);
		}

		br.close();
		pw.close();
	}

	int modulo = 30031;

	private void runtest() throws IOException {

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());
		if (p > n) {
			p = n;
		}

		int count = fact(p) / fact(k) / fact(p - k);
		int[][] b = new int[count][count];
		int[] mask = new int[count];
		int cur = 0;
		for (int m = 0; m < 1 << p; m++) {
			int c = 0;
			for (int i = 0; i < p; i++) {
				if (((m >> i) & 1) == 1) {
					c++;
				}
			}
			if (c == k) {
				mask[cur++] = m;
			}
		}

		if (cur != count) {
			System.exit(1);
		}

		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				b[i][j] = check(mask[i], mask[j], p);
			}
		}


		n -= k;
		int[][] res = new int[count][count];
		for (int i = 0; i < count; i++) {
			res[i][i] = 1;
		}

		while (n > 0) {
			if (n % 2 == 1) {
				res = mul(res, b, count);
			}
			b = mul(b, b, count);
			n = n / 2;
		}

		for (int s = 0; s < count; s++) {
			if (mask[s] == ((1 << k) - 1)) {
				for (int e = 0; e < count; e++) {
					if (mask[e] == ((1 << k) - 1)) {
						pw.println(res[s][e]);
						return;
					}
				}
			}
		}
	}

	private int[][] mul(int[][] a, int[][] b, int n) {
		int[][] r = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					r[i][j] = (r[i][j] + a[i][k] * b[k][j]) % modulo;
				}
			}
		}
		return r;
	}

	private int check(int m1, int m2, int p) {
		if ((m2 & 1) == 0 || (m1 & 1) == 0) {
			return 0;
		}

		if ((m1 & 1) == 0 && m1 * 2 == m2) {
			return 1;
		}

		for (int i = 0; i < 10; i++) {
			if (((m1 >> i) & 1) != 0) {
				for (int j = 1; j <= p; j++) {
					if (i + j <= p) {
						int mask = m1 | (1 << (i + j));
						mask = mask & ~(1 << i);
						mask = mask >> 1;
						if (mask == m2) {
							return 1;
						}
					}
				}
			}
		}

		return 0;
	}

	private int fact(int p) {
		int res = 1;
		for (int i = 2; i <= p; i++) {
			res *= i;
		}
		return res;
	}

}
