import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		HashSet<Integer> set = new HashSet<>();
		set.add(sc.nextInt());
		set.add(sc.nextInt());
		int k = sc.nextInt();
		for (int i = 0; i < k; i++) {
			int p = sc.nextInt();
			if (set.contains(p)) {
				System.out.println("NO");
				return;
			} else {
				set.add(p);
			}
		}
		System.out.println("YES");
	}
}