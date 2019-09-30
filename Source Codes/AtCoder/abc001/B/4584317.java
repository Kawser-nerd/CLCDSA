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
		int numH1 = 0;
		int numH2 = 0;

		try {
			scanner = new Scanner(System.in);
			numH1 = scanner.nextInt();
			numH2 = scanner.nextInt();

			System.out.println(numH1 - numH2);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int numM = 0;

		try {
			scanner = new Scanner(System.in);
			numM = scanner.nextInt();
			int vv = 0;
			if (numM < 100) {
				vv = 0;
			} else if (numM <= 5000) {
				vv = numM / 100;
			} else if (numM <= 30000) {
				vv = numM / 1000 + 50;
			} else if (numM <= 70000) {
				vv = (numM / 1000 - 30) / 5 + 80;
			} else {
				vv = 89;
			}
			System.out.printf("%02d%n", vv);
			;
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