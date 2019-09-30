import java.math.BigInteger;
import java.util.Scanner;

public class A {
	static BigInteger B(long x) { return BigInteger.valueOf(x); }
	static BigInteger r;
	static BigInteger f(long guess) {
		BigInteger x = B(guess);
		BigInteger two_x_minus_one = x.multiply(B(2)).subtract(B(1));
		return B(2).multiply(x).multiply(r).add(x.multiply(two_x_minus_one));
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cas=1; cas<=T; cas++) {
			r = BigInteger.valueOf(in.nextLong());
			BigInteger t = BigInteger.valueOf(in.nextLong());
			
			long lo = 0;
			long hi = t.longValue();
			while(lo < hi) {
				long mid = (lo+hi+1)/2;
				BigInteger score = f(mid);
				if(score.compareTo(t) > 0) hi = mid-1;
				else lo = mid;
			}
			
			System.out.printf("Case #%d: %d\n", cas, lo);
		}
	}
}