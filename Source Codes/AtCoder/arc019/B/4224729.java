import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int count = 0;
		for (int i = 0; i < s.length() / 2; i++) {
			if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
				count++;
			}
		}
		int sum = 0;
		if (count == 0) {
			if (s.length() == 1) {
				sum = 0;
			} else if (s.length() % 2 == 1) {
				sum = 25 * (s.length() - 1);
			} else {
				sum = 25 * s.length();
			}
		} else if (count == 1) {
			sum = 25 * s.length() - 2;
		} else {
			sum = 25 * s.length();
		}
		System.out.println(sum);
	}
}