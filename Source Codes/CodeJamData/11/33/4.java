import static java.lang.System.out;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

class LibraryC {
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

	public static long gcd(long a, long b) {
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

public class C extends LibraryC {
	public static void main(String[] args) {
		if (false) {
			long w = 8633;
			for (long a : primeFactors(w))
				out.println(a);
			out.println("======");
			for (long a : factors(w))
				out.println(a);
		} else {
			int T = sc.nextInt();
			for (int t = 1; t <= T; t++)
				main(t);
		}
	}

	static BigInteger lcm(BigInteger a, BigInteger b) {
		return a.multiply(b).divide(a.gcd(b));
	}

	static boolean between(BigInteger a, BigInteger lo, BigInteger hi) {
		return lo.compareTo(a) <= 0 && a.compareTo(hi) <= 0;
	}

	static ArrayList<Long> primeFactors(long a) {
		ArrayList<Long> factors = new ArrayList<Long>();
		while (a % 2 == 0) {
			factors.add(Long.valueOf(2));
			a /= 2;
		}

		long max = (long) Math.ceil(Math.sqrt(a));
		main: for (long i = 3; i <= max; i += 2) {
			while (a % i == 0) {
				factors.add(Long.valueOf(i));
				a /= i;
				if (a == 1)
					break main;
			}
		}
		if (a != 1)
			factors.add(a);
		return factors;
	}

	static HashSet<Long> temp = new HashSet<Long>();

	static void add(Set<Long> set, long a) {
		temp.clear();
		for (long q : set)
			temp.add(Long.valueOf(q * a));
		set.addAll(temp);
	}

	static List<Long> factors(long a) {
		HashSet<Long> factors = new HashSet<Long>();
		factors.add(Long.valueOf(1));

		while (a % 2 == 0) {
			add(factors, 2);
			a /= 2;
		}

		long max = (long) Math.ceil(Math.sqrt(a));
		main: for (long i = 3; i <= max; i += 2) {
			while (a % i == 0) {
				add(factors, i);
				a /= i;
				if (a == 1)
					break main;
			}
		}
		if (a != 1)
			add(factors, a);

		ArrayList<Long> list = new ArrayList<Long>(factors);
		Collections.sort(list);
		return list;
	}

	public static void main(int testCase) {
		int n = ni();
		BigInteger lo = BigInteger.valueOf(nl());
		BigInteger hi = BigInteger.valueOf(nl());
		BigInteger[] notes = new BigInteger[n];
		for (int i = 0; i < n; i++) {
			notes[i] = sc.nextBigInteger();
		}
		Arrays.sort(notes);

		BigInteger[] gcds = new BigInteger[n];

		// notes: 10 30
		// 10 30, misses 1 2 3 5 
		BigInteger q = gcds[n - 1] = notes[n - 1];
		for (int i = n - 2; i >= 0; i--)
			gcds[i] = q = q.gcd(notes[i]);

		BigInteger zero = BigInteger.ZERO;

		BigInteger result = zero;

		long loi = lo.longValue(), hii = hi.longValue();
		for (long e : factors(q.longValue()))
			if (loi <= e && e <= hii) {
				result = BigInteger.valueOf(e);
				break;
			}

		if (result.equals(BigInteger.ZERO))
			//out.printf("q0=%s\n", q);
			main: for (int i = 0; i < n; i++) {
				if (q.compareTo(hi) > 0)
					break;
				//out.printf("gcds[%s]=%s\n", i, q);
				if (lo.compareTo(q) <= 0 && gcds[i].mod(q).equals(zero)) {
					result = q;
					break;
				}
				BigInteger qnext = lcm(q, notes[i]);

				long inc = qnext.divide(q).longValue();
				//out.printf("inc %s\n", inc);
				for (long f : factors(inc)) {
					BigInteger e = BigInteger.valueOf(f).multiply(q);
					//out.printf("incf %s\n", e);
					if (between(e, lo, hi) && gcds[i].mod(e).equals(zero)) {
						result = e;
						break main;
					}
				}

				q = qnext;
				//out.printf("q=%s\n", q);
			}

		if (result.equals(BigInteger.ZERO) && between(q, lo, hi)) {
			// lcm
			result = q;
		}

		if (result.equals(zero) && q.compareTo(lo) < 0) {
			BigInteger e = lo.add(q).subtract(BigInteger.ONE).divide(q).multiply(q);
			if (between(e, lo, hi))
				result = e;
		}

		if (result.equals(zero))
			out.printf("Case #%s: NO\n", testCase);
		else
			out.printf("Case #%s: %s\n", testCase, result);
	}
}