import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();
		long[] ruiseki = new long[n + 1];
		ruiseki[0] = 0;
		Map<Long, Long> map = new HashMap<>();
		map.put(0l, 1l);
		for (int i = 1; i <= n; i++) {
			ruiseki[i] = ruiseki[i - 1] + a[i - 1];
			map.put(ruiseki[i], map.containsKey(ruiseki[i]) ? map.get(ruiseki[i]) + 1 : 1);
		}
		long ans = 0;
		for (long val : map.values()) {
			if (val > 1) {
				ans += val * (val - 1) / 2;
			}
		}
		System.out.println(ans);
	}
}