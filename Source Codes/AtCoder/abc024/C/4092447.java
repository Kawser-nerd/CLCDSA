import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main{
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		int n = sc.nextInt();
		int d = sc.nextInt();
		int k = sc.nextInt();
		int [] l = new int[d];
		int [] r = new int[d];
		for (int i = 0 ; i < d ; i++) {
			l[i] = sc.nextInt();
			r[i] = sc.nextInt();
		}
		int [] s = new int[k];
		int [] t = new int[k];
		for (int i = 0 ; i < k ; i++) {
			s[i] = sc.nextInt();
			t[i] = sc.nextInt();
		}
		for (int i = 0 ; i < k ; i++) {
			int start = s[i];
			int goal = t[i];
			int day = 0;
			if (start < goal) {
				for (int j = 0 ; j < d ; j++) {
					if (l[j] <= start && r[j] >= start) {
						start = r[j];
						if (r[j] >= goal) {
							day = j + 1;
							break;
						}
					}
				}
				pl(day);
			} else {
				for (int j = 0 ; j < d ; j++) {
					if (r[j] >= start && l[j] <= start) {
						start = l[j];
						if (l[j] <= goal) {
							day = j + 1;
							break;
						}
					}
				}
				pl(day);
			}
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
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}
	}
}