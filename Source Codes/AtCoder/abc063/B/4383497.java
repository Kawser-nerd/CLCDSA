import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String s = sc.next();
		Set<String> set = new HashSet<>();
		for (int i = 0; i < s.length(); i++) {
			if (!set.contains(s.charAt(i) + "")) {
				set.add(s.charAt(i) + "");
			} else {
				System.out.println("no");
				return;
			}
		}
		System.out.println("yes");
	}
}