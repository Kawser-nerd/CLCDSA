import java.io.*;
import java.util.*;

public class A {

	static void solveMultiTest() throws IOException {
		int testCases = nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			out.print("Case #" + testCase + ": ");
			solveOneTest();
		}
	}

	static final int MOD = 1000002013;

	static void solveOneTest() throws IOException {
		int n = nextInt();
		int edges = nextInt();
		int[] from = new int[edges];
		int[] to = new int[edges];
		int[] count = new int[edges];
		NavigableMap<Integer, Long> events = new TreeMap<>();

		long originalCost = 0;
		for (int i = 0; i < edges; i++) {
			from[i] = nextInt();
			to[i] = nextInt();
			count[i] = nextInt();
			add(events, from[i], count[i]);
			add(events, to[i], -count[i]);
			originalCost += getCost(from[i], to[i], count[i], n);
		}
		originalCost %= MOD;

		long theirCost = getCost(events, n);

		long answer = originalCost - theirCost;
		answer = (answer % MOD + MOD) % MOD;
		out.println(answer);
	}

	private static long getCost(NavigableMap<Integer, Long> events, int n) {
		List<Pair> stack = new ArrayList<>();

		long answer = 0;
		for (Map.Entry<Integer, Long> entry : events.entrySet()) {
			long ok = entry.getValue();
			if (ok > 0) {
				stack.add(new Pair(entry.getKey(), entry.getValue()));
			} else {
				int where = entry.getKey();
				ok = -ok;
				while (ok > 0) {
					Pair pair = stack.remove(stack.size() - 1);
					if (pair.value <= ok) {
						ok -= pair.value;
						answer += getCost(pair.key, where, pair.value, n);
					} else {
						answer += getCost(pair.key, where, ok, n);
						pair.value -= ok;
						stack.add(pair);
						ok = 0;
					}
				}
			}
		}
		if (!stack.isEmpty()) {
			throw new AssertionError();
		}
		return answer % MOD;
	}

	static class Pair {
		int key;
		long value;

		public Pair(int key, long value) {
			this.key = key;
			this.value = value;
		}
	}

	private static long getCost(int from, int to, long mul, int n) {
		mul %= MOD;
		int d = to - from;
		long answer = (n + n - d + 1L) * (long) d / 2;
		answer = answer % MOD * mul % MOD;

		return answer;
	}

	private static void add(Map<Integer, Long> balance, int key, int add) {
		Long have = balance.get(key);
		if (have == null) {
			have = 0L;
		}
		balance.put(key, have + add);
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("a.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream(new File("a.out"));
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solveMultiTest();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

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

}
