import java.math.BigInteger;
import java.util.Scanner;
import java.util.Arrays;

class GCJ_10_Qual_B {
	private static int C, N;
	private static BigInteger[] T = new BigInteger[2000];
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		C = s.nextInt();
		for (int cs = 1; cs <= C; cs++) {
			N = s.nextInt();
			for (int i = 0; i < N; i++) T[i] = s.nextBigInteger();
			BigInteger ggt = BigInteger.ZERO;
			Arrays.sort(T, 0, N);
			for (int i = 0; i < N-1; i++) ggt = ggt.gcd(T[i+1].subtract(T[i]));
			BigInteger res = ggt.subtract(T[0]).mod(ggt);
			System.out.println("Case #" + cs + ": " + res);
		}
		System.exit(0);
	}
}
