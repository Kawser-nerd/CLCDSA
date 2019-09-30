import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		new Main().solveB();
		// new Main().solveC();
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