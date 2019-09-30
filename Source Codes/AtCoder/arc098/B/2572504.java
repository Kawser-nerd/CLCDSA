import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		int[] xor = new int[N];
		int[] sum = new int[N];
		for (int i = 0; i < N; ++i) {
			A[i] = sc.nextInt();
			xor[i] = A[i] ^ (i > 0 ? xor[i - 1] : 0);
			sum[i] = A[i] + (i > 0 ? sum[i - 1] : 0);
		}
		long ans = 0;
		int t = -1;
		for (int i = 0; i < N; ++i) {
			while (t < i && sum[i] - (t >= 0 ? sum[t] : 0) != (xor[i] ^ (t >= 0 ? xor[t] : 0)))
				++t;
			ans += i - t;
		}
		System.out.println(ans);
	}

	public static void main(String[] args) {
		new Main().run();
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}