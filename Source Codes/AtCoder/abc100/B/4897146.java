import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		new Main().solveB();
		//		new Main().solveB2();
		//		new Main().solveC();
		// new Main().solveD();
	}

	private void solveA() {
		Scanner scanner = null;
		int numA = 0;
		int numB = 0;

		try {
			scanner = new Scanner(System.in);
			numA = scanner.nextInt();
			numB = scanner.nextInt();

			if (numA > 16 / 2 || numB > 16 / 2) {
				System.out.println(":(");
				return;
			}

			System.out.println("Yay!");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int numD = 0;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numD = scanner.nextInt();
			numN = scanner.nextInt();
			if (numN == 100) {
				numN++;
			}
			switch (numD) {
			case 0:
				System.out.println(numN);
				break;
			case 1:
				System.out.println(numN * 100);
				break;
			case 2:
				System.out.println(numN * 10000);
				break;
			default:
				break;
			}

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private int getFunc(int x) {
		int res = 0;
		while (x % 100 == 0) {
			x = x / 100;
			res++;
		}
		return res;
	}

	private int getFuncSaiki(int x) {
		if (x % 100 != 0) {
			return 0;
		}
		return getFuncSaiki(x / 100) + 1;
	}

	private void solveB2() {
		Scanner scanner = null;
		int numD = 0;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numD = scanner.nextInt();
			numN = scanner.nextInt();

			int count = 0;
			int val = 0;

			while (count != numN) {
				val++;
				if (getFunc(val) == numD) {
					count++;
				}
			}
			System.out.println(val);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private long dpSolveC(long[] wk) {
		int cnt = 0;
		for (int i = 0; i < wk.length; i++) {
			long wkNum = wk[i];
			while (wkNum % 2 == 0) {
				wkNum /= 2;
				cnt++;
			}
		}
		return cnt;

	}

	/**
	 * a[i]?????????2???????????
	 * a[i]?3?????2????????????????
	 * ?????a[i]?2?????????????????
	 */
	private void solveC() {
		Scanner scanner = null;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();
			long[] wk = new long[numN];

			for (int i = 0; i < wk.length; i++) {
				wk[i] = scanner.nextLong();
			}

			System.out.println(dpSolveC(wk));

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
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