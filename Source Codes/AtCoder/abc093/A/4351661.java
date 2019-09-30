import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solveA();
		// new Main().solveB();
		// new Main().solveC();
		// new Main().solveD();
	}

	private void solveA() {
		Scanner scanner = null;
		String s = "";

		try {
			scanner = new Scanner(System.in);
			s = scanner.next();

			char[] wk = s.toCharArray();

			int cntA = 0;
			int cntB = 0;
			int cntC = 0;

			for (int i = 0; i < wk.length; i++) {
				char c = wk[i];
				if (c == 'a' && cntA == 0) {
					cntA++;
				} else if (c == 'b' && cntB == 0) {
					cntB++;
				} else if (c == 'c' && cntC == 0) {
					cntC++;
				}
			}

			System.out.println((cntA + cntB + cntC) == 3 ? "Yes" : "No");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
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

	private void solveC() {
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