import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		long[] V = { sc.nextLong(), sc.nextLong() };
		Arrays.sort(V);
		if (V[1] - V[0] > 1) {
			System.out.println("Alice");
		} else {
			System.out.println("Brown");
		}
//		for (int i = 0; i < 100; ++i) {
//			for (int j = i; j < 100; ++j) {
//				System.out.println(i + " " + j + " " + dfs(i, j));
//			}
//		}
	}

	int[][] memo = new int[1000][1000];

	boolean dfs(int a, int b) {
		if (memo[a][b] != 0) {
			return memo[a][b] == 1;
		}
		boolean f = false;
		for (int i = 1; 2 * i <= a; ++i) {
			f |= !dfs(a - i * 2, b + i);
		}
		for (int i = 1; 2 * i <= b; ++i) {
			f |= !dfs(a + i, b - 2 * i);
		}
		if (f) {
			memo[a][b] = 1;
		} else {
			memo[a][b] = -1;
		}
		return f;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}