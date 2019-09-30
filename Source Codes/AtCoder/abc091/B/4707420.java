import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		Map<String, Integer[]> map = new HashMap<String, Integer[]>();
		int N = reader.nextInt();
		for (int i = 0; i < N; i++) {
			String s = reader.next();
			if (map.containsKey(s)) {
				map.get(s)[0]++;
			} else {
				Integer[] arr = new Integer[2];
				arr[0] = 1;
				arr[1] = 0;
				map.put(s, arr);
			}
		}
		int M = reader.nextInt();
		for (int i = 0; i < M; i++) {
			String s = reader.next();
			if (map.containsKey(s)) {
				map.get(s)[1]++;
			} else {
				Integer[] arr = new Integer[2];
				arr[0] = 0;
				arr[1] = 1;
				map.put(s, arr);
			}
		}
		int ans = 0;
		for (Entry<String, Integer[]> entry : map.entrySet()) {
			Integer[] arr = entry.getValue();
			int gap = arr[0] - arr[1];
			ans = Math.max(gap, ans);
		}

		System.out.println(ans);
		reader.close();
	}
}