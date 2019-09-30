import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		int prev = -1;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int tmp = sc.nextInt();
			if (tmp == prev) {
				ans++;
				prev = -1;
			} else {
				prev = tmp;
			}
		}
		System.out.println(ans);
	}
}