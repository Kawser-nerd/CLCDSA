import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += i;
		}
		System.out.println(ans);
	}
}