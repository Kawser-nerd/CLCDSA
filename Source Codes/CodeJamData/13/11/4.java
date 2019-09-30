import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			long R = in.nextLong();
			long D = in.nextLong();
			
			long low = 0;
			long high = Integer.MAX_VALUE;
			
			while(low < high) {
				long mid = (low + high + 1) / 2;
				
				if (total(R-1, mid).compareTo(BigInteger.valueOf(D)) <= 0) {
					low = mid;
				} else {
					high = mid - 1;
				}
			}
			System.out.format("Case #%d: %d\n", t, low);
		}
	}

	private static BigInteger total(long R, long N) {
		BigInteger a = BigInteger.valueOf(2*N);
		a = a.multiply(BigInteger.valueOf(R));
		
		BigInteger b = BigInteger.valueOf(2*N);
		b = b.multiply(BigInteger.valueOf(N+1));

		BigInteger total = a.add(b).subtract(BigInteger.valueOf(N));
//		System.out.println(R+" "+N+" "+total);
		return total;
	}
}
