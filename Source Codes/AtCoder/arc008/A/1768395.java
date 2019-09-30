import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n  = sc.nextInt();
		int ans = 0;
		if(n <= 6) {
			ans = n * 15;
		} else if(7 <= n && n <= 9) {
			ans = 100;
		} else {
			ans = n / 10 * 100;
			if(0 <= n % 10 && n % 10 <= 6) {
				ans += n % 10 * 15;
			} else {
				ans += 100;
			}
		}
		System.out.println(ans);
	}
}