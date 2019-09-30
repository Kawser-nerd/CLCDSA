import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	void run() throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] L = new int[N + 1];
		int[] R = new int[N + 1];
		for (int i = 0; i < N; ++i) {
			L[i] = sc.nextInt();
			R[i] = -sc.nextInt();
		}
		long ans = 0;
		Arrays.sort(L);
		Arrays.sort(R);
		for (int i = N; i >= 0; --i) {
			if (L[i] + R[i] > 0) {
				ans += 2 * (L[i] + R[i]);
			}
		}
		System.out.println(ans);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}