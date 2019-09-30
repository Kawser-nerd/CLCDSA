import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = sc.next();
		String c = sc.next();

		String result = "NO";

		if (a.charAt(a.length() - 1) == b.charAt(0)) {
			if (b.charAt(b.length() - 1) == c.charAt(0)) {
				result = "YES";
			}
		}

		System.out.println(result);

		sc.close();


	}
}