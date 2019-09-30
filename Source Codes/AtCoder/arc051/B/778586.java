import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int k = sc.nextInt();

		long a = 2;
		long b = 0;

		for (int i = 0; i <= k; i++) {
			long tmpb = a;
			a = tmpb + b;
			b = tmpb;
		}

		System.out.printf("%d %d\n", a, b);

		gcd(a, b);
		if (k != cnt) {
			System.out.printf("check %d %d %d\n", a, b, cnt);
		}

		sc.close();
	}

	private static int cnt = 0;

	private static long gcd(long n, long m) {
		if (m == 0) {
			return n;
		} else {
			cnt++;
			return gcd(m, n % m);
		}
	}
}