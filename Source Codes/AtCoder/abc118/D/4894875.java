import java.util.Arrays;
import java.util.Scanner;

public class Main {

	private static final int[] NUMBER = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int n = scanner.nextInt();
			int m = scanner.nextInt();
			scanner.nextLine();
			int[] a = new int[m];
			int[] num = new int[m];
			for (int i = 0; i < m; i++) {
				a[i] = scanner.nextInt();
				num[i] = num(a[i]);
			}
			scanner.nextLine();
			Arrays.sort(a);
			Arrays.sort(num);
			int digit = dp(n, num);
			int remain = n;
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < digit; i++) {
				for (int j = m - 1; j >= 0; j--) {
					if (dp(remain - num(a[j]), num) == dp(remain, num) - 1) {
						sb.append(a[j]);
						remain -= num(a[j]);
						break;
					}
				}
			}
			System.out.println(sb.toString());
		}
	}

	/**
	 * @param k ??
	 * @return ?????????????????
	 */
	private static int num(int k) {
		return NUMBER[k];
	}

	/**
	 * @param n   ???????
	 * @param num ???????????????????
	 * @return ?????????
	 */
	private static int dp(int n, int[] num) {
		if (0 == n) {
			return 0;
		}
		int min = num[0];
		if (n % min == 0) {
			return n / min;
		} else {
			for (int number : num) {
				if (n >= number) {
					int next = dp(n - number, num);
					if (next >= 0) {
						return next + 1;
					}
				}
			}
		}
		return -1;
	}
}