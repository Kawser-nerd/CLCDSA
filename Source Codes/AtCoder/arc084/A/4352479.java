import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskA {
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int N = in.nextInt();
			int[] A = new int[N];
			int[] B = new int[N];
			int[] C = new int[N];
			for(int i = 0; i < N; i++) {
				A[i] = in.nextInt();
			}
			for(int i = 0; i < N; i++) {
				B[i] = in.nextInt();
			}
			for(int i = 0; i < N; i++) {
				C[i] = in.nextInt();
			}
			Arrays.sort(A);
			Arrays.sort(C);
			
			long ans = 0L;
			for (int i=0; i < N; i++) {
				long a = binarySearchLB(A, B[i]);
				long c = binarySearchUB(C, B[i]);
				c = N - c;
				ans += a * c;
			}
			out.println(ans);
		}
	}
	
	static int binarySearchLB (int[] ar, int t) {
		int L = 0;
		int R = ar.length;
		while (L < R) {
			int M = (L+R) / 2;
			if (t <= ar[M]) R = M;
			else L = M+1;
		}
		return L;
	}
 
	static int binarySearchUB (int[] ar, int t) {
		int L = 0;
		int R = ar.length;
		while (L < R) {
			int M = (L+R) / 2;
			if (t >= ar[M]) L = M+1;
			else R = M;
		}
		return L;
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