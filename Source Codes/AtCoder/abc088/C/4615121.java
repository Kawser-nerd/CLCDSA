import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		//		new Main().solveB();
		new Main().solveC();
		// new Main().solveD();
		//		new Main().solveE();
		//		new Main().solveF();
	}

	private void solveA() {
		Scanner scanner = null;
		int numN = 0;
		int numA = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();
			numA = scanner.nextInt();

			int res = numN % 500;

			System.out.println(res <= numA ? "Yes" : "No");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			int[] wk = new int[numN];
			for (int i = 0; i < wk.length; i++) {
				wk[i] = scanner.nextInt();
			}

			Arrays.sort(wk);

			int alice = 0;
			int bob = 0;
			boolean convert = true;
			for (int i = wk.length - 1; i >= 0; i--) {
				if (convert) {
					alice += wk[i];
				} else {
					bob += wk[i];
				}
				convert = !convert;
			}

			System.out.println(alice - bob);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private boolean chkC(int[][] wk, int max, int currentA, int[] aA, int[] bA) {
		if (currentA > max) {
			return false;
		}

		aA[0] = currentA;
		for (int j = 0; j < bA.length; j++) {
			bA[j] = wk[0][j] - currentA;
		}
		for (int i = 0; i < aA.length; i++) {
			aA[i] = wk[i][0] - bA[0];
		}
		boolean isMatch = true;
		outside: for (int i = 0; i < bA.length; i++) {
			for (int j = 0; j < bA.length; j++) {
				isMatch = wk[i][j] == aA[i] + bA[j];
				if (!isMatch) {
					break outside;
				}
			}
		}
		return isMatch ? true : chkC(wk, max, currentA + 1, aA, bA);
	}

	private void solveC() {
		Scanner scanner = null;

		try {
			scanner = new Scanner(System.in);

			int[][] wk = new int[3][3];
			int[] aA = new int[3];
			int[] bA = new int[3];

			int max = 0;
			for (int i = 0; i < wk.length; i++) {
				for (int j = 0; j < wk[i].length; j++) {
					wk[i][j] = scanner.nextInt();
					max = Math.max(max, wk[i][j]);
				}
			}

			System.out.println(chkC(wk, max, 0, aA, bA) ? "Yes" : "No");

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

	private void solveE() {
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

	private void solveF() {
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