import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();

		long ans = 0;
		long sum = 0;
		for (int i = 0; i < k; i++) {
			sum += a[i];
		}
		ans += sum;

		for (int i = 1; i <= n - k; i++) {
			sum -= a[i - 1];
			sum += a[i - 1 + k];
			ans += sum;
		}
		System.out.println(ans);
	}
}