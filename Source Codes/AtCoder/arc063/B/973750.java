import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int T = sc.nextInt();

		int[] A = new int[N];

		for (int i = 0; i < N; ++i)
			A[i] = sc.nextInt();

		int maxDiff = 0;
		int min = A[0];

		for (int i = 0; i < N; ++i) {
			if (min > A[i])
				min = A[i];
			maxDiff = Math.max(A[i] - min, maxDiff);
		}

		int ans = 0;
		min = A[0];
		for (int i = 0; i < N; ++i) {
			min = Math.min(min, A[i]);
			if (maxDiff == A[i] - min) {
				++ans;
			}
		}
		System.out.println(ans);

	}
}