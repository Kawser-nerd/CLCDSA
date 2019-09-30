import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		//		new Main().solveB();
		new Main().solveC();
		//		new Main().solveCX();
		// new Main().solveD();
	}

	private void solveA() {
		Scanner scanner = null;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			if (numN > 999) {
				System.out.println("ABD");
			} else {
				System.out.println("ABC");
			}

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int numA = 0;
		int numB = 0;

		try {
			scanner = new Scanner(System.in);
			numA = scanner.nextInt();
			numB = scanner.nextInt();

			int wk = numB - numA;

			int res = 0;
			for (int i = 1; i < wk; i++) {
				res += i;
			}

			System.out.println(res - numA);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private int checkCash(int powC, int currentI, int currentCash) {

		if (currentCash < powC || currentI < 1) {
			return currentCash;
		}

		int res = 0;
		int wk = (int) Math.pow(powC, currentI);

		if (wk <= currentCash) {
			currentCash -= wk;
			cntC++;
		}
		int val1 = checkCash(9, currentI - 1, currentCash);
		int val2 = checkCash(6, currentI - 1, currentCash);
		res = Math.min(val1, val2);
		return res;
	}

	private int cntC = 0;

	/**
	 * dp[0] = 0
	 * N = cash/yen
	 * dp[N] = 1 + dp[N-1]
	 *       = 1 + dp[N-6]
	 *       = 1 + dp[N-6^2]
	 *       = 1 + dp[N-6^3]
	 *
	 *       = 1 + dp[N-9^1]
	 */
	private void solveC() {

		try (Scanner scanner = new Scanner(System.in)) {

			int numN = scanner.nextInt();

			/*
			 * 1
			 * 6 , 6^2 , 6^3 , 6^4
			 * 9 , 9^2 , 9^3 , 9^4
			 * dp[N]
			 * dp[i] ----- dp[N-1]
			 * 1????????
			 * dp[N]= 1 + dp[N-1]
			 *     ?  = 1 + dp[N-6]
			 *       ?= 1 + dp[N-6^2]
			 *       ?= 1 + dp[N-6^3]
			 *
			 *?       = 1 + dp[N-9^1]
			 * ?????
			 *
			 */

			/*
			 * N<=100000?????dp[N]?100000????????
			 */
			int[] dp = new int[100010];

			/*
			 * dp[N]???????
			 * min??????????????
			 */
			Arrays.fill(dp, 999999999);

			/*
			 * dpN??????????????
			 * 0-5?1?????
			 * ?????
			 */
			dp[0] = 0;
			dp[1] = 1;
			dp[2] = 2;
			dp[3] = 3;
			dp[4] = 4;
			dp[5] = 5;
			/*
			 * 6???N??????????
			 */
			for (int dpN = 6; dpN <= numN; dpN++) {

				/*
				 * 6???DP
				 */
				int power = 6;
				while (power <= dpN) {
					/*
					 * dpN??dpN-power(6^??)????
					 * dpN?????INF???????
					 * dp[dpN - power] + 1???(dpN-power)?????"????"?+1????????????????????
					 */
					dp[dpN] = Math.min(dp[dpN], dp[dpN - power] + 1);
					power *= 6;
				}

				/*
				 * 9???DP
				 */
				power = 9;
				while (power <= dpN) {
					/*
					 * dpN??dpN-power(9^??)????
					 * dpN?????INF???6^??????????????
					 * dp[dpN - power] + 1???(dpN-power)?????"????"?+1????????????????????
					 * ??dpN=6???????6????????(6-6^1)??????+1????
					 * ?????6???0?+6^1????????0?????????+1????6???????????
					 *
					 */
					dp[dpN] = Math.min(dp[dpN], dp[dpN - power] + 1);
					power *= 9;
				}
			}

			System.out.println(dp[numN]);

		}

	}
	//
	//	????????????
	//	private void solveCX() {
	//
	//		Scanner scanner = new Scanner(System.in);
	//		int n = scanner.nextInt();
	//		//dp[i]?i??????????????????
	//		int[] dp = new int[100100];
	//		for (int i = 0; i <= 100000; i++) {
	//			dp[i] = Integer.MAX_VALUE;
	//		}
	//		dp[0] = 0;
	//		dp[1] = 1;
	//		int l = 6;
	//		while (l <= 100000) {
	//			dp[l] = 1;
	//			l *= 6;
	//		}
	//		int k = 9;
	//		while (k <= 100000) {
	//			dp[k] = 1;
	//			k *= 9;
	//		}
	//		for (int i = 0; i <= 100000; i++) {
	//			int power1 = 1;
	//			while (power1 <= i) {
	//				dp[i] = Math.min(dp[i], dp[i - power1] + 1);
	//				power1 *= 6;
	//			}
	//			int power2 = 1;
	//			while (power2 <= i) {
	//				dp[i] = Math.min(dp[i], dp[i - power2] + 1);
	//				power2 *= 9;
	//			}
	//		}
	//		System.out.println(dp[n]);
	//
	//	}

	private void solveD() {
		Scanner scanner = null;
		int numN = 0;
		int numK = 0;
		int numS = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			System.out.println("");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}
}