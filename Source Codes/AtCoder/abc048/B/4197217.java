import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		long a = sc.nextLong();
		long b = sc.nextLong();
		long x = sc.nextLong();

		if (b == 0) {
			System.out.println(1);
			sc.close();
			return;
		}

		System.out.println(func(b, x) - func(a - 1, x));

		sc.close();
	}

	static long func(long n, long x) {
		if (n < 0)
			return 0;
		return n / x + 1;
	}
}