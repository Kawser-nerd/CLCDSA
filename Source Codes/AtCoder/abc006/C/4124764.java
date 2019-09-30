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
			int a = -1;
			int b = -1;
			int c = -1;
			if(M % 2 == 0) {
				for(int i = 0; i <= N; i++) {
					if(2 * i + (4 * (N - i)) == M) {
						a = i;
						b = 0;
						c = N - i;
					}
				}
			}else{
				for(int i = 0; i <= N - 1; i++) {
					if(2 * i + 3 + (4 * (N - 1 - i)) == M) {
						a = i;
						b = 1;
						c = N - 1 - i;
					}
				}
			}
			out.println(a + " " + b + " " + c);
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