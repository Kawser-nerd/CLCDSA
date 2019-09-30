import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int res = 0;
		Integer[] a = new Integer[n];
		Map<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			map.put(a[i], map.getOrDefault(a[i], 0) + 1);
		}
		Arrays.sort(a, (x, y) -> y - x);
		for (int key : a) {
			int countKey = map.getOrDefault(key, 0);
			if (countKey > 0) {
				map.put(key, countKey - 1);
				int diff = Integer.highestOneBit(key) * 2 - key;
				int countDiff = map.getOrDefault(diff, 0);
				if (countDiff > 0) {
					map.put(diff, countDiff - 1);
					res++;
				}
				else map.put(key, countKey);
			}
		}
		System.out.println(res);
	}
}