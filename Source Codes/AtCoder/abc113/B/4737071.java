import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int T = sc.nextInt();
		int A = sc.nextInt();

		double min=999;

		double ans = 0;
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			ans = Math.abs((T - sc.nextInt() * 0.006) - A);

			if (ans < 0) {
				ans = -ans;
			}
			if (min > ans) {
				min = ans;
				cnt = i;
			}
		}

		System.out.println(cnt + 1);
	}
}