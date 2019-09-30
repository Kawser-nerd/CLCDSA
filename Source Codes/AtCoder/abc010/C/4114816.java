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
			int txa = in.nextInt();
			int tya = in.nextInt();
			int txb = in.nextInt();
			int tyb = in.nextInt();
			int T = in.nextInt();
			int Y = in.nextInt();
			int n = in.nextInt();
			int x, y;
			double tmp1, tmp2;
			String ans = "NO";
			for(int i = 0; i < n; i++) {
				x = in.nextInt();
				y = in.nextInt();
				tmp1 = Math.sqrt(Math.pow(x - txa, 2)  + Math.pow(y - tya, 2));
				tmp2 = Math.sqrt(Math.pow(txb - x, 2)  + Math.pow(tyb - y, 2));
				if(tmp1 + tmp2 <= T * Y) {
					ans = "YES";
					break;
				}
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

	}
}