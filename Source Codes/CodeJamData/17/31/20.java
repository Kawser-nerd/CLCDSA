import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class A {

	public static void main(String... args) throws Exception {
		FastScan sc = new FastScan(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter pw = new PrintWriter(System.out);

		for (int TC = 1, TCC = sc.in(); TC <= TCC; ++TC) {
			int N = sc.in();
			int K = sc.in();

			Pancake[] pancakes = new Pancake[N];
			for (int i = 0; i < N; ++i) {
				pancakes[i] = new Pancake(sc.ln(), sc.ln());
			}

			Arrays.sort(pancakes, (a, b) -> Long.compare(a.radius, b.radius));

			Queue<Pancake> best = new PriorityQueue<>(K, (a, b) -> {
				int dif = Long.compare(a.sideArea, b.sideArea);
				if (dif == 0)
					dif = Long.compare(a.radius, b.radius);
				return dif;
			});

			long sideArea = 0;
			for (int i = 0; i < K - 1; ++i) {
				best.add(pancakes[i]);
				sideArea += pancakes[i].sideArea;
			}

			long bestArea = 0;
			for (int i = K - 1; i < N; ++i) {
				sideArea += pancakes[i].sideArea;
				bestArea = Math.max(sideArea + pancakes[i].topArea, bestArea);
				best.add(pancakes[i]);
				sideArea -= best.poll().sideArea;
			}

			pw.printf("Case #%d: %.9f\n", TC, bestArea * Math.PI);
		}

		sc.close();
		pw.close();
		System.exit(0);
	}

	static class Pancake {
		long radius;
		long height;
		long sideArea;
		long topArea;

		public Pancake(long radius, long height) {
			super();
			this.radius = radius;
			this.height = height;
			sideArea = radius * height * 2;
			topArea = radius * radius;
		}

	}

	static class FastScan implements Closeable {
		private BufferedReader br;
		private StringTokenizer tk;

		public FastScan(BufferedReader br) {
			this.br = br;
		}

		public int in() throws NumberFormatException, IOException {
			return Integer.parseInt(next());
		}

		public long ln() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

		public double db() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}

		@Override
		public void close() throws IOException {
			tk = null;
			br.close();
		}

		public String next() throws IOException {
			while (tk == null || !tk.hasMoreTokens()) {
				String line = br.readLine();
				if (line == null)
					return null;
				tk = new StringTokenizer(line);
			}
			return tk.nextToken();
		}
	}
}
