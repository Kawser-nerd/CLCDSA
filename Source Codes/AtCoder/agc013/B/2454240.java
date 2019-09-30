import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.InputMismatchException;
import java.util.List;
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
	static int modP = 1000000007;

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt(), m = in.nextInt();
			List<Integer>[] g = new ArrayList[n];
			g = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
			for (int i = 0; i < m; i++) {
				int a = in.nextInt()-1;
				int b = in.nextInt()-1;
				g[a].add(b);
				g[b].add(a);
			}

			int s = 0;
			int t = g[0].get(0);

			Deque<Integer> q = new ArrayDeque<>();
			List<Integer> list1 = new ArrayList<>();
			boolean[] visited = new boolean[n];
			visited[0] = true;
			visited[t] = true;

			q.add(0);
			list1.add(0);

			while (!q.isEmpty()) {
				int f = q.remove();
				for (int i = 0; i < g[f].size(); i++) {
					int to = g[f].get(i);
					if (visited[to]) {
						continue;
					}
					q.add(to);
					list1.add(to);
					visited[to] = true;
					break;
				}
			}

			q = new ArrayDeque<>();
			List<Integer> list2 = new ArrayList<>();
			q.add(t);
			list2.add(t);

			while (!q.isEmpty()) {
				int f = q.remove();
				for (int i = 0; i < g[f].size(); i++) {
					int to = g[f].get(i);
					if (visited[to]) {
						continue;
					}
					q.add(to);
					list2.add(to);
					visited[to] = true;
					break;
				}
			}

			Collections.reverse(list1);
			list1.addAll(list2);

			out.println(list1.size());
			for (int i = 0; i < list1.size(); i++) {
				if (i == 0) {
					out.print(list1.get(i)+1);
				} else {
					out.print(" "+(list1.get(i)+1));
				}
			}
			out.print("\n");
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