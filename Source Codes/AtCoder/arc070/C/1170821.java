import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class MultiTreeSet {
		private TreeMap<Long, Integer> map = new TreeMap<>();

		int count(long x) {
			return map.getOrDefault(x, 0);
		}

		void add(long x) {
			map.put(x, count(x) + 1);
		}

		void remove(long x) {
			int prev = count(x);
			if (prev == 1) {
				map.remove(x);
			} else {
				map.put(x, prev - 1);
			}
		}

		long getMax() {
			return map.lastKey();
		}

		long getMin() {
			return map.firstKey();
		}

		@Override
		public String toString() {
			return map.toString();
		}

		boolean isEmpty() {
			return map.isEmpty();
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] ls = new int[n];
		int[] rs = new int[n];

		for (int i = 0; i < n; i++) {
			ls[i] = nextInt();
			rs[i] = nextInt();
		}

		int[] minDiff = new int[n - 1];
		int[] maxDiff = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			minDiff[i] = ls[i] - rs[i + 1];
			maxDiff[i] = rs[i] - ls[i + 1];
		}

		MultiTreeSet low = new MultiTreeSet();
		MultiTreeSet high = new MultiTreeSet();

		low.add(0);
		high.add(0);

		long deltaLow = 0;
		long deltaHigh = 0;

		long valMin = 0;

		for (int i = 0; i < n - 1; i++) {
			
			deltaLow += minDiff[i];
			deltaHigh += maxDiff[i];

			long lowMax = low.getMax() + deltaLow;
			long highMin = high.getMin() + deltaHigh;

			if (lowMax >= 0) {
				low.add(-deltaLow);
				low.add(-deltaLow);

				long newLowMax = low.getMax() + deltaLow;

				low.remove(newLowMax - deltaLow);
				high.add(newLowMax - deltaHigh);
			} else {
				high.add(-deltaHigh);
				high.add(-deltaHigh);

				long newHighMin = high.getMin() + deltaHigh;

				high.remove(newHighMin - deltaHigh);
				low.add(newHighMin - deltaLow);
			}

			if (lowMax > 0) {
				valMin += lowMax;
			} else if (highMin < 0) {
				valMin -= highMin;
			}
		}

		long lowMax = low.getMax() + deltaLow;
		long highMin = high.getMin() + deltaHigh;

		out.println(valMin);
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
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