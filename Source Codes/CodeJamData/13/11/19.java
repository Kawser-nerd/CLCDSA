import java.util.*;
import java.math.*;

public class A {
	
	static BigInteger x;
	
	static BigInteger cs(BigInteger n) {
		return
			BigInteger.valueOf(2).multiply(x).multiply(n).add(
				BigInteger.valueOf(2).multiply(n).multiply(n)
			).subtract(n);
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int tc = s.nextInt();
		for (int tt = 1; tt <= tc; ++tt) {
			x = BigInteger.valueOf(s.nextLong());
			BigInteger t = BigInteger.valueOf(s.nextLong());
			
			BigInteger ok = BigInteger.valueOf(0);
			BigInteger notok = BigInteger.valueOf(10000000000L);
			while (notok.compareTo(ok.add(BigInteger.ONE)) > 0) {
				BigInteger mid = ok.add(notok).divide(BigInteger.valueOf(2));
				if (cs(mid).compareTo(t) <= 0) {
					ok = mid;
				} else {
					notok = mid;
				}
			}
			System.out.println("Case #"+tt+": "+ok);
		}
	}

}
