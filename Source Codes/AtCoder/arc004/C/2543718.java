import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static boolean debug = false;
	static boolean debug2 = false;

	public static void main(String[] args) throws java.io.IOException {
		debug = 1 <= args.length;
		debug2 = 2 <= args.length;

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String[] ia = in.readLine().split("/");
		BigInteger X = new BigInteger(ia[0]);
		BigInteger Y = new BigInteger(ia[1]);

		boolean flag = true;
		for (long i = -5; i < 5; ++i) {
			final BigInteger V = BigInteger.valueOf(2).multiply(X).divide(Y);
			final BigInteger N = V.add(BigInteger.valueOf(i));
			if (N.compareTo(BigInteger.ZERO) <= 0) {
				if (debug) {
					System.err.println();
				}
				continue;
			}
			final BigInteger U = N.multiply(BigInteger.ONE.add(N).multiply(Y).subtract(BigInteger.valueOf(2).multiply(X)));
			final BigInteger L = BigInteger.valueOf(2).multiply(Y);
			if (debug) {
				System.err.println(N);
				System.err.println(U);
				System.err.println(L);
			}
			if (U.mod(L).compareTo(BigInteger.ZERO) > 0) {
				if (debug) {
					System.err.println();
				}
				continue;
			}
			final BigInteger M = U.divide(L);
			if (0 <= M.compareTo(BigInteger.ONE) && M.compareTo(N) <= 0) {
				System.out.println("" + N + " " + M);
				if (debug) {
					System.err.println("" + N + " " + M);
				}
				flag = false;
			}
			if (debug) {
				System.err.println();
			}
		}

		if (flag) {
			System.out.println("Impossible");
		}
	}
}