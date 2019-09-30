import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int t = sc.nextInt();
		int a = sc.nextInt();

		double minSub = 1000.0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int h = sc.nextInt();
			double sub = Math.abs(a - (t - h * 0.006));
			if (sub < minSub) {
				minSub = sub;
				ans = i;
			}
		}
		System.out.println(ans);
		sc.close();
	}
}