import java.io.*;
import java.util.*;

/**
 * @author Mikhail Dvorkin
 */
public class D implements Runnable {
	private Scanner in;
	private PrintWriter out;

	private void solve(int testCase) {
		int k = in.nextInt();
		String s = in.next();
		int n = s.length();
		int p = n / k;
		int[][] e = new int[k][k];
		int[][] d = new int[k][k];
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (i == j)
					continue;
				for (int t = 0; t < p; t++) {
					if (s.charAt(t * k + i) == s.charAt(t * k + j)) {
						e[i][j]++;
					}
				}
				for (int t = 0; t < p - 1; t++) {
					if (s.charAt(t * k + i) == s.charAt((t + 1) * k + j)) {
						d[i][j]++;
					}
				}
			}
		}
		int inf = 1000000;
		int[][] a = new int[1 << k][k];
		int ans = 0;
		for (int init = 0; init < k; init++) {
			for (int mask = 0; mask < (1 << k); mask++) {
				Arrays.fill(a[mask], -inf);
			}
			a[1 << init][init] = 0;
			for (int mask = 0; mask < (1 << k); mask++) {
				for (int i = 0; i < k; i++) {
					if (a[mask][i] < 0)
						continue;
					for (int j = 0; j < k; j++) {
						int mm = mask | (1 << j);
						if (mm == mask)
							continue;
						a[mm][j] = Math.max(a[mm][j], a[mask][i] + e[i][j]);
					}
				}
			}
			for (int i = 0; i < k; i++) {
				ans = Math.max(ans, a[(1 << k) - 1][i] + d[i][init]);
			}
		}
		out.println("Case #" + testCase + ": " + (n - ans));
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Thread(new D()).start();
	}

	public void run() {
		try {
			in = new Scanner(new FileReader("d.in"));
			out = new PrintWriter("d.out");
			int n = in.nextInt();
			for (int i = 1; i <= n; i++)
				solve(i);
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
