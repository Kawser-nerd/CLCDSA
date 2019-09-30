import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}

	final long MOD = 1_000_000_000 + 7;

	public void run() {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		long ans = 1;
		ArrayList<Integer> factor = new ArrayList<>();
		for (int i = b + 1; i <= a; ++i) {
			int v = i;
			for (int j = 2; j * j <= v; ++j) {
				int c = 0;
				while (v % j == 0) {
					v /= j;
					++c;
				}
				if (c > 0) {
					factor.add(j);
				}
			}
			if (v > 1) {
				factor.add(v);
			}
		}

		Collections.sort(factor);
		for (int i = 0; i < factor.size(); ++i) {
			int j = i;
			while (j + 1 < factor.size() && factor.get(i) == factor.get(j + 1))
				++j;
			int c = 0;
			int v = factor.get(i);
			for (int k = b + 1; k <= a; ++k) {
				int u = k;
				while (u % v == 0) {
					u /= v;
					++c;
				}
			}
			ans = ans * (c + 1) % MOD;

			i = j;
		}

		System.out.println(ans);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}