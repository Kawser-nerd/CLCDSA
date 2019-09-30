import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner cin = new Scanner(System.in);
		final int C = cin.nextInt();
		for (int c = 1; c <= C; ++c) {
			final int N = cin.nextInt();
			final BigInteger[] input = new BigInteger[N];
			for (int n = 0; n < N; ++n) {
				input[n] = cin.nextBigInteger();
			}

			Arrays.sort(input);

			final BigInteger minValue = input[0];
			final BigInteger maxValue = input[N - 1];

			for (int i = 0; i < N; ++i) {
				input[i] = input[i].subtract(minValue);
			}

			BigInteger T = input[N - 1];

			for (BigInteger bi : input) {
				T = T.gcd(bi);
			}

			BigInteger y = maxValue.add(T).subtract(BigInteger.ONE).divide(T).multiply(T).subtract(maxValue);
			System.out.println("Case #" + c + ": " + y);
		}
	}
}
