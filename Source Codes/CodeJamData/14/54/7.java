import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class D {

	static class Input {
		int n;
		int[] coins;
		int[][] edges;

		Input(InputReader in) throws IOException {
			n = in.nextInt();
			List<Integer>[] edges;
			edges = new List[n];
			coins = new int[n];
			for (int i = 0; i < n; i++) {
				coins[i] = in.nextInt();
				edges[i] = new ArrayList<>();
			}
			for (int i = 0; i < n - 1; i++) {
				int u = i;
				int v = in.nextInt() - 1;
				edges[u].add(v);
				edges[v].add(u);
			}
			int[][] e = new int[n][];
			for (int i = 0; i < n; i++) {
				e[i] = new int[edges[i].size()];
				for (int j = 0; j < edges[i].size(); j++) {
					e[i][j] = edges[i].get(j);
				}
			}
			this.edges = e;
		}

		Output solve() {
			parent = new int[n];
			maxEat = new int[n];
			int[] path = new int[n];
			int[] max1 = new int[n];
			int[] max2 = new int[n];

			int[] sumCoinsPath = new int[n + 1];
			was = new boolean[n];

			int answer = Integer.MIN_VALUE;

			for (int firstChooses = 0; firstChooses < n; firstChooses++) {
				maxEat(firstChooses, -1);
				int curAnswer = Integer.MAX_VALUE;
				parent[firstChooses] = -1;
				dfs0(firstChooses);
				for (int secondChooses = 0; secondChooses < n; secondChooses++) {
					Arrays.fill(was, false);
					int cnt = 0;
					for (int i = secondChooses; i != firstChooses; i = parent[i]) {
						path[cnt++] = i;
						was[i] = true;
					}
					path[cnt++] = firstChooses;
					for (int i = 0, j = cnt - 1; i < j; ++i, --j) {
						int t = path[i];
						path[i] = path[j];
						path[j] = t;
					}
					was[firstChooses] = true;
					sumCoinsPath[0] = 0;
					for (int i = 0; i < cnt; i++) {
						maxEat(path[i], -1);
						sumCoinsPath[i + 1] = sumCoinsPath[i] + coins[path[i]];
						int u = path[i];
						int m1 = 0, m2 = 0;
						for (int v : edges[u]) {
							if (was[v]) {
								continue;
							}
							int cur = maxEat[v];
							if (cur > m1) {
								m2 = m1;
								m1 = cur;
							} else {
								if (cur > m2) {
									m2 = cur;
								}
							}
						}
						max1[i] = m1;
						max2[i] = m2;
					}

					int dpLast;
					if (cnt % 2 == 1) {
						int mid = cnt / 2;
						int firstMan = sumCoinsPath[mid + 1] + max1[mid];
						int secondMan = sumCoinsPath[cnt]
								- sumCoinsPath[mid + 1] + max2[mid];
						dpLast = firstMan - secondMan;
					} else {
						int mid2 = cnt / 2;
						int secondMan = sumCoinsPath[cnt] - sumCoinsPath[mid2]
								+ max1[mid2];
						int firstMan = sumCoinsPath[mid2] + max2[mid2];
						dpLast = secondMan - firstMan;
					}

					for (int stepsMade = cnt - 2; stepsMade >= 0; --stepsMade) {
						int score1 = -dpLast;
						int score2;
						if ((stepsMade & 1) == 0) {
							int ourPos = stepsMade >> 1;
							int us = max1[ourPos] + sumCoinsPath[ourPos + 1];
							int him = 0;
							for (int hisPos = cnt - 1 - (stepsMade >> 1); hisPos > ourPos; --hisPos) {
								him = Math.max(him, sumCoinsPath[cnt]
										- sumCoinsPath[hisPos] + max1[hisPos]);
							}
							him = Math.max(him, sumCoinsPath[cnt]
									- sumCoinsPath[ourPos + 1] + max2[ourPos]);
							score2 = us - him;
						} else {
							int ourPos = cnt - 1 - (stepsMade >> 1);
							int us = max1[ourPos] + sumCoinsPath[cnt]
									- sumCoinsPath[ourPos];
							int him = 0;
							for (int hisPos = stepsMade + 1 >> 1; hisPos < ourPos; hisPos++) {
								him = Math.max(him, sumCoinsPath[hisPos + 1]
										+ max1[hisPos]);
							}
							him = Math.max(him, sumCoinsPath[ourPos]
									+ max2[ourPos]);
							score2 = us - him;
						}
						dpLast = Math.max(score1, score2);
					}
					curAnswer = Math.min(curAnswer, dpLast);
				}
				answer = Math.max(answer, curAnswer);
			}
			return new Output(answer);
		}

		int[] parent;

		void dfs0(int u) {
			for (int v : edges[u]) {
				if (v == parent[u]) {
					continue;
				}
				parent[v] = u;
				dfs0(v);
			}
		}

		int[] maxEat;
		boolean[] was;

		int maxEat(int city, int parent) {
			int answer = 0;
			for (int to : edges[city]) {
				if (to == parent || was[to]) {
					continue;
				}
				answer = Math.max(answer, maxEat(to, city));
			}
			answer += coins[city];
			maxEat[city] = answer;
			return answer;
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
		InputReader in = new InputReader(new FileInputStream("d.in"));
		PrintWriter out = new PrintWriter("d.out");
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