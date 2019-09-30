import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		//		new Main().solveB();
		new Main().solveC();
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
					if (wkIm1.charAt(wkIm1.length() - 1) != wkI.charAt(0)) {
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

	private long maxKouyakusu(long[] wk) {

		long res = 0;
		for (int i = 0; i < wk.length; i++) {
			if (i == 0) {
				res = wk[i];
				continue;
			}
			res = maxKouyakusu(res, wk[i]);
		}
		return res;

	}

	private long maxKouyakusu(long i1, long i2) {

		long w1 = Math.min(i1, i2);
		long w2 = Math.max(i1, i2);

		while (w2 > 0) {
			long temp = w1 % w2;
			w1 = w2;
			w2 = temp;
		}

		return w1;

	}

	private void solveC() {
		Scanner scanner = null;
		int numN = 0;
		int numX = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();
			numX = scanner.nextInt();
			long[] wk = new long[numN + 1];

			wk[0] = numX;
			for (int i = 1; i < wk.length; i++) {
				wk[i] = scanner.nextInt();
			}

			Arrays.sort(wk);
			long[] wkSa = new long[numN];
			for (int i = 0; i < wk.length; i++) {
				if (i != 0) {
					wkSa[i - 1] = wk[i] - wk[i - 1];
				}
			}

			System.out.println(maxKouyakusu(wkSa));

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