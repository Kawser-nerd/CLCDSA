import java.util.HashMap;
import java.util.Scanner;

public class D {

	static Scanner sc = new Scanner(System.in);
	static int P;
	static long[] E, F;
	static HashMap<Long, Integer> map;

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			long[] ans = solve();
			System.out.printf("Case #%d:", i);
			for (long a : ans) {
				System.out.printf(" %d", a);
			}
			System.out.println();
		}
	}

	static long[] solve() {
		P = sc.nextInt();
		E = new long[P];
		F = new long[P];
		long sumF = 0;
		map = new HashMap<>();
		for (int i = 0; i < P; ++i) {
			E[i] = sc.nextLong();
			map.put(E[i], i);
		}
		for (int i = 0; i < P; ++i) {
			F[i] = sc.nextLong();
			sumF += F[i];
		}
		long[] ans = new long[Long.numberOfTrailingZeros(sumF)];
		for (int i = 0; i < P; ++i) {
			for (int j = 0; j < P; ++j) {
				if (F[j] == 0) continue;
				if (check(F, j)) {
					ans[i] = E[j];
					break;
				}
			}
		}
		return ans;
	}

	static boolean check(long[] f, int pos) {
		long[] revert = f.clone();
		long v = E[pos];
		boolean ok = true;
		if (v < 0) {
			for (int i = P - 1; i >= 0; --i) {
				if (f[i] == 0) continue;
				long n = E[i] + v;
				if (!map.containsKey(n)) {
					ok = false;
					break;
				}
				int idx = map.get(n);
				if (f[idx] < f[i]) {
					ok = false;
					break;
				}
				f[idx] -= f[i];
			}
		} else if (v > 0) {
			for (int i = 0; i < P; ++i) {
				if (f[i] == 0) continue;
				long n = E[i] + v;
				if (!map.containsKey(n)) {
					ok = false;
					break;
				}
				int idx = map.get(n);
				if (f[idx] < f[i]) {
					ok = false;
					break;
				}
				f[idx] -= f[i];
			}
		} else {
			for (int i = 0; i < P; ++i) {
				if (f[i] % 2 == 0) {
					f[i] /= 2;
				} else {
					ok = false;
					break;
				}
			}
		}
		if (!ok) {
			System.arraycopy(revert, 0, f, 0, P);
		}
		return ok;
	}
}
