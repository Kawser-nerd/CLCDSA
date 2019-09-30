import java.io.FileNotFoundException;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;

class Main {

	class BIT {
		int n;
		long[] v;

		public BIT(int n_) {
			n = n_;
			v = new long[n + 1];
		}

		void add(int k, int val) {
			while (k <= n) {
				v[k] += val;
				k += k & -k;
			}
		}

		long sum(int k) {
			long ret = 0;
			while (k >= 1) {
				ret += v[k];
				k -= k & -k;
			}
			return ret;
		}

		long sum(int l, int r) {
			return sum(r - 1) - sum(l - 1);
		}
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		int[] cnt = new int[26];
		int[] cnt2 = new int[S.length()];
		for (int i = 0; i < S.length(); ++i) {
			++cnt[S.charAt(i) - 'a'];
			cnt2[i] = cnt[S.charAt(i) - 'a'];
		}
		boolean f = true;
		for (int i = 0; i < cnt.length; ++i) {
			if (cnt[i] % 2 != 0) {
				if (!f) {
					System.out.println(-1);
					return;
				} else {
					f = false;
				}
			}
		}
		for (int i = 0; i < S.length(); ++i) {
			if (cnt[S.charAt(i) - 'a'] % 2 == 1) {
				if (cnt2[i] <= (cnt[S.charAt(i) - 'a'] - 1) / 2)
					cnt2[i] = 1;
				else if (cnt2[i] == (cnt[S.charAt(i) - 'a'] + 1) / 2)
					cnt2[i] = 2;
				else
					cnt2[i] = 3;
			} else {
				if (cnt2[i] <= cnt[S.charAt(i) - 'a'] / 2) {
					cnt2[i] = 1;
				} else {
					cnt2[i] = 3;
				}
			}
		}

		BIT bit = new BIT(3);
		long ans = 0;

		for (int i = 0; i < S.length(); ++i) {
			ans += bit.sum(cnt2[i] + 1, 4);
			bit.add(cnt2[i], 1);
		}

		ArrayDeque<Integer>[] dq = new ArrayDeque[26];
		for (int i = 0; i < dq.length; ++i)
			dq[i] = new ArrayDeque();

		int p = 1;
		for (int i = S.length() - 1; i >= 0; --i) {
			if (cnt2[i] == 3) {
				dq[S.charAt(i) - 'a'].addLast(p++);
			}
		}
		BIT bit2 = new BIT(S.length());
		for (int i = 0; i < S.length(); ++i) {
			if (cnt2[i] == 1) {
				int j = dq[S.charAt(i) - 'a'].pollFirst();
				ans += bit2.sum(j + 1, S.length() + 1);
				bit2.add(j, 1);
			}
		}
		System.out.println(ans);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.