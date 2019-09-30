import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] c = new int[n];
		int[] s = new int[n];
		int[] f = new int[n];
		for (int i = 0; i < n - 1; i++) {
			c[i] = sc.nextInt();
			s[i] = sc.nextInt();
			f[i] = sc.nextInt();
		}
		sc.close();

		for (int i = 0; i < n; i++) {
			int ans = s[i] + c[i];
			for (int j = i + 1; j < n - 1; j++) {
				ans += (f[j] - (ans % f[j]))  % f[j];
				ans = Math.max(ans, s[j]);
				ans += c[j];
			}
			System.out.println(ans);
		}
	}
}