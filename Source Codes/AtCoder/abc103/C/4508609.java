import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		//		new Main().solveB();
		new Main().solveC();
		//		 new Main().solveC2();
		// new Main().solveD();
	}

	private void solveA() {
		Scanner scanner = null;

		try {
			scanner = new Scanner(System.in);
			int[] wk = new int[3];

			for (int i = 0; i < wk.length; i++) {
				wk[i] = scanner.nextInt();
			}

			Arrays.sort(wk);
			int res = Math.abs(wk[0] - wk[1]) + Math.abs(wk[1] - wk[2]);

			System.out.println(res);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		String s;
		String t;

		try {
			scanner = new Scanner(System.in);
			s = scanner.next();
			t = scanner.next();

			s = s + s;

			System.out.println(s.contains(t) ? "Yes" : "No");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	//	private long saikiSolveC() {
	//
	//	}

	/**
	 * m = a1 × a2 × · · · × aN ?????? i ???? m mod ai = 0 ????(m ? 1) mod ai = ai ? 1
	 *  f(m ? 1) = (a1 ? 1) + (a2 ? 1) + · · · + (an ? 1) ????????????????
	 */
	private void solveC() {
		Scanner scanner = null;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();
			int[] wk = new int[numN];

			int res = 0;
			for (int i = 0; i < wk.length; i++) {
				wk[i] = scanner.nextInt();
				res += wk[i] - 1;
			}

			System.out.println(res);

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