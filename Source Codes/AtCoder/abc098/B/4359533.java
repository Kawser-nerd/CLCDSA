import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		String s = sc.next();
		long max = 0;
		for (int i = 1; i < n - 1; i++) {
			Set<Character> x = new HashSet<>();
			Set<Character> y = new HashSet<>();
			for (int j = 0; j < i; j++) {
				x.add(s.charAt(j));
			}
			for (int j = i; j < n; j++) {
				y.add(s.charAt(j));
			}
			long count = x.stream().filter(c -> !y.add(c)).count();
			if (count > max) {
				max = count;
			}
		}

		System.out.println(max);

		sc.close();
	}
}