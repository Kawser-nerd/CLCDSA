import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		TreeMap<Integer, Set<Integer>> map = new TreeMap<Integer, Set<Integer>>();
		for (int i = 2; i <= n; i++) {
			int b = sc.nextInt();
			Set<Integer> set = map.get(b);
			if (set == null) {
				set = new HashSet<Integer>();
				map.put(b, set);
			}
			set.add(i);
		}
		sc.close();

		long[] ans = new long[n + 1];
		System.out.println(getVal(1, ans, map));
	}

	static long getVal(int i, long[] ans, TreeMap<Integer, Set<Integer>> map) {
		if (ans[i] != 0) {
			return ans[i];
		}

		Set<Integer> set = map.get(i);
		if (set == null) {
			ans[i] = 1;
			return ans[i];
		}

		long min = Long.MAX_VALUE;
		long max = Long.MIN_VALUE;
		for (int j : set) {
			long val = getVal(j, ans, map);
			min = Math.min(min, val);
			max = Math.max(max, val);
		}
		ans[i] = min + max + 1;
		return ans[i];
	}
}