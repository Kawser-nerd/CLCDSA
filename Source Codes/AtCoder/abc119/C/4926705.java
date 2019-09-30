import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int n = scanner.nextInt();
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			int c = scanner.nextInt();
			scanner.nextLine();
			int[] l = new int[n];
			IntStream.range(0, n).forEach(i -> {
				l[i] = scanner.nextInt();
				scanner.nextLine();
			});
			System.out.println(dfs(0, 0, 0, 0, n, a, b, c, l));
		}
	}

	private static long dfs(int cur, int d, int e, int f, int n, int a, int b, int c, int[] l) {
		if (cur == n) {
			if (min(d, e, f) > 0) {
				return Math.abs(d - a) + Math.abs(e - b) + Math.abs(f - c) - 30;
			} else {
				return Integer.MAX_VALUE;
			}
		}
		long ret0 = dfs(cur + 1, d, e, f, n, a, b, c, l);
		long ret1 = dfs(cur + 1, d + l[cur], e, f, n, a, b, c, l) + 10;
		long ret2 = dfs(cur + 1, d, e + l[cur], f, n, a, b, c, l) + 10;
		long ret3 = dfs(cur + 1, d, e, f + l[cur], n, a, b, c, l) + 10;
		return min(ret0, ret1, ret2, ret3);
	}

	private static int min(int... x) {
		return Arrays.stream(x).min().getAsInt();
	}

	private static long min(long... x) {
		return Arrays.stream(x).min().getAsLong();
	}
}