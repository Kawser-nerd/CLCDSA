import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int s = sc.nextInt();

		int a = s;
		int i = 2;
		int ans = 0;
		Set<Integer> set = new HashSet<>();
		set.add(a);
		while (true) {
			a = func(a);
			if (!set.add(a)) {
				ans = i;
				break;
			}
			i++;
		}
		System.out.println(ans);
		sc.close();
	}

	public static int func(int n) {
		if (n % 2 == 0) {
			return n / 2;
		}
		return 3 * n + 1;
	}
}