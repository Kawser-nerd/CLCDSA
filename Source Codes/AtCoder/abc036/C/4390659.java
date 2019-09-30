import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		TreeMap<Integer, Integer> map = new TreeMap<>();
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
			map.put(arr[i], null);
		}
		Set<Integer> set = map.keySet();
		int idx = 0;
		for (Integer x : set) {
			map.put(x, idx);
			idx++;
		}
		StringBuilder sb = new StringBuilder();
		for (int x : arr) {
			sb.append(map.get(x)).append("\n");
		}
		System.out.print(sb);
	}
}