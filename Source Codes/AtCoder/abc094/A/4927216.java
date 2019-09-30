import java.util.Scanner;

public class Main {
	public static void main(String... args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long x = sc.nextLong();

		if (a > x) {
			System.out.println("NO");
		} else if (a + b < x) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
		}
	}
}