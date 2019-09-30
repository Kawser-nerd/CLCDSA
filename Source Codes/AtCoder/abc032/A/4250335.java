import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int a = sc.nextInt(), b = sc.nextInt(), n = sc.nextInt();
		long lcm = lcm(a, b);
		for (int i = 1; ; i++) {
			long c = lcm * i;
			if (c >= n) {
				System.out.println(c);
				return;
			}
		}
	}

	private static long lcm(long m, long n) {
		return m * n / gcd(m, n);
	}

	private static long gcd(long m, long n) {
		if (m < n) {
			return gcd(n, m);
		}
		if (n == 0) {
			return m;
		}
		return gcd(n, m % n);
	}
}