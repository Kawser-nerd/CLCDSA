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
		String[] stringS = new String[4];

		try {
			scanner = new Scanner(System.in);
			stringS = scanner.next().split("");

			int res = 0;
			for (int i = 0; i < stringS.length; i++) {
				if (stringS[i].equals("+")) {
					res++;
				} else if (stringS[i].equals("-")) {
					res--;
				}
			}

			System.out.println(res);

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