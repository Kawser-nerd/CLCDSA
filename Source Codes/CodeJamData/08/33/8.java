import java.util.Scanner;

public class ProblemC {
	public static void main(final String[] args) {
		final Scanner sc = new Scanner(System.in);
		final int cases = sc.nextInt();
		for (int cc = 1; cc <= cases; cc++) {
			final int n = sc.nextInt();
			final int m = sc.nextInt();
			final long x = sc.nextLong(), y = sc.nextLong(), z = sc.nextLong();
			final int[] h = new int[n];
			final int[] a = new int[n];

			for (int i = 0; i < m; i++)
				h[i] = sc.nextInt();

			for (int i = 0; i < n; i++) {
				a[i] = h[i % m];
				h[i % m] = (int) ((x * h[i % m] + y * (i + 1)) % z);
			}

			final int[] s = new int[n];
			for (int i = 0; i < n; i++) {
				s[i] = 1;
				for (int j = 0; j < i; j++)
					if (a[j] < a[i]) s[i] = (s[i] + s[j]) % 1000000007;
			}
			int count = 0;
			for (int i = 0; i < n; i++)
				count = (count + s[i]) % 1000000007;

			System.out.printf("Case #%s: %s\n", cc, count);
		}
		System.out.flush();
	}
}