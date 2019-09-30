import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.stream.Stream;

public class Main {

	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskX solver = new TaskX();
		solver.solve(1, in, out);
		out.close();
	}

	static int INF = 1 << 30;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			P[] ps1 = new P[n];
			for (int i = 0; i < n; i++) {
				ps1[i] = new P(i, in.nextLong(), in.nextLong());
			}

			P[] ps2 = Arrays.copyOf(ps1, n);

			Arrays.sort(ps1, (a,b) -> (int)a.x-(int)b.x);
			Arrays.sort(ps2, (a,b) -> (int)a.y-(int)b.y);

			List<E>[] g = new ArrayList[n];
			g = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);

			for (int i = 0; i < n-1; i++) {
				g[ps1[i].num].add(new E(ps1[i+1].num, Math.abs(ps1[i+1].x-ps1[i].x)));
				g[ps1[i+1].num].add(new E(ps1[i].num, Math.abs(ps1[i+1].x-ps1[i].x)));
			}

			for (int i = 0; i < n-1; i++) {
				g[ps2[i].num].add(new E(ps2[i+1].num, Math.abs(ps2[i+1].y-ps2[i].y)));
				g[ps2[i+1].num].add(new E(ps2[i].num, Math.abs(ps2[i+1].y-ps2[i].y)));
			}

			Set<Integer> mst = new HashSet<>();
			PriorityQueue<E> q = new PriorityQueue<E>((a,b) -> (int)a.c - (int)b.c);

			mst.add(0);
			for (E e : g[0]) {
				q.add(e);
			}

			long ans = 0;
			while (!q.isEmpty()) {
				E edge = q.remove();
				if (mst.contains(edge.t)) {
					continue;
				}
				mst.add(edge.t);
				for (E e : g[edge.t]) {
					q.add(e);
				}
				ans += edge.c;
			}

			out.println(ans);

		}
	}
	static class P{
		int num;
		long x, y;

		public P(int num,long x, long y) {
			super();
			this.num = num;
			this.x = x;
			this.y = y;
		}
	}

	static class E {
		int t;
		long c;

		public E(int t, long c) {
			super();
			this.t = t;
			this.c = c;
		}
	}

	static class InputReader {
		BufferedReader in;
		StringTokenizer tok;

		public String nextString() {
			while (!tok.hasMoreTokens()) {
				try {
					tok = new StringTokenizer(in.readLine(), " ");
				} catch (IOException e) {
					throw new InputMismatchException();
				}
			}
			return tok.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextString());
		}

		public long nextLong() {
			return Long.parseLong(nextString());
		}

		public double nextDouble() {
			return Double.parseDouble(nextString());
		}

		public int[] nextIntArray(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public long[] nextLongArray(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}

	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.