import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		int N = sc.nextInt();
		int[][] F = new int[N][10];
		int[][] P = new int[N][11];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 10; j++) {
				F[i][j] = sc.nextInt();
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 11; j++) {
				P[i][j] = sc.nextInt();
			}
		}
		long ans = -1000000000;
		for (int i = 1; i < (1 << 10); i++) {
			long bene = 0;
			for (int j = 0; j < N; j++) {
				int cnt = 0;
				for (int k = 0; k < 10; k++) {
					if ((i >> k & 1) == 1 && F[j][k] == 1)
						cnt++;
				}
				bene += P[j][cnt];
			}
			ans = Math.max(ans, bene);
		}
		System.out.println(ans);
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
	}
}