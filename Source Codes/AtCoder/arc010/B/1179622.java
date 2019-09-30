import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.time.DayOfWeek;
import java.time.LocalDate;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Set<LocalDate> dates = new HashSet<>();
		for (int i = 0; i < N; i++) {
			String[] d = sc.next().split("/");
			int month = Integer.parseInt(d[0]);
			int day = Integer.parseInt(d[1]);

			dates.add(LocalDate.of(2012, month, day));
		}

		LocalDate current = LocalDate.of(2012, 1, 1);
		int length = 0;
		int carryOver = 0;
		int max = 0;
		for (int i = 0; i < 366; i++) {
			DayOfWeek dow = current.getDayOfWeek();
			if (dow == DayOfWeek.SATURDAY || dow == DayOfWeek.SUNDAY) {
				if (dates.contains(current)) {
					carryOver++;
				}
				length++;
			} else if (dates.contains(current)) {
				length++;
			} else if (carryOver > 0) {
				length++;
				carryOver--;
			} else {
				max = Math.max(length, max);
				length = 0;
			}
			debug(current, max, length);
			current = current.plusDays(1);
		}

		// 12?31??????????????
		max = Math.max(length, max);

		System.out.println(max);
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

			int read = skip();
			do {
				num = num * 10 + (read - 0x30);
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