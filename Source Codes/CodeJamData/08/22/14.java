package aditsu.gcj.numbersets;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class NumberSetsBig {
	private String getPath(final String file) {
		return "src/" + getClass().getPackage().getName().replace('.', '/') + '/' + file;
	}

	private BufferedReader getReader(final String file) throws IOException {
		return new BufferedReader(new FileReader(getPath(file)));
	}

	private PrintWriter getWriter(final String file) throws IOException {
		return new PrintWriter(getPath(file));
	}

	private PrintWriter getWriter() throws IOException {
		return getWriter("result.txt");
	}

	private static int toInt(final String s) {
		return Integer.parseInt(s);
	}
	
	private final List<Integer> sieve = new ArrayList<Integer>();
	private final List<Integer> primes = new ArrayList<Integer>();

	private void calcPrimes() {
		int n = 1000000;
		for (int i = 0; i < n; ++i) {
			sieve.add(i);
		}
		sieve.set(0, 0);
		sieve.set(1, 0);
		for (int i = 2; i < Math.sqrt(n) + 10; ++i) {
			for (int j = i * i; j < n; j += i) {
				sieve.set(j, 0);
			}
		}
		for (int i = 0; i < n; ++i) {
			final int x = sieve.get(i);
			if (x != 0) {
				primes.add(x);
			}
		}
//		System.out.println(primes.size());
	}

	private static int getSet(final int[] set, final int x) {
		final int s = set[x];
//		System.out.println(x + "->" + s);
		if (s != x) {
			set[x] = getSet(set, s);
		}
		return set[x];
	}

	private static boolean combine(final int[] set, final int x, final int y) {
		final int sx = getSet(set, x);
		final int sy = getSet(set, y);
		if (sx == sy) {
			return false;
		}
		set[sy] = sx;
		return true;
	}

	private void go() throws IOException {
		final BufferedReader br = getReader("B-large.in");
		final PrintWriter w = getWriter();
		
		final int c = toInt(br.readLine());
		for (int i = 0; i < c; ++i) {
			final Scanner sc = new Scanner(br.readLine());
			final long a = sc.nextLong();
			final long b = sc.nextLong();
			final long p = sc.nextLong();
			System.out.println(a + " " + b + " " + p);
			int idx = -1;
			for (int j = 0; j < primes.size(); ++j) {
				if (primes.get(j) >= p) {
					idx = j;
					break;
				}
			}
			final int n = (int) (b - a + 1);
			int sets = n;
			if (idx >= 0 && n >= p) {
				final int[] set = new int[n];
				for (int j = 0; j < n; ++j) {
					set[j] = j;
				}
				for (int j = idx; j < primes.size(); ++j) {
					final int pp = primes.get(j);
					final int a1 = (pp - (int) (a % pp)) % pp;
					for (int x = a1 + pp; x < n; x += pp) {
						if (combine(set, a1, x)) {
							sets--;
						}
					}
				}
			}
			w.println("Case #" + (i + 1) + ": " + sets);
		}
		w.flush();
	}

	public static void main(final String... args) throws IOException {
		final NumberSetsBig x = new NumberSetsBig();
		x.calcPrimes();
		x.go();
	}
}
