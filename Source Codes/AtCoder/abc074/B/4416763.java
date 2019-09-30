import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt(), k = sc.nextInt();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x = sc.nextInt();
			ans += Math.min(Math.abs(k - x), x) * 2;
		}
		System.out.println(ans);
	}
}