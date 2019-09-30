import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;

public class Main {

	private static final int MOD = 1000000007;

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] p = new int[N];
		for (int i = 0; i < N; i++) {
			p[i] = sc.nextInt() - 1;
		}

		int[] a = new int[N];
		int[] b = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = i + 1;
			b[i] = N - i;
		}

		int prev = a[p[0]] + b[p[0]];
		for (int i = 1; i < N; i++) {
			int index = p[i];

			int plus = prev - (a[index] + b[index]) + 1;
			for (int j = index; j < N; j++) {
				a[j] += plus;
			}
			for (int j = 0; j <= index; j++) {
				b[j] += plus;
			}

			// System.err.println(prev + ", " + plus);

			prev = a[index] + b[index];

			// System.err.println(Arrays.toString(a));
			// System.err.println(Arrays.toString(b));
			// System.err.println();
		}

		StringBuilder builder = new StringBuilder();
		for (int i = 0; i < N; i++) {
			builder.append(a[i]);
			builder.append(' ');
		}
		builder.deleteCharAt(builder.length() - 1);
		builder.append(System.lineSeparator());

		for (int i = 0; i < N; i++) {
			builder.append(b[i]);
			builder.append(' ');
		}
		builder.deleteCharAt(builder.length() - 1);
		builder.append(System.lineSeparator());

		System.out.print(builder.toString());

	}

	public static class Scanner {
		private BufferedInputStream inputStream;

		public Scanner(InputStream in) {
			inputStream = new BufferedInputStream(in);
		}

		public int nextInt() throws IOException {
			int num = 0;
			int sign = 1;

			int read = skip();
			if (read == '-') {
				sign = -1;
				read = inputStream.read();
			}

			do {
				num = num * 10 + sign * (read - 0x30);
			} while ((read = inputStream.read()) > 0x20);

			return num;
		}

		public void fill(int[] a) throws IOException {
			for (int i = 0; i < a.length; i++) {
				a[i] = nextInt();
			}
		}

		public void fill(int[] a, int[] b) throws IOException {
			if (a.length != b.length) {
				throw new IllegalArgumentException();
			}

			for (int i = 0; i < a.length; i++) {
				a[i] = nextInt();
				b[i] = nextInt();
			}
		}

		public long nextLong() throws IOException {
			long num = 0;
			int sign = 1;

			int read = skip();
			if (read == '-') {
				sign = -1;
				read = inputStream.read();
			}

			do {
				num = num * 10 + sign * (read - 0x30);
			} while ((read = inputStream.read()) > 0x20);

			return num;
		}

		public void fill(long[] a) throws IOException {
			for (int i = 0; i < a.length; i++) {
				a[i] = nextLong();
			}
		}

		public void fill(long[] a, long[] b) throws IOException {
			if (a.length != b.length) {
				throw new IllegalArgumentException();
			}

			for (int i = 0; i < a.length; i++) {
				a[i] = nextLong();
				b[i] = nextLong();
			}
		}

		public long[] nextLong(int n) throws IOException {
			long[] array = new long[n];
			for (int i = 0; i < n; i++) {
				array[i] = nextLong();
			}

			return array;
		}

		public String next() throws IOException {
			StringBuilder builder = new StringBuilder();

			int read = skip();
			do {
				builder.append((char) read);
			} while ((read = inputStream.read()) > 0x20);

			return builder.toString();
		}

		private int skip() throws IOException {
			int read;
			while ((read = inputStream.read()) <= 0x20)
				;

			return read;
		}
	}
}