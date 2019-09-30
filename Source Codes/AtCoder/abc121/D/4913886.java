import java.util.Scanner;

public class Main {
	public static void main(String... args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long x = 0L;

		if (a % 2 == 1) {
			a = a - 1;
			x = a;
		}

		long sub = b - a;
		if (sub % 4 == 0) {
			System.out.println(b ^ x);
		
		} else if (sub % 4 == 1) {
			System.out.println(b ^ (b - 1) ^ x);
		
		} else if (sub % 4 == 2) {
			System.out.println(b ^ 1 ^ x);
		
		} else if (sub % 4 == 3) {
			System.out.println(b ^ (b - 1) ^ 1 ^ x);
		
		}
	}
}