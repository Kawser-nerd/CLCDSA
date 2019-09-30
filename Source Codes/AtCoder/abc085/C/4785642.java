import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int Y = reader.nextInt();
		int max = Y / 10000;
		int[] ans = new int[3];

		for (int i = max; i >= 0; i--) {
			ans[0] = i;
			ans[2] = (5000 * (N - ans[0]) - (Y - ans[0] * 10000)) / 4000;
			ans[1] = N - ans[0] - ans[2];
			if (ans[0] * 10000 + ans[1] * 5000 + ans[2] * 1000 == Y && ans[0] >= 0 && ans[1] >= 0 && ans[2] >= 0) {
				System.out.print(ans[0] + " " + ans[1] + " " + ans[2]);
				return;
			}
		}

		System.out.print("-1 -1 -1");
		reader.close();
	}
}