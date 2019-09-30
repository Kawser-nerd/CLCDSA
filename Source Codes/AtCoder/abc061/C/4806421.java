import java.util.Scanner;
import java.util.TreeMap;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		TreeMap<Integer, Long> map = new TreeMap<Integer, Long>();
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			long b = sc.nextLong();
			if (map.containsKey(a)) {
				map.put(a, map.get(a) + b);
			} else {
				map.put(a, b);
			}
		}
		sc.close();

		long sum = 0L;
		for (int key : map.keySet()) {
			sum += map.get(key);
			if (sum >= k) {
				System.out.println(key);
				return;
			}
		}
	}
}