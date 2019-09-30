import java.util.*;

public class Main {
	static final long MOD = 1000000007L;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		HashMap<Integer, Integer> map = new HashMap<>();
		for (int i = b + 1; i <= a; i++) {
			int x = i;
			for (int j = 2; j <= Math.sqrt(i); j++) {
				while (x % j == 0) {
					if (map.containsKey(j)) {
						map.put(j, map.get(j) + 1);
					} else {
						map.put(j, 1);
					}
					x /= j;
				}
			}
			if (x != 1) {
				if (map.containsKey(x)) {
					map.put(x, map.get(x) + 1);
				} else {
					map.put(x, 1);
				}
			}
		}
		long ans = 1;
		for (int x : map.values()) {
			ans = (ans * (long)(x + 1)) % MOD;
		}
		System.out.println(ans);
	}
}