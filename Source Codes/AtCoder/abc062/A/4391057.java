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
			int x = in.nextInt();
			int y = in.nextInt();
			int[] a = {1, 3, 5, 7, 8, 10, 12};
			int[] b = {4, 6, 9, 11};
			int[] c = {2};
			
			for(int i = 0; i < a.length; i++) {
				if(a[i] == x) {
					x = 100;
				}
				if(a[i] == y) {
					y = 100;
				}
			}
			
			for(int i = 0; i < b.length; i++) {
				if(b[i] == x) {
					x = 200;
				}
				if(b[i] == y) {
					y = 200;
				}
			}
			
			for(int i = 0; i < c.length; i++) {
				if(c[i] == x) {
					x = 300;
				}
				if(c[i] == y) {
					y = 300;
				}
			}
			out.println(x == y ? "Yes" : "No");
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
		
		public char nextChar() {
			return next().charAt(0);
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
}