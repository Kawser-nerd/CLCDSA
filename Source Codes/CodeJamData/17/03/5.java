import java.io.*;
import java.util.*;

public class C2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastScanner input = new FastScanner();
		int n = input.nextInt();
		for (int x = 0; x < n; x++) {
			long k2 = input.nextLong();
			long k = input.nextLong();

			TreeMap<Long, Long> queue = new TreeMap<Long, Long>();
			queue.put(k2, 1l);
			long startCount = 0;
			long prevDist = -1;
			while (true) {
				long dist = queue.lastKey();
				prevDist = dist;
				long freq = queue.lastEntry().getValue();
				startCount += freq;
				if (startCount >= k) {
					break;
				}
				queue.remove(dist);

				insert(queue, (dist - 1) / 2, freq);
				insert(queue, ((dist - 1) / 2) + ((dist - 1) % 2), freq);

			}

			long left = (prevDist - 1) / 2;
			long right = ((prevDist - 1) / 2) + ((prevDist - 1) % 2);

			System.out.println("Case #" + (x + 1) + ": " + Math.max(left, right) + " " + Math.min(left, right));
		}
	}

	private static void insert(TreeMap<Long, Long> queue, long l, long freq) {
		// TODO Auto-generated method stub
		if (!queue.containsKey(l)) {
			queue.put(l, (long) 0);
		}
		queue.put(l, queue.get(l) + freq);
	}

	public static class Range implements Comparable<Range> {
		long dist;

		public Range(long _dist) {
			dist = _dist;
		}

		@Override
		public int compareTo(Range arg0) {
			return -1 * Long.compare(dist, dist);
		}

	}

	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(Reader in) {
			br = new BufferedReader(in);
		}

		public FastScanner() {
			this(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String readNextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

		int[] readIntArray(int n) {
			int[] a = new int[n];
			for (int idx = 0; idx < n; idx++) {
				a[idx] = nextInt();
			}
			return a;
		}

		long[] readLongArray(int n) {
			long[] a = new long[n];
			for (int idx = 0; idx < n; idx++) {
				a[idx] = nextLong();
			}
			return a;
		}
	}
}
