import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int l = sc.nextInt(), r = sc.nextInt();
			ans += r - l + 1;
		}
		System.out.println(ans);
	}
}