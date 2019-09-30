import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		long A = sc.nextInt();
		long B = sc.nextInt();
		int[] p = new int[N + 1];
		p[N] = N;
		for (int i = 0; i < N; i++) {
			p[i] = sc.nextInt() - 1;
		}
		int[] lessToLeft = new int[N + 1];
		for (int i = 0; i < N + 1; i++) {
			for (int j = i + 1; j < N + 1; j++) {
				if (p[i] < p[j]) lessToLeft[j]++;
			}
		}
		long[] tabla = new long[N + 1];
		for (int i = 0; i <= N; i++) {
			int total = p[i];
			int fromLeft = lessToLeft[i];
			tabla[i] = fromLeft * A + (total - fromLeft) * B;
			int less = 0;
			for (int j = i; j >= 0; j--) if (p[j] < p[i]) {
				total = p[i] - p[j] - 1;
				fromLeft = lessToLeft[i] - lessToLeft[j] - 1 - less;
				tabla[i] = Math.min(tabla[i], tabla[j] + fromLeft * A + (total - fromLeft) * B);
				less++;
			}
		}
		
		out.println(tabla[N]);
		
		out.flush();
	}
	
	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;
		
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}