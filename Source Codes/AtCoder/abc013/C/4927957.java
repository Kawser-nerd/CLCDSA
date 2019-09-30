import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long h = sc.nextLong();
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		long d = sc.nextLong();
		long e = sc.nextLong();
		sc.close();

		long ans = Long.MAX_VALUE;
		for (int x = 0; x <= n; x++) {
			long y = e*n - e*x - h - b*x;
			if (y < 0) {
				y = 0;
			} else {
				y = y / (d + e) + 1;
			}
			if (x + y <= n) {
				ans = Math.min(ans, a*x + c*y);
			}
		}
		System.out.println(ans);
	}
}