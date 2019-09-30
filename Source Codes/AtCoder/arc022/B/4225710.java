import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		HashSet<Integer> set = new HashSet<>();
		int[] arr = new int[n];
		int max = 0;
		int start = 0;
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			arr[i] = a;
			if (set.contains(a)) {
				while (arr[start] != a) {
					set.remove(arr[start]);
					start++;
				}
				start++;
			} else {
				set.add(a);
				int v = set.size();
				if (max < v) {
					max = v;
				}
			}
		}
		System.out.println(max);
	}
}