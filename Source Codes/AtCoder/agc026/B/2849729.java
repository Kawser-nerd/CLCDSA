import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	
	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			long A = sc.nextLong();
			long B = sc.nextLong();
			long C = sc.nextLong();
			long D = sc.nextLong();
			boolean yes = true;
			if (D < B || A < B) yes = false;
			if (yes && C < B - 1) {
				long gcd = gcd(B, D);
				yes = C >= (A % gcd) + B - gcd;
			}
			out.println(yes ? "Yes" : "No");
		}
		
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