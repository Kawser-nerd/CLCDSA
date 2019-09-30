import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		int[] t = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			t[i] = sc.nextInt();
			sum += t[i];
		}
		int m = sc.nextInt();
		int[] p = new int[m];
		int[] x = new int[m];
		for (int i = 0; i < m; i++) {
			p[i] = sc.nextInt();
			x[i] = sc.nextInt();
		}
		for (int i = 0; i < m; i++) {
			int ans = sum - t[p[i]-1] + x[i];
			System.out.println(ans);
		}
	}
}