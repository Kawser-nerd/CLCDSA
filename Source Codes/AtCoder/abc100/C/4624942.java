import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			a = sc.nextInt();
			while (a % 2 == 0) {
				a /= 2;
				ans++;
			}
		}
		sc.close();

		System.out.println(ans);
	}
}