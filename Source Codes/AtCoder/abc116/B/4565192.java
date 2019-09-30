import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int s = sc.nextInt();
		Set<Integer> set = new HashSet<>();
		for (int i = 0; ; i++) {
			if (set.contains(s)) {
				System.out.println(i + 1);
				return;
			} else {
				set.add(s);
			}
			s = s % 2 == 0 ? s / 2 : s * 3 + 1;
		}
	}
}