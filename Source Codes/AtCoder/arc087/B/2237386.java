import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		new Main().run();
	}

	long MOD = (long) (1e9 + 7);

	public void run() {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int x = sc.nextInt();
		int y = sc.nextInt();
		ArrayList<Integer>[] list = new ArrayList[2];
		for (int i = 0; i < 2; ++i) {
			list[i] = new ArrayList();
		}
		int c = 0;
		boolean first = true;
		for (int i = 0; i < s.length(); ++i) {
			int j = i;
			int cnt = 0;
			while (j < s.length() && s.charAt(j) == 'F') {
				++cnt;
				++j;
			}
			if (first) {
				x = Math.abs(x - cnt);
				first = false;
			} else {
				list[c].add(cnt);
			}
			i = j;
			c ^= 1;
		}
		x = Math.abs(x);
		y = Math.abs(y);
		if (x > 8000 || y > 8000) {
			System.out.println("No");
			return;
		}
		boolean[][] dp = new boolean[2][8001];
		dp[0][0] = true;
		for (int i = 0; i < list[0].size(); ++i) {
			for (int j = 0; j <= 8000; ++j) {
				dp[(i % 2) ^ 1][j] = false;
			}
			for (int j = 0; j + list[0].get(i) <= 8000; ++j) {
				if (dp[(i % 2)][j]) {
					dp[(i % 2) ^ 1][j + list[0].get(i)] = true;
					dp[(i % 2) ^ 1][Math.abs(j - list[0].get(i))] = true;
				}
			}
		}
		if (!dp[list[0].size() % 2][x]) {
			System.out.println("No");
			return;
		}
		dp = new boolean[2][8001];
		dp[0][0] = true;
		for (int i = 0; i < list[1].size(); ++i) {
			for (int j = 0; j <= 8000; ++j) {
				dp[(i % 2) ^ 1][j] = false;
			}
			for (int j = 0; j + list[1].get(i) <= 8000; ++j) {
				if (dp[(i % 2)][j]) {
					dp[(i % 2) ^ 1][j + list[1].get(i)] = true;
					dp[(i % 2) ^ 1][Math.abs(j - list[1].get(i))] = true;
				}
			}
		}
		if (!dp[list[1].size() % 2][y]) {
			System.out.println("No");
			return;
		}
		System.out.println("Yes");
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.