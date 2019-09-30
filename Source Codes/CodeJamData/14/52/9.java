import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class B {

	static class Input {
		int p, q;
		int n;
		int[] hp, gold;

		Input(InputReader in) throws IOException {
			p = in.nextInt();
			q = in.nextInt();
			n = in.nextInt();
			hp = new int[n];
			gold = new int[n];
			for (int i = 0; i < n; i++) {
				hp[i] = in.nextInt();
				gold[i] = in.nextInt();
			}
		}

		Output solve() {
			int maxTurns = 0;
			for (int h : hp) {
				maxTurns += (h + q - 1) / q;
			}
			maxTurns += 10;
			int[][] dp = new int[n + 1][maxTurns];
			for (int[] d : dp) {
				Arrays.fill(d, Integer.MIN_VALUE);
			}
			dp[0][1] = 0;
			for (int killed = 0; killed < n; killed++) {
				for (int weHaveTurns = 0; weHaveTurns < maxTurns; weHaveTurns++) {
					if (dp[killed][weHaveTurns] == Integer.MIN_VALUE) {
						continue;
					}
					int man = hp[killed];
					int hits = (man + q - 1) / q;
					for (int towerHitsMan = 0; towerHitsMan < hits; towerHitsMan++) {
						int weHitToKill = (man - q * towerHitsMan + p - 1) / p;
						if (towerHitsMan + weHaveTurns < weHitToKill) {
							continue;
						}
						int weNowHaveTurns = weHaveTurns + towerHitsMan
								- weHitToKill;
						dp[killed + 1][weNowHaveTurns] = Math.max(
								dp[killed + 1][weNowHaveTurns],
								dp[killed][weHaveTurns] + gold[killed]);
					}
					dp[killed + 1][weHaveTurns + hits] = Math.max(
							dp[killed + 1][weHaveTurns + hits],
							dp[killed][weHaveTurns]);
				}
			}
			long answer = 0;
			for (int i = 0; i < maxTurns; i++) {
				answer = Math.max(answer, dp[n][i]);
			}
			return new Output(answer);
		}
	}

	static class Output {
		long answer;

		public Output(long answer) {
			this.answer = answer;
		}

		void printOutput(PrintWriter out) {
			out.println(answer);
		}
	}

	public static void main(String[] args) throws IOException,
			InterruptedException, ExecutionException {
		InputReader in = new InputReader(new FileInputStream("b.in"));
		PrintWriter out = new PrintWriter("b.out");
		ExecutorService executor = Executors.newFixedThreadPool(4);
		int testCases = in.nextInt();
		final Input[] inputs = new Input[testCases];
		for (int i = 0; i < testCases; i++) {
			inputs[i] = new Input(in);
		}

		@SuppressWarnings("unchecked")
		Future<Output> outputs[] = new Future[testCases];

		for (int i = 0; i < testCases; i++) {
			final int testCase = i;
			outputs[i] = executor.submit(new Callable<Output>() {
				@Override
				public Output call() throws Exception {
					return inputs[testCase].solve();
				}
			});
		}

		for (int i = 0; i < testCases; i++) {
			out.print("Case #" + (i + 1) + ": ");
			outputs[i].get().printOutput(out);
		}

		out.close();
		executor.shutdown();
	}

	static class InputReader {

		InputReader(InputStream input) {
			br = new BufferedReader(new InputStreamReader(input));
		}

		BufferedReader br;
		StringTokenizer st;

		String nextToken() throws IOException {
			while (st == null || !st.hasMoreTokens()) {
				String line = br.readLine();
				if (line == null) {
					return null;
				}
				st = new StringTokenizer(line);
			}
			return st.nextToken();
		}

		int nextInt() throws IOException {
			return Integer.parseInt(nextToken());
		}

		long nextLong() throws IOException {
			return Long.parseLong(nextToken());
		}

		double nextDouble() throws IOException {
			return Double.parseDouble(nextToken());
		}
	}
}