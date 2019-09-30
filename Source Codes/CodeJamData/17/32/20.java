import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class B {

	static final int MAXTIME = 1440;
	static final int DESIRED = MAXTIME / 2;

	public static void main(String... args) throws Exception {
		FastScan sc = new FastScan(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter pw = new PrintWriter(System.out);

		for (int TC = 1, TCC = sc.in(); TC <= TCC; ++TC) {
			int Ac = sc.in(), Aj = sc.in();
			int N = Ac + Aj;
			int[][] regions = new int[N][3];
			for (int i = 0; i < Ac + Aj; ++i) {
				regions[i][0] = sc.in();
				regions[i][1] = sc.in();
				regions[i][2] = i < Ac ? -1 : 1;
			}
			Arrays.sort(regions, (a, b) -> Integer.compare(a[0], b[0]));
			int totalRight = -DESIRED;
			List<Switch> sw = new ArrayList<>(Ac + Aj + 1);
			int prevPerson = regions[N - 1][2];
			int prevTime = regions[N - 1][1] - MAXTIME;
			int switches = 0;
			for (int i = 0; i < Ac + Aj; ++i) {
				int[] cur = regions[i];
				int duration = cur[0] - prevTime;
				boolean different = prevPerson != cur[2];
				sw.add(new Switch(different, -cur[2] * duration));
				if (different)
					switches++;
				if (cur[2] == 1)
					totalRight += cur[1] - prevTime;
				prevTime = cur[1];
				prevPerson = cur[2];
			}

			Collections.sort(sw, (a, b) -> {
				int dif = -Boolean.compare(a.single, b.single);
				if (dif == 0)
					dif = -Integer.compare(Math.abs(a.size), Math.abs(b.size));
				return dif;
			});

			int sign = Integer.signum(totalRight);
			totalRight *= sign;

			// The switches we want to use will be opposite sign to us
			for (Switch s : sw) {
				if (totalRight <= 0)
					break;
				if (Integer.signum(s.size) != -sign)
					continue;
				totalRight += sign * s.size;
				if (!s.single)
					switches += 2;
			}

			pw.printf("Case #%d: %d\n", TC, switches);
		}

		sc.close();
		pw.close();
		System.exit(0);
	}

	static class Switch {
		boolean single;
		int size;

		public Switch(boolean single, int size) {
			super();
			this.single = single;
			this.size = size;
		}

		@Override
		public String toString() {
			return "Switch [single=" + single + ", size=" + size + "]";
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
