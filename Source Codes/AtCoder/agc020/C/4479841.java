import java.util.*;

/*
 * 
 * Sadekujjaman Saju
 * 
 */

public class Main {

	static long dp[][] = new long[201][101];
	static int grid[][] = new int[201][101];

	static int n;
	static int arr[];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

//		BitSet bits1 = new BitSet(16);
//		BitSet bits2 = new BitSet(16);
//
//		for (int i = 0; i < 16; i++) {
//			if ((i % 2) == 0)
//				bits1.set(i);
//			if ((i % 5) != 0)
//				bits2.set(i);
//		}

//		System.out.println("Initial pattern in bits1: ");
//		System.out.println(bits1);
//		System.out.println("\nInitial pattern in bits2: ");
//		System.out.println(bits2);
//
//		// get some bit
//		
//		BitSet b1 = bits2.get(2, 8);
//		System.out.println(bits1.get(0, 11));
//		
//		
//		// AND bits
//		bits2.and(bits1);
//		System.out.println("\nbits2 AND bits1: ");
//		System.out.println(bits2);
//
//		// OR bits
//		bits2.or(bits1);
//		System.out.println("\nbits2 OR bits1: ");
//		System.out.println(bits2);

		n = sc.nextInt();
		arr = new int[n];

		int sum = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
			sum += arr[i];
		}

		BitSet bs = new BitSet(sum + 1);
		bs.set(sum);

//		System.out.println(bs);
		
		for (int i = 0; i < n; i++) {
			BitSet curr = bs.get(arr[i], sum + 1);
//			System.out.println(curr);
			bs.or(curr);
//			System.out.println(bs);
		}
		
		int start = 0;
		if(sum %2 == 0){
			start = sum / 2;
		}
		else{
			start = (sum + 1) / 2;
		}
		
		for (int i = start; i <= sum; i++) {
			if (bs.get(i)) {
				System.out.println(i);
				break;
			}
		}
		sc.close();
	}

	private static void printDistSum(int arr[], int n) {
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += arr[i];

		// dp[i][j] would be true if arr[0..i-1]
		// has a subset with sum equal to j.
		boolean[][] dp = new boolean[n + 1][sum + 1];

		// There is always a subset with 0 sum
		for (int i = 0; i <= n; i++)
			dp[i][0] = true;

		// Fill dp[][] in bottom up manner
		for (int i = 1; i <= n; i++) {
			dp[i][arr[i - 1]] = true;
			for (int j = 1; j <= sum; j++) {
				// Sums that were achievable
				// without current array element
				if (dp[i - 1][j] == true) {
					dp[i][j] = true;
					dp[i][j + arr[i - 1]] = true;
				}
			}
		}

		// Print last row elements
		for (int j = 0; j <= sum; j++)
			if (dp[n][j] == true)
				System.out.print(j + " ");
	}

}