import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class E {

	static Output solveOneTest(Input input) {
		return input.solve();
	}

	static class Input {
		int n;
		int[] sequence;

		Input() throws IOException {
			n = nextInt();
			sequence = new int[n];
			for (int i = 0; i < n; i++) {
				sequence[i] = nextInt();
			}
		}

		Output solve() {
			int[][] dpPrefix = new int[n + 1][n + 1];
			int[][] dpSuffix = new int[n + 1][n + 1];
			dpPrefix[0][0] = 1;
			dpSuffix[n][0] = 1;
			for (int i = 0; i < n; i++) {
				for (int wasLength = 0; wasLength < n; wasLength++) {
					for (int wasLast = 0; wasLast <= i; wasLast++) {
						if (wasLast == 0
								|| sequence[wasLast - 1] >= sequence[i]) {
							dpPrefix[i + 1][wasLength + 1] = add(
									dpPrefix[i + 1][wasLength + 1],
									dpPrefix[wasLast][wasLength]);
						}
					}
				}
			}

			for (int i = n - 1; i >= 0; --i) {
				dpSuffix[i][1] = 0;
				for (int wasLength = 0; wasLength < n; wasLength++) {
					for (int wasLast = i + 1; wasLast <= n; wasLast++) {
						if (wasLast == n || sequence[wasLast] <= sequence[i]) {
							dpSuffix[i][wasLength + 1] = add(
									dpSuffix[i][wasLength + 1],
									dpSuffix[wasLast][wasLength]);
						}
					}
				}
			}

			if (dpPrefix[n][n] == 1) {
				return new Output(1);
			}

//			int[][] dp = new int[n][n + 1];
//			for (int dude = 0; dude < n; dude++) {
//				for (int hadBefore = 0; hadBefore <= dude; hadBefore++) {
//					for (int hadAfter = 0; hadAfter <= n - 1 - dude; hadAfter++) {
//						int cur = mul(dpPrefix[dude + 1][hadBefore + 1],
//								dpSuffix[dude][hadAfter + 1]);
//						int len = hadBefore + hadAfter + 1;
//						dp[dude][len] = add(dp[dude][len], cur);
//					}
//				}
//			}
			// System.err.println(Arrays.deepToString(dpPrefix));
			// System.err.println(Arrays.deepToString(dpSuffix));
			// for (int i = 0; i < n; i++) {
			// System.err.println(sequence[i] + ": " + Arrays.toString(dp[i]));
			// }
			// System.err.println(Arrays.deepToString(dp));
			// System.err.println(goStupid(0)+" - stupid");
			int answer = 0;

			int[] fact = new int[n];
			fact[0] = 1;
			for (int i = 1; i < n; i++) {
				fact[i] = mul(fact[i - 1], i);
			}

			for (int lastRemovedDude = 0; lastRemovedDude < n; lastRemovedDude++) {
				for (int before = 0; before <= lastRemovedDude; before++) {
					for (int after = lastRemovedDude + 1; after <= n; after++) {
						boolean beforeBad = before == 0
								|| sequence[before - 1] >= sequence[lastRemovedDude];
						boolean afterBad = after == n
								|| sequence[after] <= sequence[lastRemovedDude];
						if (beforeBad && afterBad) {
							continue;
						}
						if (before > 0 && after < n
								&& sequence[before - 1] < sequence[after]) {
							continue;
						}
						for (int length1 = 0; length1 <= before; length1++) {
							for (int length2 = 0; length2 <= n - after; length2++) {
								int ways = mul(dpPrefix[before][length1],
										dpSuffix[after][length2]);
								int length = length1 + length2;
								ways = mul(ways, fact[n - length - 1]);
								answer = add(answer, ways);
							}
						}
					}
				}
			}
			return new Output(answer);
		}

		int goStupid(int mask) {
			boolean bad = false;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if ((mask & (1 << i)) != 0) {
						continue;
					}
					if ((mask & (1 << j)) != 0) {
						continue;
					}
					if (sequence[i] < sequence[j]) {
						bad = true;
					}
				}
			}
			if (!bad) {
				return 1;
			}
			int ret = 0;
			for (int i = 0; i < n; i++) {
				if ((mask & (1 << i)) == 0) {
					ret += goStupid(mask | (1 << i));
				}
			}
			return ret;
		}
	}

	static int add(int a, int b) {
		a += b;
		if (a >= MOD) {
			a -= MOD;
		}
		return a;
	}

	static int mul(int a, int b) {
		return a * b % MOD;
	}

	static final int MOD = 10007;

	static class Output {
		int answer;

		public Output(int answer) {
			super();
			this.answer = answer;
		}

		void writeOutput() {
			out.println(answer);
		}
	}

	public static void main(String[] args) throws IOException,
			InterruptedException, ExecutionException {
		br = new BufferedReader(new FileReader("e.in"));
		out = new PrintWriter("e.out");
		ExecutorService executor = Executors.newFixedThreadPool(6);
		int testCases = nextInt();
		final Input[] inputs = new Input[testCases];
		for (int i = 0; i < testCases; i++) {
			inputs[i] = new Input();
		}

		@SuppressWarnings("unchecked")
		Future<Output> outputs[] = new Future[testCases];

		for (int i = 0; i < testCases; i++) {
			final int testCase = i;
			outputs[i] = executor.submit(new Callable<Output>() {
				@Override
				public Output call() throws Exception {
					return solveOneTest(inputs[testCase]);
				}
			});
		}

		for (int i = 0; i < testCases; i++) {
			out.print("Case #" + (i + 1) + ": ");
			outputs[i].get().writeOutput();
		}

		out.close();
		executor.shutdown();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}
