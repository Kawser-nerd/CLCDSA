import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		String s = sc.next(), t = sc.next();
		String ans = s + t;
		for (int i = 0; i <= n; i++) {
			String concat = s.substring(0, i) + t;
			if (concat.substring(0, n).equals(s)) {
				if (ans.length() > concat.length()) {
					ans = concat;
				}
			}
		}
		System.out.println(ans.length());
	}
}