import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String s = sc.next();
		if (s.charAt(s.length() - 1) == 'T') {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}