import java.io.*;
import java.util.*;
import java.math.*;

import javax.xml.ws.FaultAction;

public class C implements Runnable {
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer st;
	private static Random rnd;

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveOne();
		}
	}

	class Ratio implements Comparable<Ratio> {
		BigInteger top, bottom;

		public Ratio(long top, long bottom) {
			this.top = BigInteger.valueOf(top);
			this.bottom = BigInteger.valueOf(bottom);
		}

		public Ratio(BigInteger top, BigInteger bottom) {
			this.top = top;
			this.bottom = bottom;
		}

		public Ratio add(Ratio other) {
			BigInteger _top = top.multiply(other.bottom).add(
					other.top.multiply(bottom));
			BigInteger _bottom = other.bottom.multiply(bottom);
			return new Ratio(_top, _bottom);
		}

		@Override
		public int compareTo(Ratio other) {
			BigInteger a = top.multiply(other.bottom);
			BigInteger b = other.top.multiply(bottom);
			return a.compareTo(b);
		}

		@Override
		public String toString() {
			return "Ratio [top=" + top + ", bottom=" + bottom + ", ratio="
					+ ((double) top.longValue() / bottom.longValue()) + "]";
		}
	}

	class Biker {
		long startPosition, timeToMakeCircle;

		public Biker(long startPosition, long timeToMakeCircle) {
			this.startPosition = startPosition;
			this.timeToMakeCircle = timeToMakeCircle;
		}

		public Ratio finishTime() {
			final long circleLength = 360;
			return new Ratio(timeToMakeCircle * (circleLength - startPosition),
					circleLength);
		}

		public long getCircles(Ratio targetFinishTime) {
			long l = -1, r = Integer.MAX_VALUE;

			Ratio finishTime = finishTime();

			while (r - l > 1) {
				long m = (l + r) / 2;

				Ratio currentFinishTime = finishTime.add(new Ratio(
						timeToMakeCircle * m, 1));

				int cmp = currentFinishTime.compareTo(targetFinishTime);

				if (cmp == 0)
					throw new AssertionError();

				if (cmp > 0)
					r = m;
				else
					l = m;
			}

			return l;
		}
	}

	private void solveOne() throws IOException {
		List<Biker> bikers = new ArrayList<>();
		int bikerGroupsCount = nextInt();
		for (int i = 0; i < bikerGroupsCount; i++) {
			int startPosition = nextInt();
			int bikersInGroup = nextInt();
			long timeToMakeCircle = nextLong();
			for (int j = 0; j < bikersInGroup; j++) {
				bikers.add(new Biker(startPosition, timeToMakeCircle + j));
			}
		}

		Collections.sort(bikers, new Comparator<Biker>() {
			public int compare(Biker a, Biker b) {
				return -a.finishTime().compareTo(b.finishTime());
			}
		});

		long result = bikers.size();

		Ratio eps = new Ratio(1, 200000000000000L - 1357L);

		for (int fasterCount = 0; fasterCount < bikers.size(); fasterCount++) {
			Ratio targetFinishTime = bikers.get(fasterCount).finishTime()
					.add(eps);

			long currentResult = fasterCount;

			for (int other = fasterCount + 1; other < bikers.size(); other++) {
				Biker otherBiker = bikers.get(other);
				int cmpResult = targetFinishTime.compareTo(otherBiker
						.finishTime());

				if (cmpResult == 0)
					throw new AssertionError();

				if (cmpResult < 0) {
					++currentResult;
				} else {
					currentResult += otherBiker.getCircles(targetFinishTime);
				}
			}

			result = Math.min(result, currentResult);
		}

		out.println(result);
	}

	public static void main(String[] args) {
		new C().run();
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

	private String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null)
				return null;

			st = new StringTokenizer(line);
		}

		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}