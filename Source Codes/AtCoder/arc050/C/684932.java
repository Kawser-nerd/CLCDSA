import java.util.BitSet;
import java.util.Scanner;

public class Main {

	/**10^(2^i)?m???????????????*/
	private static long[] remainders0;
	/** one(2^i)?m???????????????*/
	private static long[] remainders1;
	/** remainders2???? 10^(2^i * gcd)?m??????????????*/
	private static long[] remaindersPre2;
	/** one(2^i * gcd)/one(gcd)?m???????????????*/
	private static long[] remainders2;
	
	
	public static void main(String[] args) {
		
		final long a;
		final long b;
		final long m;		// ???int??long??????
		try(Scanner scan = new Scanner(System.in)) {
			a = scan.nextLong();
			b = scan.nextLong();
			m = scan.nextLong();
		}

		// ???????????????
		/* 1?a?????????one(a)?????????
		 * x = one(a), y = one(b)?????x > y ???
		 * x % y = one(a % b)????
		 * ?????one(a)???a % b??0?????one(a)-one(a%b)?one(b)??????
		 * one(a%b) < one(b)???one(a % b)?one(b)???????
		 * ????x,y????????????a,b????????????
		 */
		
		
		long gcd = euclidean(a, b);
		long max = Math.max(a, b);
		long min = Math.min(a, b);
		// ??????????????m?????????????????m=4????3???????
		// 1??m???????????????????????????
		// 2???????????????????
		final int limit = 60;	// 10^18 < 2^(10*6)
		remainders0 = new long[limit];
		remainders0[0] = 10L % m;
		for (int i = 1; i < remainders0.length; i++) {
			remainders0[i] = remainders0[i - 1] * remainders0[i - 1] % m;
		}
		remainders1 = new long[limit];
		remainders1[0] = 1 % m;				// m >=2
		for (int i = 1; i < remainders1.length; i++) {
			// one(2^i) = one(2^(i-1)) * 10^(2^(i-1)) + one(2^(i-1))
			remainders1[i] = (remainders1[i - 1] * remainders0[i -1] + remainders1[i - 1]) % m;	//long?????????
		}
		remaindersPre2 = new long[limit];
		remaindersPre2[0] = remainder0(gcd, m);
		for (int i = 1; i < remaindersPre2.length; i++) {
			remaindersPre2[i] = remaindersPre2[i - 1] * remaindersPre2[i - 1] % m;
		}
		remainders2 = new long[limit];
		remainders2[0] = 1 % m;
		for (int i = 1; i < remainders2.length; i++) {
			// one(2^i * gcd)/one(gcd) = one(2^(i-1) * gcd)/one(gcd) * 10^((2^(i-1) * gcd)) + one(2^(i-1) * gcd)/one(gcd)
			remainders2[i] = (remainders2[i -1] * remaindersPre2[i -1] + remainders2[i -1]) % m;
		}

		//System.out.println(gcd);
		//System.out.println(remainder1(min, m));
		//System.out.println(remainder2(max / gcd, m));
		
		long result = remainder1(min, m) * remainder2(max / gcd, m) % m;
		
		System.out.println(result);

	}
	
	/**
	 * ?????????????????????????????????
	 * @param a
	 * @param b
	 * @return a b ??????
	 */
	private static long euclidean(long a, long b) {
		long max = Math.max(a, b);
		long min = Math.min(a, b);
		long remain = max % min;
		if (remain == 0) {
			return min;
		} else {
			return euclidean(remain, min);
		}
	}
	
	/**
	 * one(m)?m??????????
	 */
	private static long remainder1(long n, long m) {
		BitSet bit = BitSet.valueOf(new long[]{n-1});		//little-endian
		long remain = 1L;
		for (int i = 0; i < remainders1.length; i++) {
			// one(n+2^i) = one(n) + 10^(2^i) + one(2^i)
			if (bit.get(i)) {
				remain = (remain * remainders0[i] + remainders1[i]) % m;
			}
		}
		return remain;
	}
	
	/**
	 * 10^n?m??????????
	 * @param n <  ???3?????bit?0
	 * @param m: long??int???
	 * @return long??int???
	 */
	private static long remainder0(long n, long m) {
		BitSet bit = BitSet.valueOf(new long[]{n});		//little-endian
		long remain = 1L;
		for (int i = 0; i < remainders0.length; i++) {
			// 10^(n+2^i) = 10^n * 10^(2^i)
			if (bit.get(i)) {
				remain = remain * remainders0[i] % m;
			}
		}
		return remain;
	}
	
	/**
	 * one(n * gcd)/one(gcd)?m??????????
	 * @param n <  ???3?????bit?0
	 * @param m: long??int???
	 * @return: long??int???
	 */
	private static long remainder2(long n, long m) {
		BitSet bit = BitSet.valueOf(new long[]{n-1});		//1??1?n-1???????????
		long remain = 1L;
		for (int i = 0; i < remaindersPre2.length; i++) {
			// one((n+2^i) * gcd)/one(gcd) = one(n * gcd)/one(gcd) * 10^((2^i * gcd)) + one(2^i * gcd)/one(gcd)
			if (bit.get(i)) {
				remain = (remain * remaindersPre2[i] + remainders2[i]) % m;
			}
		}
		return remain;
	}
	
}