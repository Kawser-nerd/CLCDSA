import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String args[]){
		SC sc = new SC(System.in);
		int N = sc.nextInt();
		double[] coin = new double[N];
		for (int i = 0; i < N; i++) {
			coin[i] = sc.nextDouble();
		}
		Arrays.sort(coin);
		double sum = 0;
		for (int i = 0; i < N; i++) {
			double tmp = 0;
			for (int j = 0; j < N; j++) {
				if (i != j && coin[i] % coin[j] == 0) {
					tmp = tmp + 1;
				}
			}
			if (tmp % 2 == 0) {
				sum += (tmp + 2)/(2*tmp +2);
			} else {
				sum += 1.0/2.0;
			}
		}
		pl(sum);
	}
	static class SC {
		private BufferedReader reader = null;
		private StringTokenizer tokenizer = null;
		public SC(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
		}
		public String next() {
			if (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new UncheckedIOException(e);
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
		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
}