import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;

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
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int R = in.nextInt(), C = in.nextInt(), K = in.nextInt();
			int N = in.nextInt();
			int[] S = new int[N], T = new int[N];
			int[] H = new int[R], W = new int[C];
			for (int i = 0; i < N; i++) {
				S[i] = in.nextInt();
				T[i] = in.nextInt();
				H[S[i]-1]++;
				W[T[i]-1]++;
			}

			Map<Integer, Integer> mapH = new HashMap<>();
			Map<Integer, Integer> mapW = new HashMap<>();

			for (int i = 0; i < R; i++) {
				mapH.merge(H[i], 1, Integer::sum);
			}
			for (int i = 0; i < C; i++) {
				mapW.merge(W[i], 1, Integer::sum);
			}

			long ans = 0;

			for (Entry<Integer, Integer> entry : mapH.entrySet()) {
				int key = entry.getKey();
				if (mapW.containsKey(K - key)) {
					ans += entry.getValue() * mapW.get(K - key);
				}
			}

			for (int i = 0; i < N; i++) {
				if (H[S[i]-1]+W[T[i]-1] == K) ans--;
				if (H[S[i]-1]+W[T[i]-1] == K+1) ans++;
			}

			out.println(ans);

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

}