import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		System.out.println(solve(new Scanner(System.in).next()));
	}

	String solve(String a) {
		BigInteger m = new BigInteger(a);
		BigInteger m1 = m.multiply(m);
		BigInteger m2 = (m.add(BigInteger.ONE)).multiply((m.add(BigInteger.ONE)));
		String ans = m.multiply(m).toString();
		
		for (int i = 0; i < 10000000; ++i) {
			String strPow10 = "1";
			for (int t = 0; t < 2 * i; ++t) {
				strPow10 = strPow10 + "0";
			}
			BigInteger pow10 = new BigInteger(strPow10);
			BigInteger v1 = m1.divide(pow10);
			BigInteger v2 = m2.divide(pow10);
			if (!m1.remainder(pow10).equals(BigInteger.ZERO)) {
				v1 = v1.add(BigInteger.ONE);
			}
			if (!m2.remainder(pow10).equals(BigInteger.ZERO)) {
				v2 = v2.add(BigInteger.ONE);
			}
			if (v2.subtract(v1).signum() <= 0)
				break;
			ans = v1.toString();
			if(i%10==0)
			System.gc();
		}
		return ans;
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}