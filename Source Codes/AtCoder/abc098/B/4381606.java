import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
			int    N = in.nextInt();
			String S = in.next();
			int[] X = new int[26];
			int[] Y = new int[26];
			int ans   = 0;
			
			for(int i = 1; i < N - 1; i++) {
				int count = 0;
				for(int j = 0; j < i; j++) {
					X[S.charAt(j)-97]++;
				}
				for(int j = i; j < N; j++) {
					Y[S.charAt(j)-97]++;
				}
				for(int j = 0; j < 26; j++) {
					if(0 < X[j] && 0 < Y[j]) {
						count++;
					}
					X[j] = 0;
					Y[j] = 0;
				}
				ans = Math.max(ans, count);
			}
			out.println(ans);
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
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
}