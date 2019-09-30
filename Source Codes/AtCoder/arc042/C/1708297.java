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
		int p = sc.nextInt();
		int[][] a = new int[n][2];
		for (int i = 0; i < n; ++i) {
			a[i][0] = sc.nextInt();
			a[i][1] = sc.nextInt();
		}

		Arrays.sort(a, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return -Integer.compare(o1[0], o2[0]);
			}
		});

		int ans = 0;
		int[] f = new int[p + 101];
		for (int i = 0; i < n; ++i) {
			for (int j = p; j >= 0; --j) {
				f[j + a[i][0]] = Math.max(f[j + a[i][0]], f[j] + a[i][1]);
				ans = Math.max(ans, f[j + a[i][0]]);
			}
		}
		System.out.println(ans);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}