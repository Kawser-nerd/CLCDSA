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