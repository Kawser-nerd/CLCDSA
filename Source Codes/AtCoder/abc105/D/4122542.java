import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		HashMap<Integer, Integer> map = new HashMap<>();
		map.put(0, 1);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += sc.nextInt();
			sum %= m;
			Integer x = map.get(sum);
			if (x == null) {
				x = 0;
			}
			map.put(sum, x + 1);
		}
		long count = 0;
		for (int x : map.values()) {
			count += (long)x * (long)(x - 1) / (long)2;
		}
		System.out.println(count);
	}
}