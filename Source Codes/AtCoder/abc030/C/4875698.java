import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[m];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		for (int i = 0; i < m; i++) {
			b[i] = sc.nextInt();
		}
		sc.close();

		int ans = 0;
		int t = 0;
		while (true) {
			int idx = Arrays.binarySearch(a, t);
			if (idx < 0) idx = ~idx;
			if (idx >= n) break;
			t = a[idx];
			t += x;

			idx = Arrays.binarySearch(b, t);
			if (idx < 0) idx = ~idx;
			if (idx >= m) break;
			t = b[idx];
			t += y;

			ans++;
		}
		System.out.println(ans);
	}
}