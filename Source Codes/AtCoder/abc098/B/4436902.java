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

			System.out.println(Math.max(numA + numB, Math.max(numA - numB, numA * numB)));

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int numN = 0;
		String numS = "";

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();
			numS = scanner.next();

			int res = 0;
			for (int num = 0; num < 2; num++) {

				String numWk = "";
				if (num == 0) {
					numWk = numS;
				} else {
					numWk = new StringBuilder(numS).reverse().toString();
				}

				for (int i = numN / 2; i >= 0; i--) {
					char[] val1 = numWk.substring(0, i).toCharArray();
					char[] val2 = numWk.substring(i, numN).toCharArray();

					Set<Character> wkSet1 = new HashSet<Character>();
					for (int j = 0; j < val1.length; j++) {
						wkSet1.add(val1[j]);
					}

					Set<Character> wkSet2 = new HashSet<Character>();
					for (int j = 0; j < val2.length; j++) {
						wkSet2.add(val2[j]);
					}

					Set<Character> chkSet = null;
					Set<Character> resSet = null;
					if (wkSet1.size() > wkSet2.size()) {
						chkSet = wkSet1;
						resSet = wkSet2;
					} else {
						chkSet = wkSet2;
						resSet = wkSet1;
					}

					int cnt = 0;
					for (Character character : chkSet) {
						if (resSet.contains(character)) {
							cnt++;
						}
					}

					res = Math.max(res, cnt);
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