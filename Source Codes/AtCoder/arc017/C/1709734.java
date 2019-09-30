import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
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
		int n = sc.nextInt();
		int x = sc.nextInt();
		int[] w = new int[n];
		for (int i = 0; i < n; ++i) {
			w[i] = sc.nextInt();
		}

		HashMap<Long, Integer> count1 = new HashMap<>();
		for (int s = 0; s < 1 << (n / 2); ++s) {
			long sum = 0;
			for (int i = 0; i < (n / 2); ++i) {
				if ((s & (1 << i)) > 0) {
					sum += w[i];
				}
			}
			if (count1.containsKey(sum)) {
				count1.put(sum, count1.get(sum) + 1);
			} else {
				count1.put(sum, 1);
			}
		}

		HashMap<Long, Integer> count2 = new HashMap<>();
		for (int s = 0; s < 1 << (n - (n / 2)); ++s) {
			long sum = 0;
			for (int i = 0; i < (n - (n / 2)); ++i) {
				if ((s & (1 << i)) > 0) {
					sum += w[i + n / 2];
				}
			}
			if (count2.containsKey(sum)) {
				count2.put(sum, count2.get(sum) + 1);
			} else {
				count2.put(sum, 1);
			}
		}

		long ans = 0;
		for (Map.Entry<Long, Integer> e : count1.entrySet()) {
			if (count2.containsKey(x - e.getKey())) {
				ans += e.getValue() * count2.get(x - e.getKey());
			}
		}
		System.out.println(ans);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}