import java.util.Arrays;
import java.util.Scanner;

public class Main {
	// abc114 D

	// primes under 100.
	private int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

	public class PrimeFactorizater {
		
		public PrimeFactorizater(int max) {
		}
		
		public int[] getPrimeCount(int num) {
			int[] counts = new int[primes.length];
			Arrays.fill(counts, 0);

			for (int i=0; i<primes.length; i++) {
				int prime = primes[i];
				while (true) {
					if (num % prime == 0) {
						counts[i]++;
						num = num / prime;
					} else {
						break;
					}
				}
			}
			
			return counts;
		}
	}
	
	public void solve() {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.close();

		PrimeFactorizater pf = new PrimeFactorizater(N);
		int[] primesCount = new int[primes.length];
		Arrays.fill(primesCount, 0);
		
		for (int i=1; i<=N; i++) {
			int[] pfRet = pf.getPrimeCount(i);
			for(int j=0; j<pfRet.length; j++) {
				primesCount[j] += pfRet[j];
			}
		}
		
		int[] useCount = new int[primesCount.length];
		Arrays.fill(useCount, 0);
		long result = count(primesCount, useCount, 0);
		
		System.out.println(result);
	}
	
	private long count(int[] primesCount, int[] useCount, int pos) {
		long ret = 0;
		long pattern = getPattern(useCount);
		
		if (pattern == 75) {
			return 1;
		} else if (pattern > 75) {
			return 0;
		}
		if (pos >= primesCount.length) {
			return 0;
		}
		
		for (int i=0; i<=primesCount[pos]; i++) {
			useCount[pos] = i;
			ret += count(primesCount, useCount, pos+1);
		}	
		useCount[pos] = 0;

		return ret;
	}
	
	private long getPattern(int[] useCount) {
		long pattern = 1;	// count unused all elements instead of factor 1.
		for (int i=0; i<useCount.length; i++) {
			pattern *= useCount[i] + 1;
			if (pattern > 75) {
				return pattern;
			}
		}
		return pattern;
	}
	
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}
}