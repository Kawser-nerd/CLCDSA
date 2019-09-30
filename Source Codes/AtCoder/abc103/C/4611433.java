import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += sc.nextInt();
		}
		sc.close();

		ans -= n;
		System.out.println(ans);
	}
}