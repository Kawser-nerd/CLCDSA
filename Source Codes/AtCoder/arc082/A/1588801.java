import java.util.*;

// ARC 82-C
// https://beta.atcoder.jp/contests/arc082/tasks/arc082_a

public class Main {

	public static void main (String[] args) {
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();

		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		
		for (int i = 0; i < N; i++) {
			int n = in.nextInt();
			
			if (map.containsKey(n - 1)) {
				int count = map.get(n - 1);
				map.put(n - 1, count + 1);
			} else {
				map.put(n - 1, 1);
			}
			if (map.containsKey(n)) {
				int count = map.get(n);
				map.put(n, count + 1);
			} else {
				map.put(n, 1);
			}
			if (map.containsKey(n + 1)) {
				int count = map.get(n + 1);
				map.put(n + 1, count + 1);
			} else {
				map.put(n + 1, 1);
			}
		}
		
		int answer = 0;
		
		for (int k : map.keySet()) {
			answer = Math.max(answer, map.get(k));
		}
		
		System.out.println(answer);
	}
}