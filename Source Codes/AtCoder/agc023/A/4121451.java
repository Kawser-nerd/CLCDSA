import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long sum = 0;
		HashMap<Long, Integer> map = new HashMap<>();
		map.put(0L, 1);
		for (int i = 0; i < n ; i++) {
			sum += sc.nextLong();
			Integer x = map.get(sum);
			if (x == null) {
				x = 0;
			}
			map.put(sum, x+ 1);
		}
		long count = 0;
		for (int x : map.values()) {
			if (x >= 2) {
				count += (long)x * (long)(x - 1) / (long)2;
			}
		}
		System.out.print(count);
	}
			
}