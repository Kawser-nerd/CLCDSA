import java.io.*;
import java.util.*;
import java.math.*;

public class Treasure implements Runnable {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;
	static Random rnd;

	void solve() throws IOException {
		solveIO();
	}

	private void solveIO() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			String res = solveIOOne();
			out.println("Case #" + (test) + ": " + res);
			out.flush();
		}
	}

	private String solveIOOne() throws IOException {
		int k = nextInt(), n = nextInt();
		int[] initKeys = new int[k];
		for (int i = 0; i < k; i++)
			initKeys[i] = nextInt() - 1;
		int[] needKeys = new int[n];
		int[][] keysInside = new int[n][];
		for (int i = 0; i < n; i++) {
			needKeys[i] = nextInt() - 1;
			keysInside[i] = new int[nextInt()];
			for (int j = 0; j < keysInside[i].length; j++)
				keysInside[i][j] = nextInt() - 1;
		}
		return solveOne(initKeys, needKeys, keysInside);
	}

	final static int maxId = 200;
	static long enters = 0;

	private String solveOne(int[] initKeys, int[] needKeys, int[][] keysInside) {
		if (isBad(initKeys, needKeys, keysInside))
			return "IMPOSSIBLE";

		int[] count = new int[maxId];
		for (int id : initKeys)
			count[id]++;

		int n = needKeys.length;
		Set<Long> cache = new HashSet<Long>();
		int[] tempArray = new int[maxId];
		boolean[] tempArrayBoolean = new boolean[n];

		enters = 0;

		int[] res = rec(0, n, new boolean[n], new int[n], count, needKeys,
				keysInside, cache, tempArray, tempArrayBoolean);

		System.err.println("DEBUG, total iterations: " + enters);
		System.err.flush();

		return (res == null ? "IMPOSSIBLE" : buildAnswer(res));
	}

	private int[] rec(int step, int limit, boolean[] used, int[] history,
			int[] count, int[] needKeys, int[][] keysInside, Set<Long> cache,
			int[] tempArray, boolean[] tempArrayBoolean) {
		++enters;

		// System.err.println("DEBUG, current history: "
		// + Arrays.toString(Arrays.copyOf(history, step)));

		if (step == limit)
			return history;

		if (step != 0)
			if (!touchCache(step, history, cache, tempArray))
				return null;

		if (isBadRemain(used, count, needKeys, keysInside, tempArray,
				tempArrayBoolean))
			return null;

		for (int i = 0; i < limit; i++) {
			if (!used[i] && count[needKeys[i]] > 0) {
				used[i] = true;

				--count[needKeys[i]];
				for (int id : keysInside[i])
					++count[id];

				history[step] = i;

				int[] tryRes = rec(step + 1, limit, used, history, count,
						needKeys, keysInside, cache, tempArray,
						tempArrayBoolean);

				used[i] = false;
				++count[needKeys[i]];
				for (int id : keysInside[i])
					--count[id];

				if (tryRes != null)
					return tryRes;

			}
		}

		return null;
	}

	private boolean isBadRemain(boolean[] used, int[] count, int[] needKeys,
			int[][] keysInside, int[] tempArray, boolean[] tempArrayBoolean) {
		int n = needKeys.length;
		System.arraycopy(used, 0, tempArrayBoolean, 0, n);
		System.arraycopy(count, 0, tempArray, 0, maxId);

		boolean updated = true;
		while (updated) {
			updated = false;
			for (int i = 0; i < n; i++) {
				if (!tempArrayBoolean[i] && tempArray[needKeys[i]] > 0) {
					tempArrayBoolean[i] = true;
					updated = true;
					for (int id : keysInside[i])
						tempArray[id]++;
				}
			}
		}

		for (boolean flag : tempArrayBoolean)
			if (!flag)
				return true;

		return false;
	}

	final static long p = 1000000 + 3;

	private boolean touchCache(int n, int[] history, Set<Long> cache,
			int[] tempArray) {
		long hash = calcHash(n, history, tempArray);

		if (cache.contains(hash))
			return false;

		cache.add(hash);

		return true;
	}

	private long calcHash(int n, int[] history, int[] tempArray) {
		System.arraycopy(history, 0, tempArray, 0, n);
		Arrays.sort(tempArray, 0, n);
		long hash = 0;

		for (int i = 0; i < n; i++)
			hash = (p * hash + tempArray[i] + 1);

		return hash;
	}

	private String buildAnswer(int[] res) {
		int n = res.length;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(res[i] + 1);
			sb.append(i + 1 == n ? "" : " ");
		}
		return sb.toString();
	}

	private boolean isBad(int[] initKeys, int[] needKeys, int[][] keysInside) {
		if (!isEnough(initKeys, needKeys, keysInside))
			return true;
		else if (!canTakeAll(initKeys, needKeys, keysInside))
			return true;

		return false;
	}

	private boolean canTakeAll(int[] initKeys, int[] needKeys,
			int[][] keysInside) {
		int[] count = new int[maxId];
		for (int id : initKeys)
			count[id]++;
		int n = needKeys.length;
		boolean[] taked = new boolean[n];
		boolean updated = true;
		while (updated) {
			updated = false;

			for (int i = 0; i < n; i++) {
				if (!taked[i] && count[needKeys[i]] > 0) {
					taked[i] = true;
					updated = true;
					for (int id : keysInside[i])
						count[id]++;
				}
			}
		}
		for (boolean flag : taked)
			if (!flag)
				return false;
		return true;
	}

	private boolean isEnough(int[] initKeys, int[] needKeys, int[][] keysInside) {
		int[] count = new int[maxId];
		for (int id : initKeys)
			count[id]++;
		for (int[] ids : keysInside)
			for (int id : ids)
				count[id]++;
		for (int id : needKeys)
			count[id]--;
		for (int value : count)
			if (value < 0)
				return false;
		return true;
	}

	public static void main(String[] args) {
		new Treasure().run();
	}

	public void run() {
		try {
			final String className = this.getClass().getName().toLowerCase();

			try {
				in = new BufferedReader(new FileReader(className + ".in"));
				out = new PrintWriter(new FileWriter(className + ".out"));
				// in = new BufferedReader(new FileReader("input.txt"));
				// out = new PrintWriter(new FileWriter("output.txt"));
			} catch (FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}

			rnd = new Random();

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(42);
		}
	}

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null)
				return null;

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