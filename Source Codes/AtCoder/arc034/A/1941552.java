import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		double ans = 0;
		for(int i = 0 ; i < n ; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int d = sc.nextInt();
			int e = sc.nextInt();
			ans = Math.max(ans, 1.0 * (a + b + c + d) + 11.0 * e / 90.0);
		}
		System.out.printf("%.7f", ans);
	}
}