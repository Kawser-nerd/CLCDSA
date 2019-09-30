import static java.lang.System.out;

import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;

class LibraryA {
	final static Scanner sc = new Scanner(System.in);

	static String ns() {
		return sc.next();
	}

	static long nl() {
		return sc.nextLong();
	}

	static int ni() {
		return sc.nextInt();
	}

	static String[] ns(int size) {
		String[] array = new String[size];
		for (int i = 0; i < size; i++)
			array[i] = sc.next();
		return array;
	}

	static long[] nl(int size) {
		long[] array = new long[size];
		for (int i = 0; i < size; i++)
			array[i] = sc.nextLong();
		return array;
	}

	static int[] ni(int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = sc.nextInt();
		return array;
	}

	static long gcd(long a, long b) {
		if (a < 0)
			a = -a;
		if (b < 0)
			b = -b;
		while (b != 0) {
			long t = b;
			b = a % b;
			a = t;
		}
		return a;
	}

	static int gcd(int a, int b) {
		if (a < 0)
			a = -a;
		if (b < 0)
			b = -b;
		while (b != 0) {
			int t = b;
			b = a % b;
			a = t;
		}
		return a;
	}

	static void swap(long[] array, int a, int b) {
		long m = array[a];
		array[a] = array[b];
		array[b] = m;
	}

	static void swap(int[] array, int a, int b) {
		int m = array[a];
		array[a] = array[b];
		array[b] = m;
	}

	static Iterable<Integer> range(final int end) {
		return range(0, end);
	}

	static Iterable<Integer> range(final int begin, final int end) {
		return new Iterable<Integer>() {
			@Override
			public Iterator<Integer> iterator() {
				return new Iterator<Integer>() {
					int i = begin;

					@Override
					public boolean hasNext() {
						return i < end;
					}

					@Override
					public Integer next() {
						return i++;
					}

					@Override
					public void remove() {
					}
				};
			}
		};
	}

	static int[] __tmp;

	static boolean nextperm(int[] cur) {
		int pos = cur.length - 2;
		while (cur[pos] > cur[pos + 1]) {
			pos--;
			if (pos < 0)
				return false;
		}

		int maxVal = cur[pos + 1];
		int i = pos + 1;

		if (__tmp == null || __tmp.length < cur.length)
			__tmp = new int[cur.length];
		else
			Arrays.fill(__tmp, 0);

		__tmp[cur[pos]] = 1;
		while (i != cur.length) {
			__tmp[cur[i]] = 1;
			if (cur[i] > cur[pos] && cur[i] < maxVal) {
				maxVal = cur[i];
			}
			i++;
		}
		cur[pos++] = maxVal;
		__tmp[maxVal] = 0;

		for (i = 0; i < cur.length; i++)
			if (__tmp[i] == 1) {
				cur[pos++] = i;
				__tmp[i] = 0;
			}
		return true;
	}

	static void print(int[] array) {
		for (int a : array) {
			out.print(" ");
			out.print(a);
		}
		out.println();
	}

	static void print(long[] array) {
		for (long a : array) {
			out.print(" ");
			out.print(a);
		}
		out.println();
	}
}

public class A extends LibraryA {
	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++)
			main(t);
	}

	public static void main(int testCase) {
		int r = ni(), c = ni();
		char[][] m = new char[r][];
		for (int i = 0; i < r; i++)
			m[i] = ns().toCharArray();

		boolean possible = true;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				if (m[i][j] != '#')
					continue;
				if (i + 1 < r && j + 1 < c && m[i][j + 1] == '#' && m[i + 1][j + 1] == '#'
						&& m[i + 1][j] == '#') {
					m[i][j] = '/';
					m[i][j + 1] = '\\';
					m[i + 1][j] = '\\';
					m[i + 1][j + 1] = '/';
				} else {
					possible = false;
					break;
				}
			}

		out.printf("Case #%s:\n", testCase);
		if (!possible)
			out.printf("Impossible\n");
		else {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++)
					out.print(m[i][j]);
				out.println();
			}
		}
	}
}