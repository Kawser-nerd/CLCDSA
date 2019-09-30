import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		char[][] w = new char[N][];
		for (int i = 0; i < w.length; i++) {
			w[i] = sc.next().toLowerCase().toCharArray();
		}

		Map<Character, Character> map = new HashMap<>();
		map.put('b', '1');
		map.put('c', '1');
		map.put('d', '2');
		map.put('w', '2');
		map.put('t', '3');
		map.put('j', '3');
		map.put('f', '4');
		map.put('q', '4');
		map.put('l', '5');
		map.put('v', '5');
		map.put('s', '6');
		map.put('x', '6');
		map.put('p', '7');
		map.put('m', '7');
		map.put('h', '8');
		map.put('k', '8');
		map.put('n', '9');
		map.put('g', '9');
		map.put('z', '0');
		map.put('r', '0');

		List<String> result = new ArrayList<>();
		for (int i = 0; i < w.length; i++) {
			StringBuilder sb = new StringBuilder();
			for (char c : w[i]) {
				Character num = map.get(c);
				if (num != null) {
					sb.append(num);
				}
			}
			if (sb.length() > 0) {
				result.add(sb.toString());
			}
		}

		System.out.println(String.join(" ", result));
	}

	private static boolean isDebug = System.getProperty("sun.desktop") != null;

	private static void debug(Object... o) {
		if (isDebug) {
			System.err.println(Arrays.deepToString(o));
		}
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

			int read = skip();
			do {
				num = num * 10 + (read - 0x30);
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