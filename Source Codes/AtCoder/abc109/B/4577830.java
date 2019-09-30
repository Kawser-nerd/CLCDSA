import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

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

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();
			String[] wk = new String[numN];

			Set<String> wkSet = new HashSet<String>();
			for (int i = 0; i < wk.length; i++) {
				String wkI = scanner.next();
				wk[i] = wkI;
				if (wkSet.contains(wk[i])) {
					System.out.println("No");
					return;
				}
				wkSet.add(wk[i]);
				if (i != 0) {
					String wkIm1 = wk[i - 1];
					if(wkIm1.charAt(wkIm1.length()-1)!=wkI.charAt(0)) {
						System.out.println("No");
						return;
					}

				}
			}

			System.out.println("Yes");

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