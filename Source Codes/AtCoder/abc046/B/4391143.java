import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		try {
			int n = sc.nextInt();
			int k = sc.nextInt();

			int ans = k;
			for (int i = 0; i < n - 1; i++) {
				ans *= (k - 1);
			}

			System.out.println(ans);

		} finally {
			sc.close();
		}
	}
}