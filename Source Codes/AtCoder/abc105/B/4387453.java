import java.io.IOException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		String ans = "No";

		outer:
		for (int i = 0; i * 4 <= n; i++) {
			for (int j = 0; i * 4 + j * 7 <= n; j++) {
				if (i * 4 + j * 7 == n) {
					ans = "Yes";
					break outer;
				}
			}
		}
		System.out.println(ans);
		sc.close();
	}
}