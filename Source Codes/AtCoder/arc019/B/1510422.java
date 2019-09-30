import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		if (s.length() == 1) {
			System.out.println(0);
			return;
		}
		boolean flag = true;
		int total = 0;
		int count = 0;

		for (int i = 0; i < s.length() / 2; i++) {
			if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
				count++;
				flag = false;
			}
		}
		if (flag) {
			if (s.length() % 2 == 1) {
				total = 25 * (s.length() - 1);
			} else {
				total = 25 * s.length();
			}
		} else if (count == 1) {
			total = 25 * s.length() - 2;
		} else {
			total = 25 * s.length();
		}
		System.out.println(total);

	}
}