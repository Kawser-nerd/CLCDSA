import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int ans = 0;
		for (int i = 0; i < 3; i++) {
			ans += sc.nextInt() / 10 * sc.nextInt();
		}
		System.out.println(ans);
	}
}