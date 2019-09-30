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
		int numC = 0;
		int numD = 0;

		try {
			scanner = new Scanner(System.in);
			numA = scanner.nextInt();
			numB = scanner.nextInt();
			numC = scanner.nextInt();
			numD = scanner.nextInt();

			boolean canTalk = false;

			canTalk = ((Math.abs(numA - numB) <= numD && Math.abs(numB - numC) <= numD)
					|| Math.abs(numA - numC) <= numD);

			System.out.println(canTalk ? "Yes" : "No");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int numX = 0;

		try {
			scanner = new Scanner(System.in);
			numX = scanner.nextInt();

			int max = 0;
			for (int i = 1; i <= numX; i++) {
				for (int j = 2; j < 10; j++) {
					if (Math.pow(i, j) <= numX) {
						max = Math.max(max, (int) Math.pow(i, j));
					} else {
						break;
					}
				}
			}

			System.out.println(max);
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