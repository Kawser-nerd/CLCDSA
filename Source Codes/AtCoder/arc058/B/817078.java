import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long H = sc.nextInt() - 1;
		long W = sc.nextInt() - 1;
		long A = sc.nextInt() - 1;
		long B = sc.nextInt() - 1;

		long MOD = 1000000007L;
		BigInteger BMOD = BigInteger.valueOf(MOD);
		//BigInteger x = BigInteger.ONE;
		//BigInteger y = BigInteger.ONE;
		long x = 1;
		long y = 1;

		for (long i = W - B; i <= W - B - 1 + H; i++) {
			//y = y.multiply(BigInteger.valueOf(i));
			y = (y * i) % MOD;
		}
		for (long i = 1; i <= H; i++) {
			//y = y.divide(BigInteger.valueOf(i));
			y = (y * BigInteger.valueOf(i).modInverse(BMOD).longValue()) % MOD;
		}

		//long ans = x.multiply(y).mod(BigInteger.valueOf(MOD)).longValue();
		long ans = (x * y) % MOD;
		long a1 = B + 1;
		long a2 = 1;
		long b1 = W - B - 1 + H;
		long b2 = H;
		for (int i = 1; i < H - A; i++) {
			//x = x.multiply(BigInteger.valueOf(a1))
			//		.divide(BigInteger.valueOf(a2));
			x = (x * a1) % MOD;
			x = (x * BigInteger.valueOf(a2).modInverse(BMOD).longValue()) % MOD;
			a1 += 1;
			a2 += 1;
			//y = y.multiply(BigInteger.valueOf(b2))
			//		.divide(BigInteger.valueOf(b1));
			y = (y * b2) % MOD;
			y = (y * BigInteger.valueOf(b1).modInverse(BMOD).longValue()) % MOD;
			b1 -= 1;
			b2 -= 1;
			//ans = (ans
			//		+ x.multiply(y).mod(BigInteger.valueOf(MOD)).longValue())
			//		% MOD;
			ans = (ans + x * y) % MOD;
		}
		System.out.println(ans);
	}
}