import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		long[] a = new long[N];
		for (int i = 0; i < N; ++i) {
			a[i] = sc.nextLong();
		}
		Arrays.sort(a);
		boolean[] vis = new boolean[K];
		vis[0] = true;
		int ok = N;
		for (int i = N - 1; i >= 0; --i) {
			for (int j = K - 1; j >= 0; --j) {
				if (!vis[j])
					continue;
				if (j + a[i] >= K)
					ok = i;
				else {
					vis[(int) (j + a[i])] = true;
				}
			}
		}
		System.out.println(ok);
	}
}