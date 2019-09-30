import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Set<Integer> set = new HashSet<Integer>();
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			if (set.contains(a)) {
				set.remove(a);
			} else {
				set.add(a);
			}
		}
		sc.close();

		System.out.println(set.size());
	}
}