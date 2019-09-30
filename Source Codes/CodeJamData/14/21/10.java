import java.util.Scanner;

public class A {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %s\n", i, solve());
		}
	}

	static String solve() {
		int N = sc.nextInt();
		String[] str = new String[N];
		for (int i = 0; i < N; ++i) {
			str[i] = sc.next();
		}
		int[][] count = new int[N][101];
		int[] pos = new int[N];
		for (int i = 0; pos[0] < str[0].length(); ++i) {
			char c = str[0].charAt(pos[0]);
			for (int j = 0; j < N; ++j) {
				if (pos[j] >= str[j].length() || str[j].charAt(pos[j]) != c) {
					return "Fegla Won";
				}
				while (pos[j] < str[j].length() && str[j].charAt(pos[j]) == c) {
					++pos[j];
					++count[j][i];
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			if (pos[i] != str[i].length()) {
				return "Fegla Won";
			}
		}

		int ans = 0;
		for (int i = 0; count[0][i] > 0; ++i) {
			int min = 1 << 30;
			for (int j = 1; j <= 100; ++j) {
				int sum = 0;
				for (int k = 0; k < N; ++k) {
					sum += Math.abs(count[k][i] - j);
				}
				min = Math.min(min, sum);
			}
			ans += min;
		}
		return "" + ans;
	}
}
