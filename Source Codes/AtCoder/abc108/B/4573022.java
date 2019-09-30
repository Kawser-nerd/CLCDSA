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
		int numK = 0;
		int eqaC = 0;
		int oddC = 0;

		try {
			scanner = new Scanner(System.in);
			numK = scanner.nextInt();
			for (int i = 1; i <= numK; i++) {
				if (i % 2 == 0) {
					eqaC++;
				} else {
					oddC++;
				}
			}

			System.out.println(eqaC * oddC);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;

		try {
			scanner = new Scanner(System.in);
			x1 = scanner.nextInt();
			y1 = scanner.nextInt();
			x2 = scanner.nextInt();
			y2 = scanner.nextInt();

			int x3 = x2 - (y2 - y1);
			int y3 = y2 + (x2 - x1);
			int x4 = x3 - (y3 - y2);
			int y4 = y3 + (x3 - x2);

			System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);

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