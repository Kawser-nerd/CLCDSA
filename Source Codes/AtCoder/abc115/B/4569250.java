import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int p = 0;
		int max = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			p = sc.nextInt();
			max = Math.max(max, p);
			ans += p;
		}
		sc.close();

		ans -= max / 2;
		System.out.println(ans);
	}
}