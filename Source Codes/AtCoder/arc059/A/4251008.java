import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		int ans = Integer.MAX_VALUE;
		for (int i = -100; i <= 100; i++) {
			int tmp = 0;
			for (int j = 0; j < n; j++) {
				tmp += (int) Math.pow(a[j] - i, 2);
			}
			ans = Math.min(ans, tmp);
		}
		System.out.println(ans);
	}
}