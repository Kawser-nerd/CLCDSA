import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
		int ans = 0;
		if (a + b < c) {
			ans += a + b + 1;
		} else {
			ans += c;
		}
		ans += b;
		System.out.println(ans);
	}
}