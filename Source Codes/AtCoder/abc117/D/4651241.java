import java.util.*;

public class Main {
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		long K = sc.nextLong();
		
		long[] A = new long[N];
		long sum = 0;
		
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextLong();
			sum += A[i];
		}
		
		int numBinDigits = getMostSignificantBit(K);
		long[] netGainForDigit = new long[numBinDigits];
		
		for (int i = 0; i < numBinDigits; i++) {
			int oneCount = 0;
			int zeroCount = 0;
			for (int j = 0; j < N; j++) {
				if (getBitAt(A[j], i+1)) {
					oneCount++;
				} else {
					zeroCount++;
				}
			}
			int netChange = zeroCount - oneCount;
			netGainForDigit[i] = netChange * pow(2, i);
		}
		
		/*
		System.out.println("NetGains:");
		for (long n : netGainForDigit) {
			System.out.print(n + " ");
		}
		System.out.println();
		*/
		
		System.out.println(sum+getMax(K, netGainForDigit, numBinDigits-1, 0, 0));
	}
	
	public static long getMax(long K, long[] netGainForDigit, int digit, long curValue, long max) {
		if (digit < 0) {
			return max;
		}
		if (netGainForDigit[digit] > 0 && curValue + pow(2, digit) <= K) {
			if (curValue + pow(2, digit+1) <= K) {
				return getMax(K, netGainForDigit, digit-1, curValue + pow(2, digit), max + netGainForDigit[digit]);
			} else {
				return Math.max(getMax(K, netGainForDigit, digit-1, curValue + pow(2, digit), max + netGainForDigit[digit]), 
				getMax(K, netGainForDigit, digit-1, curValue, max));
			}
		} else {
			return getMax(K, netGainForDigit, digit-1, curValue, max);
		}
	}
	
	public static long pow(int a, int b) {
		long product = 1;
		for (int i = 0; i < b; i++) {
			product *= a;
		}
		return product;
	}
	
	public static boolean getBitAt(long A, int digit) {
		if (digit == 1 || A == 0) {
			return A%2 == 1;
		}
		return getBitAt(A/2, digit-1);
	}
	
	public static int getMostSignificantBit(long K) {
		if (K <= 1) {
			return 1;
		}
		return 1+getMostSignificantBit(K/2);
	}
}