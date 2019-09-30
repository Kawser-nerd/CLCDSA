import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class A {

	static Output solveOneTest(Input input) {
		return input.solve();
	}

	static class Input {
		int cars;
		long x, n;
		long[] start, end;
		long[] time;

		Input() throws IOException {
			cars = nextInt();
			x = nextLong();
			n = nextLong();
			start = new long[cars];
			end = new long[cars];
			time = new long[cars];
			for (int i = 0; i < cars; i++) {
				start[i] = nextLong() - 1;
				end[i] = nextLong() - 1;
				time[i] = nextLong();
			}
		}

		Output solve() {
			long bestTime = 0;
			if (cars == 0) {
				bestTime = x;
			}
			for (long time = 0; time <= x; time++) {
				for (long pos = 0; pos < n; pos++) {
					bestTime = Math.max(bestTime, drive(pos, time));
				}
			}
//			for (int carMissed = 0; carMissed < cars; carMissed++) {
//				{
//					long possiblePosition = (start[carMissed] + n - 1) % n;
//					long possibleTime = time[carMissed];
//					long curTime = drive(possiblePosition, possibleTime);
//					bestTime = Math.max(bestTime, curTime);
//				}
//				{
//					long possiblePosition = start[carMissed];
//					long possibleTime = time[carMissed] + 1;
//					long curTime = drive(possiblePosition, possibleTime);
//					bestTime = Math.max(bestTime, curTime);
//				}
//				long travelTime = end[carMissed] - start[carMissed];
//				if (travelTime < 0) {
//					travelTime += n;
//				}
//				{
//					long possiblePosition = (end[carMissed] + 1) % n;
//					long possibleTime = time[carMissed] + travelTime;
//					long curTime = drive(possiblePosition, possibleTime);
//					bestTime = Math.max(bestTime, curTime);
//				}
//				{
//					long possiblePosition = end[carMissed];
//					long possibleTime = time[carMissed] + 1 + travelTime;
//					long curTime = drive(possiblePosition, possibleTime);
//					bestTime = Math.max(bestTime, curTime);
//				}
//			}
			return new Output(bestTime);
		}

		private long drive(long possiblePosition, long possibleTime) {
			if (possibleTime < 0) {
				possiblePosition = (possiblePosition + possibleTime) % n;
				if (possiblePosition < 0) {
					possiblePosition += n;
				}
				possibleTime = 0;
			}
			long live = Math.max(x - possibleTime, 0);
			// System.err.println(possiblePosition + " " + possibleTime
			// + " - possible start");
			for (int car = 0; car < cars; car++) {
				long currentLive = timeWhenCollisionHappens(possiblePosition,
						possibleTime, start[car], end[car], time[car]) - possibleTime;
				live = Math.min(live, currentLive);
			}
			return live;
		}

		private long timeWhenCollisionHappens(long possiblePosition,
				long possibleTime, long start, long end, long timeStart) {
			if (possibleTime > x) {
				return possibleTime;
			}
			long timeEnd;
			{
				long travelTime = end - start;
				if (travelTime < 0) {
					travelTime += n;
				}
				timeEnd = timeStart + travelTime;
			}

			if (possibleTime > timeEnd) {
				return x;
			}
			if (possibleTime > timeStart) {
				start = (start + possibleTime - timeStart) % n;
				timeStart = possibleTime;
			}

			long posAtTimeStart = (possiblePosition - (timeStart - possibleTime))
					% n;
			if (posAtTimeStart < 0) {
				posAtTimeStart += n;
			}
			possibleTime = timeStart;

			long distance = (posAtTimeStart - start);
			if (distance < 0) {
				distance += n;
			}
			// System.err.println("here " + distance + "; " + timeStart + ", "
			// + timeEnd + "; " + posAtTimeStart + " " + start);

			if (distance > 2 * (timeEnd - timeStart)) {
				return x;
			} else {
				if (distance == 0) {
					return timeStart - 1;
				}
				return timeStart + (distance - 1) / 2;
			}
		}
	}

	static class Output {
		long time;

		public Output(long time) {
			this.time = time;
		}

		void writeOutput() {
			out.println(time);
		}
	}

	public static void main(String[] args) throws IOException,
			InterruptedException, ExecutionException {
		br = new BufferedReader(new FileReader("a.in"));
		out = new PrintWriter("a.out");
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
