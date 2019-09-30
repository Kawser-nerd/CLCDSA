import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int l = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int s = sc.nextInt();
		int d = sc.nextInt();
		double ans = 1001001001.0;
		if(s <= d) {
			if(x < y) {
				ans = (double)Math.min(1.0 * (d - s) / (x + y), 1.0 * (s + l - d) / (y - x));
			} else {
				ans = (double)(1.0 * (d - s) / (x + y));
			}
		} else {
			if(x < y) {
				ans = (double)Math.min(1.0 * (d + l - s) / (x + y), 1.0 * (s - d) / (y - x));
			} else {
				ans = (double)(1.0 * (d + l - s) / (x + y));
			}
		}
		System.out.printf("%.7f", ans);
	}
}