import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] c = new int[n];
		Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();
		for (int i = 0; i < n; i++) {
			int ci = sc.nextInt();
			c[i] = ci;
			if (map.containsKey(ci)) {
				map.get(ci).add(i);
			} else {
				List<Integer> list = new ArrayList<Integer>();
				list.add(i);
				map.put(ci, list);
			}
		}
		sc.close();

		Set<Integer> set = new HashSet<Integer>();
		long[] dp = new long[n];
		dp[0] = 1;
		set.add(c[0]);
		for (int i = 1; i < n; i++) {
			int ci = c[i];
			if (ci == c[i - 1]) {
				dp[i] = dp[i - 1];

			} else if (set.contains(ci)) {
				List<Integer> list = map.get(ci);
				int idx = binarySearch(list, i);
				dp[i] = (dp[i - 1] + dp[list.get(idx)]) % 1000000007;

			} else {
				dp[i] = dp[i - 1];
			}
			set.add(ci);
		}
//		for (int i = 0; i < dp.length; i++) {
//			System.out.print(dp[i] + " ");
//		}
//		System.out.println();
		System.out.println(dp[n - 1] % 1000000007);
	}

	public static int binarySearch(List<Integer> list, int val) {
		int start = -1;
		int end = list.size();

		while (Math.abs(end - start) > 1) {
			int mid = (end + start) / 2;
			if (list.get(mid) >= val) {
				end = mid;
			} else {
				start = mid;
			}
		}
		return start;
	}
}