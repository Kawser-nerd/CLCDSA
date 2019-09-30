import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		HashSet<Integer> set = new HashSet<>();
		int count = 0;
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			if (set.contains(a)) {
				count++;
			} else {
				set.add(a);
			}
		}
		System.out.println(count);
	}
}