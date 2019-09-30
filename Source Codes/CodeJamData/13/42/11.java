import java.math.BigInteger;
import java.util.*;

public class B {
	static BigInteger B(long n) { return BigInteger.valueOf(n); }
	static BigInteger A(BigInteger A, BigInteger B) { return A.add(B); }
	static BigInteger M(BigInteger A, BigInteger B) { return A.multiply(B); }
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cas=1; cas<=T; cas++) {
			int n = in.nextInt();
			BigInteger P = new BigInteger(in.next());
			BigInteger last_pos = B(2).pow(n).subtract(P);
			
			int min_ones = 0;
			for(min_ones=0; min_ones<=n; min_ones++) {
				BigInteger val = B(0);
				for(int i=0; i<min_ones; i++)
					val = A(val, B(2).pow(n-1-i));
				if(val.compareTo(last_pos) >= 0)
					break;
			}
			BigInteger last_win = B(2).pow(n).subtract(B(2).pow(min_ones));
			
			int min_zeroes = 0;
			for(min_zeroes=0; min_zeroes<=n; min_zeroes++) {
				BigInteger val = B(2).pow(n).subtract(B(1));
				for(int i=0; i<min_zeroes; i++)
					val = val.subtract(B(2).pow(n-1-i));
				if(val.compareTo(last_pos) < 0)
					break;
			}
			BigInteger last_guarantee = B(2).pow(min_zeroes).subtract(B(2));
			if(last_pos.equals(B(0)))
				last_guarantee = B(2).pow(n).subtract(B(1));
			
			//System.out.println(min_zeroes+" "+min_ones);
			System.out.printf("Case #%d: %s %s\n", cas, last_guarantee, last_win);
		}
	}
}
