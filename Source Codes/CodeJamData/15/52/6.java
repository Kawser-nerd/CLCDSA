import java.util.Scanner;

public class B {
	static Scanner sc = new Scanner(System.in);
	static int N, K;
	static int[] S;

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			int ans = solve();
			System.out.printf("Case #%d: %s\n", i, ans);
		}
	}

	static int solve() {
		N = sc.nextInt();
		K = sc.nextInt();
		S = new int[N - K + 1];
		for (int i = 0; i <= N - K; ++i) {
			S[i] = sc.nextInt();
		}
		int[] min = new int[K];
		int[] max = new int[K];
		for (int i = 0; i < K; ++i) {
			int cur = i;
			int v = 0;
			while (cur < N - K) {
				v = v + S[cur + 1] - S[cur];
				min[i] = Math.min(min[i], v);
				max[i] = Math.max(max[i], v);
				cur += K;
			}
		}
		int rest = S[0];
		int mi = Integer.MAX_VALUE;
		for (int i = 0; i < K; ++i) {
			mi = Math.min(mi, min[i]);
		}
		for (int i = 0; i < K; ++i) {
			int diff = min[i] - mi;
			min[i] -= diff;
			max[i] -= diff;
			rest += diff;
		}
		while (rest < 0) {
			rest += K;
		}
		rest %= K;
		while (rest > 0) {
			int mav = Integer.MIN_VALUE;
			int miv = Integer.MAX_VALUE;
			int mai = 0;
			for (int i = 0; i < K; ++i) {
				if (max[i] > mav || (max[i] == mav && min[i] < miv)) {
					mai = i;
					mav = max[i];
					miv = min[i];
				}
			}
			int id = -1;
			int mimin = Integer.MAX_VALUE;
			for (int i = 0; i < K; ++i) {
				if (max[i] == mav) continue;
				if (min[i] < mimin) {
					mimin = min[i];
					id = i;
				}
			}
			if (id == -1) {
				min[mai]++;
				max[mai]++;
			} else {
				min[id]++;
				max[id]++;
			}
			rest--;
		}
		int tmin = Integer.MAX_VALUE;
		int tmax = Integer.MIN_VALUE;
		for (int i = 0; i < K; ++i) {
			tmin = Math.min(tmin, min[i]);
			tmax = Math.max(tmax, max[i]);
		}
		return tmax - tmin;
	}
}
