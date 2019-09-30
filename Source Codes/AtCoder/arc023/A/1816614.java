import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int y = sc.nextInt();
		int m = sc.nextInt();
		int d = sc.nextInt();
		if(m == 1) {
			m = 13;
			y--;
		}
		if(m == 2) {
			y--;
			m = 14;
		}
		int a = 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429;
		int b = 365 * 2014 + 2014 / 4 - 2014 / 100 + 2014 / 400 + 306 * (5 + 1) / 10 + 17 - 429;
		int ans = Math.abs(b - a);
		System.out.println(ans);
	}
}