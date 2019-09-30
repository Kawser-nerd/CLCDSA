import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int L = sc.nextInt();
		int N = sc.nextInt();
		int[] right = new int[N];
		int[] left = new int[N];
		for (int i = 0; i < right.length; i++) {
			right[i] = sc.nextInt();
			left[N-1-i] = L - right[i];
		}
		long[] acumR = new long[N+1];
		long[] acumL = new long[N+1];
		for (int i = 0; i < N; i++) {
			acumR[i+1] = acumR[i] + right[i];
			acumL[i+1] = acumL[i] + left[i];
		}
		long ans = Math.max(right[N-1], left[N-1]);
		for (int l = 1; l < N ; l++) {
			int r = N - l;
			int min = Math.min(l, r);
			long value = 0;
			value += 2 * (acumR[r] - acumR[r - min]);
			value += 2 * (acumL[l] - acumL[l - min]);
			value += Math.max(-right[r-1] + 2 * (r > min ? right[r - min - 1] : 0), -left[l-1] + 2 * (l > min ? left[l - min - 1] : 0));
			ans = Math.max(ans, value);
		}
		out.println(ans);
		
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