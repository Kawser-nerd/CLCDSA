import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class ProblemB {
	public static void main(final String[] args) {
		final Scanner sc = new Scanner(System.in);
		final int cases = sc.nextInt();

		for (int cc = 1; cc <= cases; cc++) {
			final String num = sc.next();
			final int len = num.length();

			final List<Map<BigInteger, BigInteger>> x = new ArrayList<Map<BigInteger, BigInteger>>();

			for (int i = 0; i <= len; i++)
				x.add(new HashMap<BigInteger, BigInteger>());

			for (int i = 1; i <= len; i++) {
				final BigInteger a = new BigInteger(num.substring(0, i));
				final Map<BigInteger, BigInteger> xi = x.get(i);
				add(xi, a.mod(b210), BigInteger.ONE);
				for (int j = 1; j < i; j++) {
					final BigInteger b = new BigInteger(num.substring(j, i));
					for (final Map.Entry<BigInteger, BigInteger> e : x.get(j).entrySet()) {
						final BigInteger eb = e.getKey();
						final BigInteger ec = e.getValue();
						add(xi, eb.add(b).mod(b210), ec);
						add(xi, eb.subtract(b).mod(b210), ec);
					}
				}
			}

			BigInteger count = BigInteger.ZERO;
			for (final Map.Entry<BigInteger, BigInteger> e : x.get(len).entrySet()) {
				final BigInteger eb = e.getKey();
				final BigInteger ec = e.getValue();
				if (ugly(eb)) count = count.add(ec);
			}

			System.out.printf("Case #%s: %s\n", cc, count);
		}
		System.out.flush();
	}

	static void add(final Map<BigInteger, BigInteger> m, final BigInteger b, final BigInteger c) {
		final BigInteger q = m.get(b);
		if (q == null)
			m.put(b, c);
		else
			m.put(b, q.add(c));
	}

	static final BigInteger b2 = BigInteger.valueOf(2);
	static final BigInteger b210 = BigInteger.valueOf(210);
	static final BigInteger b3 = BigInteger.valueOf(3);
	static final BigInteger b5 = BigInteger.valueOf(5);
	static final BigInteger b7 = BigInteger.valueOf(7);

	static boolean ugly(BigInteger a) {
		if (a.signum() < 0) a = a.negate();
		return a.mod(b2).signum() == 0 || a.mod(b3).signum() == 0 || a.mod(b5).signum() == 0
				|| a.mod(b7).signum() == 0;
	}
}