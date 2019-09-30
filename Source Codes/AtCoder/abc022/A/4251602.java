import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt(), s = sc.nextInt(), t = sc.nextInt();
		int w = sc.nextInt();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (i != 0) {
				w += sc.nextInt();
			}
			if (w >= s && w <= t) {
				ans++;
			}
		}
		System.out.println(ans);
	}
}