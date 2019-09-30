import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int[] vals;
	static int M, N;
	
	static int sumLeft(int pairs) {
		int ret = 0;
		for (int i = 0; i < pairs; i++) {
			ret = Math.max(ret, vals[i] + vals [2 * pairs - 1 - i]);
		}
		return ret;
	}
	
	static int sumRight(int pairs) {
		int rem = N - pairs;
		int ret = 0;
		for (int i = 0; i < rem; i++) {
			int sum = vals[2 * N - 1 - i] + vals[2 * pairs + i] - M;
			if (sum < 0) return M;
			ret = Math.max(ret, sum);
		}
		return ret;
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		N = sc.nextInt();
		M = sc.nextInt();
		vals = new int[2 * N];
		for (int i = 0; i < vals.length; i++) {
			vals[i] = sc.nextInt();
		}
		Arrays.sort(vals);
		int left = -1, right = N;
		while (left + 1 < right) {
			int med = (left + right) / 2;
			if (sumRight(med) < M) {
				right = med;
			} else {
				left = med;
			}
		}
		int ans = Math.max(sumLeft(right), sumRight(right));
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