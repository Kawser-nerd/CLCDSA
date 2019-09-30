import java.util.Scanner;


public class A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			long ans = 0;
			int N = sc.nextInt();
			int[] A = new int[N];
			int[] B = new int[N];
			for (int n = 0; n < N; ++n) {
				A[n] = sc.nextInt();
				B[n] = sc.nextInt();
				for (int i = 0; i < n; ++i) {
					int da = A[i] - A[n];
					int db = B[i] - B[n];
					if (da > 0) {
						if (db < 0) ans++;
					} else {
						if (db > 0) ans++;
					}
				}
			}
			System.out.println("Case #" + t + ": " + ans);
		}
	}
}
