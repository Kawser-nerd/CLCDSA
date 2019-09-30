import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String a = sc.next();
		String b = sc.next();

		System.out.println(judge(a, b));

		sc.close();
	}

	static String judge(String a, String b) {
		if (a.length() == b.length()) {
			int ia = Integer.parseInt("" + a.charAt(0));
			int ib = Integer.parseInt("" + b.charAt(0));
			if (ia == ib) {
				return "EQUAL";
			} else if (ia > ib) {
				return "GREATER";
			} else {
				return "LESS";
			}
		} else if (a.length() > b.length()) {
			return "GREATER";
		} else {
			return "LESS";
		}
	}
}