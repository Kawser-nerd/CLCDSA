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
			int N = in.nextInt();
			int[] count = new int[5];
			String str = in.next();
			for(int i = 0; i < N; i++) {
				switch(str.charAt(i)) {
				case '1':
					count[1]++;
					break;
				case '2':
					count[2]++;
					break;
				case '3':
					count[3]++;
					break;
				case '4':
					count[4]++;
					break;
				}
			}
			int max = count[1];
			int min = count[1];
			for(int i = 2; i <= 4; i++) {
				max = Math.max(max, count[i]);
				min = Math.min(min, count[i]);
			}
			out.println(max + " " + min);
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