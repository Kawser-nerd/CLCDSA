import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

class Main {
	public void run() {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		long[] A = new long[K];
		for (int i = 0; i < K; ++i) {
			A[i] = sc.nextLong();
		}
		long max = 2;
		long min = 2;
		for (int i = K - 1; i >= 0; --i) {
			if (max < A[i]) {
				System.out.println(-1);
				return;
			}
			max = max / A[i] * A[i];
			min = (min + A[i] - 1) / A[i] * A[i];
			max += A[i] - 1;
			if (max < min) {
				System.out.println(-1);
				return;
			}
		}
		System.out.println(min + " " + max);
	}


	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}
}