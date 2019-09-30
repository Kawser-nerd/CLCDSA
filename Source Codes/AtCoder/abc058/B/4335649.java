import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String a = sc.next(), b = sc.next();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < a.length(); i++) {
			sb.append(a.charAt(i));
			if (b.length() > i) {
				sb.append(b.charAt(i));
			}
		}
		System.out.println(sb);
	}
}