import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();

		int ans = Integer.MAX_VALUE;
		for (int i = 0; i <= n; i++) {
			int cnt = 0;
			int n6 = i;
			int n9 = n - i;

			for (int a = 6; a >= 0; a--) {
				int mod = (int) Math.pow(6, a);
				cnt += n6 / mod;
				n6 %= mod;
			}
			for (int a = 5; a >= 0; a--) {
				int mod = (int) Math.pow(9, a);
				cnt += n9 / mod;
				n9 %= mod;
			}
			ans = Math.min(ans, cnt);
		}
		System.out.println(ans);
	}
}