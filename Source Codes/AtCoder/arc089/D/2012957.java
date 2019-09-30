import java.io.*;
import java.util.*;

public class Main {

	static final int P = 1_000_000_007;

	void submit() {
		int n = nextInt();
		nextInt();
		char[] s = nextToken().toCharArray();

		int ans = 1;

		for (int rb = 0; 2 * rb <= s.length; rb++) {
			for (int r = 0; 2 * rb + r <= s.length; r++) {
				if (rb == 0 && r == 0) {
					continue;
				}

				int nowRb = 0;
				int nowR = 0;

				int[] have = new int[rb];

				for (char c : s) {
					if (c == 'r') {
						if (nowRb + nowR < rb + r) {
							nowR++;
						} else if (nowRb > 0) {
							have[rb - nowRb]++;
						}
					} else {
						if (nowR > 0 && nowRb < rb) {
							nowR--;
							nowRb++;
						} else if (nowRb > 0) {
							have[rb - nowRb]++;
						}
					}
				}

				if (nowR != r || nowRb != rb) {
					continue;
				}

				for (int i = 1; i < rb; i++) {
					have[i] += have[i - 1];
				}

				ans += solve(rb, r, have, n);
				if (ans >= P) {
					ans -= P;
				}
			}
		}

		out.println(ans);
	}

	int solve(int rb, int r, int[] have, int len) {
		
//		System.err.println(rb + " " + r + " " + Arrays.toString(have) + " " + len);
		
		
		int maxUsed = have.length == 0 ? 0 : have[have.length - 1];
		int[][] dp = new int[rb + 1][maxUsed + 1];
		dp[0][0] = (int) ((long) fact[rb + r] * invFact[r] % P);

		for (int x = 0; x <= maxUsed; x++) {
			for (int idx = rb; idx >= 0; idx--) {
				for (int sum = 0; sum <= maxUsed; sum++) {
					int val = dp[idx][sum];
					if (val == 0) {
						continue;
					}

					for (int k = 1; idx + k <= rb
							&& sum + k * x <= have[idx + k - 1]; k++) {

						int delta = (int) ((long) val * invFact[k] % P);
						dp[idx + k][sum + k * x] += delta;
						if (dp[idx + k][sum + k * x] >= P) {
							dp[idx + k][sum + k * x] -= P;
						}

					}
				}
			}
		}

		int ret = 0;
		for (int sum = 0; sum <= maxUsed; sum++) {
			int ways = dp[rb][sum];

			if (ways == 0) {
				continue;
			}

			int boxes = rb + r + 1; // whites
			boxes += r; // just rs
			boxes += 3 * rb + 2 * sum; // rbs, with 0->3, 1->5, 2->7, ...

			int occ = rb + r - 1; // whites
			occ += r; // just rs
			occ += rb + 2 * sum; // rbs, with 0->1, 1->3, 2->5

			int free = len - occ;
			if (free < 0) {
				continue;
			}

			ret += (int) ((long) ways * go(boxes, free) % P);
			if (ret >= P) {
				ret -= P;
			}
		}

		return ret;
	}

	int go(int boxes, int items) {
		return (int) ((long) fact[items + boxes - 1] * invFact[items] % P
				* invFact[boxes - 1] % P);
	}

	static final int N = 200;

	int[] fact;
	int[] invFact;

	void preCalc() {
		int[] inv = new int[N];
		inv[0] = 0;
		inv[1] = 1;
		for (int i = 2; i < inv.length; i++) {
			inv[i] = P - (int) ((long) (P / i) * inv[P % i] % P);
		}

		fact = new int[N];
		invFact = new int[N];
		fact[0] = invFact[0] = 1;

		for (int i = 1; i < N; i++) {
			fact[i] = (int) ((long) i * fact[i - 1] % P);
			invFact[i] = (int) ((long) inv[i] * invFact[i - 1] % P);
		}

	}

	void stress() {

	}

	void test() {

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}