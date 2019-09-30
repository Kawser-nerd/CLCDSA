import java.util.Arrays;
import java.util.Scanner;

public class ProblemA {
	public static void main(final String[] args) {
		final Scanner sc = new Scanner(System.in);
		final int cases = sc.nextInt();
		final long[] freq = new long[1000];
		for (int cc = 1; cc <= cases; cc++) {
			final int p = sc.nextInt(), k = sc.nextInt(), l = sc.nextInt();
			for (int i = 0; i < l; i++)
				freq[i] = sc.nextLong();
			Arrays.sort(freq, 0, l);

			long count = 0;
			for (int i = l - 1; i >= 0; i--) {
				final int a = l - 1 - i;
				count += freq[i] * (a / k + 1);
			}

			System.out.printf("Case #%s: %s\n", cc, count);
		}
		System.out.flush();
	}
}