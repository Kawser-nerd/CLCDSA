import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solveA();
		//		new Main().solveB();
		// new Main().solveC();
		// new Main().solveD();
	}

	private void solveA() {
		Scanner scanner = null;
		String topping = "";

		try {
			scanner = new Scanner(System.in);
			topping = scanner.next();

			int res = 700;

			for (int i = 0; i < topping.length(); i++) {
				switch (topping.charAt(i)) {
				case 'o':
					res += 100;
					break;
				case 'x':
					break;

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
		int numX = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();
			numX = scanner.nextInt();

			int[] wk = new int[numN];

			int res = 0;
			for (int i = 0; i < numN; i++) {
				wk[i] = scanner.nextInt();
				res++;
				numX -= wk[i];
			}

			Arrays.sort(wk);

			boolean isExit = false;
			while (!isExit) {
				if (numX >= wk[0]) {
					numX -= wk[0];
					res++;
				} else {
					isExit = true;
				}
			}

			System.out.println(res);

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