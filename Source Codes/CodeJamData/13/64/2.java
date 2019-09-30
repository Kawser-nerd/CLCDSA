import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class D {

	static Output solveOneTest(Input input) {
		return input.solve();
	}

	static class Input {
		int n, d;
		int k;
		int[][] rolls;

		Input() throws IOException {
			n = nextInt();
			d = nextInt();
			k = nextInt();
			rolls = new int[n][d];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < d; j++) {
					rolls[i][j] = nextInt();
				}
			}
		}

		int bestSegment;

		MyBitset[] bitsetForLevel;
		Map<Integer, MySet> setForValue;

		Output solve() {
			bestSegment = 0;
			Map<Integer, Integer> valueCount = new HashMap<>();
			Set<Integer> curSet = new HashSet<>();
			for (int i = 0; i < n; i++) {
				curSet.clear();
				for (int j = 0; j < d; j++) {
					int value = rolls[i][j];
					curSet.add(value);
				}
				for (Integer value : curSet) {
					Integer have = valueCount.get(value);
					if (have == null) {
						have = 0;
					}
					valueCount.put(value, have + 1);
				}
			}
			setForValue = new HashMap<Integer, MySet>();
			final int SMALL = 300;
			for (Map.Entry<Integer, Integer> entry : valueCount.entrySet()) {
				if (entry.getValue() < SMALL) {
					setForValue.put(entry.getKey(),
							new MyStupidSet(entry.getValue()));
				} else {
					setForValue.put(entry.getKey(), new MyBitset(n));
				}
			}
			for (int i = 0; i < n; i++) {
				curSet.clear();
				for (int j = 0; j < d; j++) {
					int value = rolls[i][j];
					curSet.add(value);
				}
				for (Integer value : curSet) {
					MySet set = setForValue.get(value);
					set.add(i);
				}
			}
			bitsetForLevel = new MyBitset[k + 1];
			for (int i = 0; i <= k; i++) {
				bitsetForLevel[i] = new MyBitset(n);
			}
			int bestAnswer = 0;
			int bestStart = 0, bestEnd = 0;
			for (int startPosition = 0; startPosition < n; startPosition++) {
				Set<Integer> set = new HashSet<>();
				for (int i : rolls[startPosition]) {
					set.add(i);
				}
				if (startPosition > 0) {
					for (int i : rolls[startPosition - 1]) {
						set.remove(i);
					}
				}
				for (int value : set) {
					setForValue.get(value).orWith(bitsetForLevel[k],
							bitsetForLevel[k - 1]);
					int endPosition = go(k - 1, startPosition);
					if (endPosition - startPosition > bestAnswer) {
						bestAnswer = endPosition - startPosition;
						bestStart = startPosition;
						bestEnd = endPosition;
					}
				}
			}
			return new Output(bestStart, bestEnd-1);
		}

		private int go(int level, int startPosition) {
			startPosition = bitsetForLevel[level].nextUnsetBit(startPosition);
			if (level == 0 || startPosition >= n) {
				return startPosition;
			}
			int best = 0;
			for (int value : rolls[startPosition]) {
				MySet mySet = setForValue.get(value);
				mySet.orWith(bitsetForLevel[level], bitsetForLevel[level - 1]);
				best = Math.max(best, go(level - 1, startPosition));
			}
			return best;
		}
	}

	static interface MySet {
		void add(int element);

		void orWith(MyBitset with, MyBitset result);
	}

	static class MyStupidSet implements MySet {
		int[] listOfValues;
		int size;

		MyStupidSet(int capacity) {
			listOfValues = new int[capacity];
			size = 0;
		}

		@Override
		public void add(int element) {
			listOfValues[size++] = element;
		}

		@Override
		public void orWith(MyBitset with, MyBitset result) {
			if (size != listOfValues.length) {
				throw new AssertionError();
			}
			result.set(with);
			for (int value : listOfValues) {
				result.add(value);
			}
		}

	}

	static class MyBitset implements MySet {
		int n;
		long[] values;

		MyBitset(int n) {
			this.n = n;
			values = new long[(n + 63) >> 6];
		}

		void clear() {
			Arrays.fill(values, 0);
		}

		void set(MyBitset bitSet) {
			System.arraycopy(bitSet.values, 0, values, 0, bitSet.values.length);
		}

		public int nextUnsetBit(int startPosition) {
			while ((startPosition & 63) != 0) {
				if (!get(startPosition)) {
					return startPosition;
				}
				startPosition++;
			}
			while (startPosition < n && values[startPosition >> 6] == -1) {
				startPosition += 64;
			}
			while (startPosition < n && get(startPosition)) {
				startPosition++;
			}
			return startPosition;
		}

		public boolean get(int index) {
			return (values[index >> 6] & (1L << index)) != 0;
		}

		@Override
		public void add(int element) {
			values[element >> 6] |= 1L << element;
		}

		@Override
		public void orWith(MyBitset with, MyBitset result) {
			for (int i = 0; i < values.length; i++) {
				result.values[i] = values[i] | with.values[i];
			}
		}
	}

	static class Output {
		public Output(int answerStart, int answerEnd) {
			this.answerStart = answerStart;
			this.answerEnd = answerEnd;
		}

		int answerStart, answerEnd;

		void writeOutput() {
			out.println(answerStart+" "+answerEnd);
		}
	}

	public static void main(String[] args) throws IOException,
			InterruptedException, ExecutionException {
		br = new BufferedReader(new FileReader("d-large.in"));
		out = new PrintWriter("d.out");
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
