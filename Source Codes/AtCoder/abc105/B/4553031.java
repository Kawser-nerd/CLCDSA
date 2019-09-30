import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		//		new Main().solveB();
		new Main().solveB2();
		// new Main().solveC();
		// new Main().solveD();
	}

	private void solveA() {
		Scanner scanner = null;
		int numN = 0;
		int numK = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();
			numK = scanner.nextInt();

			if (numN % numK == 0) {
				System.out.println(0);
			} else {
				System.out.println(1);
			}

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private int isPurchase(int numN, int num) {

		if (numN <= 0) {
			return numN;
		}
		if (bWkMap.get(numN) != null) {
			return bWkMap.get(numN);
		}

		int val1 = isPurchase(numN - 7, 4);
		int val2 = isPurchase(numN - 7, 7);
		int val3 = isPurchase(numN - 4, 4);
		int val4 = isPurchase(numN - 4, 7);

		val1 = val1 < 0 ? 999999999 : val1;
		val2 = val2 < 0 ? 999999999 : val2;
		val3 = val3 < 0 ? 999999999 : val3;
		val4 = val4 < 0 ? 999999999 : val4;

		int wk = Math.min(Math.min(val1, val2), Math.min(val3, val4));

		bWkMap.put(numN, wk);
		return wk;
	}

	private Map<Integer, Integer> bWkMap = new HashMap<Integer, Integer>();

	private void solveB() {
		Scanner scanner = null;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			int val = isPurchase(numN, 0);

			System.out.println(val == 0 ? "Yes" : "No");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB2() {
		Scanner scanner = null;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			for (int i = 0; i < 25; i++) {
				for (int j = 0; j < 15; j++) {
					if (4 * i + 7 * j == numN) {
						System.out.println("Yes");
						return;
					}
				}
			}
			System.out.println("No");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveC() {
		Scanner scanner = null;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			long wk = 0;
			while (wk == numN) {

			}

			System.out.println("");

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