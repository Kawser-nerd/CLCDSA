import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		boolean[][] a = new boolean[n][n];
		for (int i = 0; i < n; ++i) {
			String s = sc.next();
			for (int j = 0; j < n; ++j) {
				a[i][n - 1 - j] = s.charAt(j) == 'o';
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j])
					continue;
				if (!a[i][j]) {
					++cnt;
					for (int k = j; k < n; ++k) {
						a[i][k] = true;
					}
					for (int k = 0; i + 1 < n && k <= j; ++k) {
						a[i + 1][k] = true;
					}
				}
			}
		}
		System.out.println(cnt);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}