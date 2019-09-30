import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			if (map.containsKey(a)) {
				map.get(a).add(b);
			} else {
				List<Integer> list = new ArrayList<Integer>();
				list.add(b);
				map.put(a, list);
			}
			if (map.containsKey(b)) {
				map.get(b).add(a);
			} else {
				List<Integer> list = new ArrayList<Integer>();
				list.add(a);
				map.put(b, list);
			}
		}
		sc.close();

		int ans = 0;
		for (int a : map.keySet()) {
			for (int b : map.get(a)) {
				if (a < b) {
					boolean[] flg = new boolean[n + 1];
					dfs(flg, 1, map, a, b);
					for (int i = 1; i < n + 1; i++) {
						if (!flg[i]) {
							ans++;
							break;
						}
					}
				}
			}
		}
		System.out.println(ans);
	}

	static void dfs(boolean[] flg, int num, Map<Integer, List<Integer>> map, int ngA, int ngB) {
		if (flg[num]) {
			return;
		}
		flg[num] = true;
		List<Integer> list = map.get(num);
		if (list == null) {
			return;
		}
		for (int b : list) {
			if (num == ngA && b == ngB || num == ngB && b == ngA) {
				continue;
			}
			dfs(flg, b, map, ngA, ngB);
		}
	}
}