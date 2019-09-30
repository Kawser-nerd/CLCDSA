import java.util.*;

public class Main {

	public static void main(String[] args) {
		new Main().execute();
	}

	public void execute() {
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		int[] c = new int[N - 1];
		int[] S = new int[N - 1];
		int[] F = new int[N - 1];

		for (int i = 0; i < N - 1; i++) {
			c[i] = sc.nextInt();
			S[i] = sc.nextInt();
			F[i] = sc.nextInt();
		}

		for (int i = 0; i < N; i++) {
			int[] at = new int[N];
			int[] dt = new int[N];
			if (i == N - 1) {
				dt[i] = 0;
			} else {
				dt[i] = S[i];
			}
			for (int j = i + 1; j < N; j++) {
				at[j] = dt[j - 1] + c[j - 1];
				if (j < N - 1) {
					dt[j] = (at[j] < S[j]) ? S[j] : S[j] + F[j] * roundUp(at[j] - S[j], F[j]);
				}
			}
			System.out.println(at[N - 1]);
		}

		sc.close();
	}

	private int roundUp(int a, int b) {
		int res = a / b;
		if (a % b == 0) {
			return res;
		} else {
			return res + 1;
		}
	}

}