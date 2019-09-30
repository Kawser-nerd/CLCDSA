import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();

		if (s.charAt(1) != s.charAt(2)) {
			System.out.println("No");
		} else if (s.charAt(0) == s.charAt(1) || s.charAt(2) == s.charAt(3)) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}

		sc.close();
	}

}