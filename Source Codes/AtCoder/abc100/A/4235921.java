import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		new Main().solveA();
		//		new Main().solveB();
		//		new Main().solveC();
		//		new Main().solveD();
	}

	private void solveA() {
		Scanner scanner = null;
		int a = 0;
		int b = 0;

		try {
			scanner = new Scanner(System.in);
			a = scanner.nextInt();
			b = scanner.nextInt();
			if (a > 8 || b > 8) {
				System.out.println(":(");
			} else {
				System.out.println("Yay!");
			}
		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int lineAB = 0;
		int lineBC = 0;
		int lineCA = 0;

		try {
			scanner = new Scanner(System.in);
			lineAB = scanner.nextInt();
			lineBC = scanner.nextInt();
			lineCA = scanner.nextInt();

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveC() {
		Scanner scanner = null;
		int lineAB = 0;
		int lineBC = 0;
		int lineCA = 0;

		try {
			scanner = new Scanner(System.in);
			lineAB = scanner.nextInt();
			lineBC = scanner.nextInt();
			lineCA = scanner.nextInt();

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveD() {
		Scanner scanner = null;
		int lineAB = 0;
		int lineBC = 0;
		int lineCA = 0;

		try {
			scanner = new Scanner(System.in);
			lineAB = scanner.nextInt();
			lineBC = scanner.nextInt();
			lineCA = scanner.nextInt();

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}
}