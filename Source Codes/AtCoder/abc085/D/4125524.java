import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in Actual solution is at the top
 */

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}

	static class Task {
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int N = in.nextInt();
			int M = in.nextInt();
			Integer[] a = new Integer[N];
			Integer[] b = new Integer[N];
			for(int i = 0; i < N; i++) {
				a[i] = in.nextInt();
				b[i] = in.nextInt();
			}
			Arrays.sort(a, Comparator.reverseOrder());
			Arrays.sort(b, Comparator.reverseOrder());
			int count = 0;
			for(int i = 0; i < N; i++) {
				if(b[i] <= a[0]) {
					break;
				}
				count++;
				M -= b[i];
				if(M <= 0) {
					break;
				}
			}
			while(M > 0) {
				M -= a[0];
				count++;
			}
			out.println(count);
			}
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
}