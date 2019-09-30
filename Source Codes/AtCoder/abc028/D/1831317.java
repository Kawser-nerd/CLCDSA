import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long K = sc.nextLong();
		double ans = 0;
		ans += 1. / N / N / N;
		ans += 1. / N / N * (N - 1) / N * 3;
		ans += 1. / N * (K - 1) / N * (N - K) / N * 6;
		System.out.println(ans);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}