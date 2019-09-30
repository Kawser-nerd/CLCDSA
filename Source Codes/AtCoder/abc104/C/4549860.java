import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		//		new Main().solveB();
		/**
		 * remaining problem C
		 */
		//		new Main().solveC();
		new Main().solveC2();
		// new Main().solveD();
	}

	private void solveA() {
		Scanner scanner = null;
		int numRating = 0;

		try {
			scanner = new Scanner(System.in);
			numRating = scanner.nextInt();

			if (numRating < 1200) {
				System.out.println("ABC");
			} else if (numRating < 2800) {
				System.out.println("ARC");
			} else {
				System.out.println("AGC");
			}

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		String strS = "";

		try {
			scanner = new Scanner(System.in);
			strS = scanner.next();

			if (strS.charAt(0) != 'A') {
				System.out.println("WA");
				return;
			}
			int res = 0;
			int wkIndex = 0;
			for (int i = 2; i < strS.length() - 1; i++) {
				if (strS.charAt(i) == 'C') {
					res++;
					wkIndex = i;
				}
			}
			if (res != 1) {
				System.out.println("WA");
				return;
			}
			for (int i = 0; i < strS.length(); i++) {
				if (i != 0 && i != wkIndex && !Character.isLowerCase(strS.charAt(i))) {
					System.out.println("WA");
					return;
				}
			}
			System.out.println("AC");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private long solveCsaiki(long currentG, int currentI, long[][] wk, long numG) {

		if (currentI < 0) {
			return currentG;
		}
		if (wk[currentI][1] <= 0) {
			return solveCsaiki(currentG, currentI + 1, wk, numG);
		}

		long currentG2 = currentG;
		long count1 = 0;
		while (currentG2 <= numG && wk[currentI][1] > 0) {
			currentG2 -= wk[currentI][0];
			wk[currentI][1]--;
			count1++;
		}
		if (currentG2 > 0) {
			currentG2 -= wk[currentI][2];
		}
		long count2 = solveCsaiki(currentG, currentI, wk, numG);
		return Math.min(count1, count2);

	}

	private void solveC() {
		Scanner scanner = null;
		int numD = 0;
		long numG = 0;

		try {
			scanner = new Scanner(System.in);
			numD = scanner.nextInt();
			numG = scanner.nextInt();
			long[][] wk = new long[numD][7];

			for (int i = 0; i < wk.length; i++) {
				wk[i][0] = (i + 1) * 100;//??
				wk[i][1] = scanner.nextLong();//??
				wk[i][2] = scanner.nextLong();//??????????
				wk[i][3] = (wk[i][0] * wk[i][1]);//??
				wk[i][4] = wk[i][3] + wk[i][2];//????????
				wk[i][5] = wk[i][4] / wk[i][1];//????????
				wk[i][6] = 0;//?????
			}

			long res = 0;
			for (int i = 0; i < wk.length; i++) {
				res += wk[i][6];
			}
			System.out.println(solveCsaiki(numG, 0, wk, numG));

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	public void solveC2() {
		Scanner sc = null;
		int n = 0;
		int goal = 0;
		int[][] arr;
		try {
			sc = new Scanner(System.in);
			n = sc.nextInt() /* <= 10 */;
			goal = sc.nextInt();
			arr = new int[n][5];
			for (int i = 0; i < n; i++) {
				arr[i][0] = (i + 1) * 100; // for which score problem
				arr[i][1] = sc.nextInt(); // how many
				arr[i][2] = sc.nextInt(); // bonus
				arr[i][3] = arr[i][0] * arr[i][1] + arr[i][2]; // total
			}

			//??????
			boolean[] left = new boolean[n];
			for (int i = 0; i < n; i++) {
				left[i] = true;
			}
			int min = Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				int count = 0;
				int score = 0;
				min = Math.min(rec(count, score, left, i, arr, goal), min);
			}
			System.out.println(min);
		} finally {
			if (sc != null) {
				sc.close();
			}
		}
	}

	public int rec(int count, int score, boolean[] left, int idx, int[][] arr, int goal) {
		if (score >= goal) {
			return count;
		}

		//??????????????
		for (int i = 0; i < arr[idx][1]; i++) {
			score += arr[idx][0];
			count++;
			//???goal?????return
			if (score >= goal) {
				return count;
			}
		}
		score += arr[idx][2];
		if (score >= goal) {
			return count;
		}

		int min = Integer.MAX_VALUE;
		left[idx] = false;
		for (int i = 0; i < left.length; i++) {
			if (left[i]) {
				min = Math.min(rec(count, score, left, i, arr, goal), min);
			}
		}
		left[idx] = true;
		return min;
	}

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