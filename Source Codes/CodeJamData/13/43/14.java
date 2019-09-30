import java.util.Scanner;

public class C {

	static Scanner sc = new Scanner(System.in);
	static int N;
	static int[] A, B;
	static int[] X;
	static boolean[] used;

	public static void main(String[] args) throws Exception {
		int T = sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			solve();
			System.out.print("Case #" + t + ":");
			for (int i = 0; i < N; ++i) {
				System.out.print(" " + X[i]);
			}
			System.out.println();
		}
	}

	static void solve() {
		N = sc.nextInt();
		A = new int[N];
		B = new int[N];
		X = new int[N];
		used = new boolean[N + 1];
		for (int i = 0; i < N; ++i) {
			A[i] = sc.nextInt();
		}
		for (int i = 0; i < N; ++i) {
			B[i] = sc.nextInt();
		}
		used[1] = true;
		dfs(0);
	}

	static boolean dfs(int d) {
		if (d == N) {
			return check();
		}
		if (A[d] == 1 && B[d] == 1) {
			X[d] = 1;
			return dfs(d + 1);
		}
		int min = Math.max(A[d], B[d]);
		int max = N;
		for (int i = 0; i < d; ++i) {
			if (A[i] >= A[d]) {
				max = Math.min(max, X[i] - 1);
			}
			if (B[i] <= B[d]) {
				min = Math.max(min, X[i] + 1);
			}
		}
		//		System.out.println(d + " " + min + " " + max);
		for (int i = min; i <= max; ++i) {
			if (used[i]) continue;
			used[i] = true;
			X[d] = i;
			if (dfs(d + 1)) return true;
			used[i] = false;
		}
		return false;
	}

	static boolean check() {
		int[] fw = new int[N + 1];
		int[] bk = new int[N + 1];
		for (int i = 0; i < N; ++i) {
			fw[i] = bk[N - 1 - i] = 1;
			for (int j = 0; j < i; ++j) {
				if (X[j] < X[i]) fw[i] = Math.max(fw[i], fw[j] + 1);
			}
			for (int j = N - 1; j > N - 1 - i; --j) {
				if (X[j] < X[N - 1 - i]) bk[N - 1 - i] = Math.max(bk[N - 1 - i], bk[j] + 1);
			}
			if (fw[i] != A[i]) return false;
			if (bk[N - 1 - i] != B[N - 1 - i]) return false;
		}
		return true;
	}
}
