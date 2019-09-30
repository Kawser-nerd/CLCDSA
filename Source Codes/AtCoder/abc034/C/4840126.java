import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int w = sc.nextInt();
		int h = sc.nextInt();
		sc.close();

		System.out.println(nCr(w + h - 2, w - 1));
	}

	static long nCr(long n, long r) {
		long m = 1000000007;
		long val = 1;
		for (int i = 1; i <= r; i++) {
			val = val * (n - i + 1) % m;
			val = val * modinv(i, m) % m;
		}
		return val;
	}

	static long modinv(long a, long m) {
		long b = m;
		long u = 1;
		long v = 0;
		long tmp = 0;

		while (b > 0) {
			long t = a / b;
			a -= t * b;
			tmp = a;
			a = b;
			b = tmp;

			u -= t * v;
			tmp = u;
			u = v;
			v = tmp;
		}

		u %= m;
		if (u < 0) u += m;
		return u;
	}
}