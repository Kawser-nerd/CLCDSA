import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			while (a % 2 != 1 || a % 3 == 2) {
				a--;
				ans++;
			}
		}
		System.out.println(ans);
	}
}