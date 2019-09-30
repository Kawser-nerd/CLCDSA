import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		HashSet<Integer> set = new HashSet<>();
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			while (a % 2 == 0) {
				a /= 2;
			}
			set.add(a);
		}
		System.out.println(set.size());
	}
}