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
			int[] E = new int[6];
			int[] L = new int[6];
			for(int i = 0; i < E.length; i++) {
				E[i] = in.nextInt();
			}
			int B = in.nextInt();
			for(int i = 0; i < L.length; i++) {
				L[i] = in.nextInt();
			}
			int count = 0;
			boolean b = false;
			for(int i = 0; i < E.length; i++) {
				for(int j = 0; j < L.length; j++) {
					if(E[i] == L[j]) {
						count++;
					}else if(E[i] != L[j] && L[j] == B) {
						b = true;
					}	
				}
			}
			int ans;
			if(count == 6) {
				ans = 1;
			}else if(count == 5 && b) {
				ans = 2;
			}else if(count == 5) {
				ans = 3;
			}else if(count == 4) {
				ans = 4;
			}else if(count == 3) {
				ans = 5;
			}else{
				ans = 0;
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