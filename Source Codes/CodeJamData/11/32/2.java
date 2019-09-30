import static java.lang.System.out;

import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;

class LibraryB {
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

public class B extends LibraryB {
	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++)
			main(t);
	}

	static long simulate(int stars, int[] dist, long btime, int a, int b) {
		long time = 0;
		int i = 0;
		while (i < stars) {
			if (i == a || i == b) {
				if (btime <= time) {
					time += dist[i % dist.length];
				} else if (btime <= time + dist[i % dist.length] * 2) {
					long ttb = btime - time;
					long d = ttb / 2;
					time += ttb + (dist[i % dist.length] - d);
				} else {
					time += dist[i % dist.length] * 2;
				}
			} else {
				time += dist[i % dist.length] * 2;
			}
			i++;
		}
		//out.printf("boosters %s %s, time %s\n", a, b, time);
		return time;
	}

	public static void main(int testCase) {
		int boosters = ni();
		long btime = nl();
		int stars = ni();
		int d = ni();
		int[] dist = ni(d);

		long time = Long.MAX_VALUE;

		//for (int i = 0; i < stars; i++) {
		//	out.printf("dist %s\n", dist[i % dist.length]);
		//}
		
		switch (boosters) {
		case 0:
			time = simulate(stars, dist, btime, stars+1, stars+1);
			break;
		case 1:
			for (int a = 0; a < stars; a++) {
				long travelTime = simulate(stars, dist, btime, a, stars+1);
				time = Math.min(time, travelTime);
			}
			break;
		case 2:
			for (int a = 0; a < stars; a++)
				for (int b = a + 1; b < stars; b++) {
					long travelTime = simulate(stars, dist, btime, a, b);
					time = Math.min(time, travelTime);
				}
			break;
		}
		out.printf("Case #%s: %s\n", testCase, time);
	}
}