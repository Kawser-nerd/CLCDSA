import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();

		long ans = n;
		long cnt = 0;
		for (int i = 1; i < n; i++) {
			if (a[i - 1] < a[i]) {
				cnt++;
			} else {
				ans += cnt * (cnt + 1) / 2;
				cnt = 0;
			}
		}
		ans += cnt * (cnt + 1) / 2;
		System.out.println(ans);
	}
}