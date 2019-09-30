import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static class TaskF {

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int N = in.nextInt();
			int M = in.nextInt();
			long[] A = new long[N];
			for (int i = 1; i < N; ++i) {
				A[i] = in.nextInt();
			}
			int[][] B = new int[M][N];// (4*N)*(4*M)<=40KB*800B=32MB
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					B[j][i] = in.nextInt();
				}
			}

			int[][] a = new int[N][2];// 4*2*N<=80KB
			int[] mate = new int[N];// 4*N<=40KB
			boolean[] vis = new boolean[N];// 4*N<=40KB

			ArrayList<int[]>[] pq = new ArrayList[N + 1];
			for (int i = 0; i < pq.length; ++i) {
				pq[i] = new ArrayList<>(200);
			}
			for (int i = 0; i < M; ++i) {
				for (int j = 0; j < N; ++j) {
					a[j][0] = j;
					a[j][1] = B[i][j];
				}
				B[i] = null;
				Arrays.sort(a, new Comparator<int[]>() {
					@Override
					public int compare(int[] o1, int[] o2) {
						return Integer.compare(o1[1], o2[1]);
					}
				});
				Arrays.fill(vis, false);
				for (int j = 0; j < N; ++j) {
					mate[j] = j;
				}
				for (int j = 0; j < N; ++j) {
					int idx = a[j][0];
					int l = idx, r = idx;
					if (idx > 0 && vis[idx - 1]) {
						l = mate[idx - 1];
					}
					if (idx + 1 < N && vis[idx + 1]) {
						r = mate[idx + 1];
					}
					pq[l].add(new int[] { idx, a[j][1] });
					pq[idx + 1].add(new int[] { r + 1, a[j][1] });
					pq[l].add(new int[] { r + 1, -a[j][1] });
					pq[idx + 1].add(new int[] { idx, -a[j][1] });
					vis[idx] = true;
					if (idx > 0 && idx + 1 < N && vis[idx - 1] && vis[idx + 1]) {
						mate[l] = r;
						mate[r] = l;
					} else if (idx > 0 && vis[idx - 1]) {
						mate[l] = idx;
						mate[idx] = l;
					} else if (idx + 1 < N && vis[idx + 1]) {
						mate[r] = idx;
						mate[idx] = r;
					}
				}
			}
			long[] sum = new long[N];
			for (int i = 0; i < N; ++i) {
				if (i > 0)
					A[i] += A[i - 1];
			}
			long best = 0;
			long[] lazy = new long[N + 1];
			for (int i = 0; i < N; ++i) {
				Arrays.fill(lazy, 0);
				for (int[] q : pq[i]) {
					lazy[q[0]] += q[1];
				}
				for (int j = i; j < N; ++j) {
					if (j > 0)
						lazy[j] += lazy[j - 1];
					sum[j] += lazy[j];
					best = Math.max(best, sum[j] - (A[j] - A[i]));
				}
			}
			out.println(best);
		}
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	InputStream is;
	PrintWriter out;
	String INPUT = "";

	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.