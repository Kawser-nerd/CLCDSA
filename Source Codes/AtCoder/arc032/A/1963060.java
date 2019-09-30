import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner sc = new Scanner(System.in);

		int score = 0;
		int n = sc.nextInt();

		if (n == 1) {
			System.out.println("BOWWOW");
			System.exit(0);
		}

		for (int i = 0; i <= n; i++) {
			score += i;
		}

		for (int i = 2; i < n; i++) {
			if (score % i == 0) {
				System.out.println("BOWWOW");
				System.exit(0);
			}
		}
		System.out.println("WANWAN");

	}

}