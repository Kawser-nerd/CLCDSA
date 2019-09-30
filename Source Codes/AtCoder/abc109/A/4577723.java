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
		int numA = 0;
		int numB = 0;

		try {
			scanner = new Scanner(System.in);
			numA = scanner.nextInt();
			numB = scanner.nextInt();
			for (int i = 1; i < 4; i++) {
				if (numA * numB * i % 2 != 0) {
					System.out.println("Yes");
					return;
				}
			}

			System.out.println("No");

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