import java.util.Arrays;
import java.util.Scanner;

public class B {

	static Scanner sc = new Scanner(System.in);
	static int N;
	static int[] ans, X, Y;

	public static void main(String[] args) throws Exception {
		int T = sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			solve();
			System.out.print("Case #" + t + ":");
			for (int i = 0; i < N; ++i) {
				System.out.print(" " + ans[i]);
			}
			System.out.println();
		}
	}

	static void solve() {
		N = sc.nextInt();
		int[] ord = new int[N];
		X = new int[N];
		Y = new int[N];
		for (int i = 0; i < N; ++i) {
			X[i] = sc.nextInt();
			Y[i] = sc.nextInt();
			ord[i] = i;
		}
		ans = new int[N];
		double max = -1;

		do {
			if (ord[0] != 0) break;
			boolean ok = true;
			for (int i = 2; i < N; ++i) {
				for (int j = (i == N - 1 ? 1 : 0); j <= i - 2; ++j) {
					if (cross(ord[i], ord[(i + 1) % N], ord[j], ord[j + 1])) {
						ok = false;
						break;
					}
				}
			}
			if (ok) {
				double s = 0;
				for (int i = 0; i < N; ++i) {
					s += X[ord[i]] * Y[ord[(i + 1) % N]] - X[ord[(i + 1) % N]] * Y[ord[i]];
				}
				s = Math.abs(s);
				//				System.out.println(Arrays.toString(ord) + " " + s);
				if (s > max) {
					max = s;
					ans = ord.clone();
				}
			}
		} while (nextPermutation(ord));
	}

	static boolean cross(int p1, int p2, int p3, int p4) {
		int x1 = X[p1];
		int y1 = Y[p1];
		int x2 = X[p2];
		int y2 = Y[p2];
		int x3 = X[p3];
		int y3 = Y[p3];
		int x4 = X[p4];
		int y4 = Y[p4];
		int ta = (x3 - x4) * (y1 - y3) + (y3 - y4) * (x3 - x1);
		int tb = (x3 - x4) * (y2 - y3) + (y3 - y4) * (x3 - x2);
		int tc = (x1 - x2) * (y3 - y1) + (y1 - y2) * (x1 - x3);
		int td = (x1 - x2) * (y4 - y1) + (y1 - y2) * (x1 - x4);
		if (ta * tb < 0 && tc * td < 0) return true;
		if (ta == 0) {
			int dx = x3 - x4;
			int dy = y3 - y4;
			double t;
			if (dx != 0) {
				t = 1.0 * (x1 - x4) / dx;
			} else {
				t = 1.0 * (y1 - y4) / dy;
			}
			if (0 <= t && t <= 1) return true;
		}
		if (tb == 0) {
			int dx = x3 - x4;
			int dy = y3 - y4;
			double t;
			if (dx != 0) {
				t = 1.0 * (x2 - x4) / dx;
			} else {
				t = 1.0 * (y2 - y4) / dy;
			}
			if (0 <= t && t <= 1) return true;
		}
		if (tc == 0) {
			int dx = x1 - x2;
			int dy = y1 - y2;
			double t;
			if (dx != 0) {
				t = 1.0 * (x3 - x2) / dx;
			} else {
				t = 1.0 * (y3 - y2) / dy;
			}
			if (0 <= t && t <= 1) return true;
		}
		if (td == 0) {
			int dx = x1 - x2;
			int dy = y1 - y2;
			double t;
			if (dx != 0) {
				t = 1.0 * (x4 - x2) / dx;
			} else {
				t = 1.0 * (y4 - y2) / dy;
			}
			if (0 <= t && t <= 1) return true;
		}
		return false;
	}

	public static boolean nextPermutation(int[] a) {
		for (int i = a.length - 1; i > 0; --i) {
			if (a[i - 1] < a[i]) {
				int swapIndex = find(a[i - 1], a, i, a.length - 1);
				int temp = a[swapIndex];
				a[swapIndex] = a[i - 1];
				a[i - 1] = temp;
				Arrays.sort(a, i, a.length);
				return true;
			}
		}
		return false;
	}

	private static int find(int dest, int[] a, int s, int e) {
		if (s == e) {
			return s;
		}
		int m = (s + e + 1) / 2;
		return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
	}
}
