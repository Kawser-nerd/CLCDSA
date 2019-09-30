import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n;
		int[] c;
		n = sc.nextInt();
		c = new int[n];
		for (int i = 0; i < n; ++i) {
			c[i] = sc.nextInt();
			--c[i];
		}
		int[] a = new int[n];
		Arrays.fill(a, Integer.MAX_VALUE / 3);
		for (int i = 0; i < n; ++i) {
			a[-Arrays.binarySearch(a, c[i]) - 1] = c[i];
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] != Integer.MAX_VALUE / 3) {
				ans = Math.max(ans, i + 1);
			}
		}
		System.out.println(n - ans);

	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}