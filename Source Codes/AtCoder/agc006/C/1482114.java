import java.util.Arrays;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// new Main().run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] x = new int[N];
		int[] d = new int[N];// d[i]: = | x[i] - x[i-1] |
		for (int i = 0; i < N; ++i) {
			x[i] = sc.nextInt();
			d[i] = x[i] - (i > 0 ? x[i - 1] : 0);
		}
		int M = sc.nextInt();
		long K = sc.nextLong();
		int[] a = new int[M];
		int[] comb = new int[N];// comb[i]:=i?????comb[i]???
		for (int i = 0; i < N; ++i) {
			comb[i] = i;
		}
		for (int i = 0; i < M; ++i) {
			a[i] = sc.nextInt();
			--a[i];
			// swap[ d[i] , d[i+1] ]
			{
				int tmp = comb[a[i]];
				comb[a[i]] = comb[a[i] + 1];
				comb[a[i] + 1] = tmp;
			}
		}

		int[] cur = new int[N];
		for (int i = 0; i < N; ++i) {
			cur[i] = i;
		}
		for (; K > 0; K >>= 1, comb = mul(comb, comb)) {
			if (K % 2 == 1) {
				cur = mul(cur, comb);
			}
		}
		long L = 0;
		for (int i = 0; i < N; ++i) {
			L += d[cur[i]];
			System.out.println(L);
		}
	}

	int[] mul(int[] ord1, int[] ord2) {
		int n = ord1.length;
		if (ord1.length != ord2.length) {
			throw new AssertionError();
		}
		int[] ret = new int[n];
		for (int i = 0; i < n; ++i) {
			ret[i] = ord1[ord2[i]];
		}
		return ret;
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}