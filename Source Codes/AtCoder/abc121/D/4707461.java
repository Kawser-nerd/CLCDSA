import java.util.Scanner;

public class Main {
	public static final long x = 62L;
	public static final long one = 1L;

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		final long a = scanner.nextLong();
		final long b = scanner.nextLong();
		final long n = b - a + 1;
		long result = 0;
		for (int i = 0; i < x; i++) {
			long T = one << i + 1;
			long ra = a % T;
			long r = n % T;
			if (i == 0) {
				long ones = calcOnes(T, ra, r);
				ones += n / T;
				result = result ^ ((ones % 2) << i);
				continue;
			}
			long ones = calcOnes(T, ra, r);
			result ^= ((ones % 2) << i);
		}
		System.out.println(result);
		scanner.close();
	}

	public static long calcOnes(long T, long ra, long r) {
		long zero2ra = Math.max(0, ra - T/2);
		long zero2raPr;
		if(r + ra > T) {
			zero2raPr = T/2 + Math.max(0, (r + ra - T) - T/2);
		}else {
			zero2raPr = Math.max(0, ra + r - T/2);
		}
		long ones = zero2raPr - zero2ra;
		return ones;
	}
}