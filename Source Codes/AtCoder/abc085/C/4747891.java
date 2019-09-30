import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		//		new Main().solveB();
		//		new Main().solveC();
		new Main().solveC2();
		//		new Main().solveC3();
		// new Main().solveD();
	}

	private void solveA() {
		Scanner scanner = null;
		String line = "";

		try {
			scanner = new Scanner(System.in);
			line = scanner.next();

			System.out.println(line.replaceAll("2017", "2018"));

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {

		final Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] wk = IntStream.range(0, n).map(i -> scanner.nextInt()).toArray();
		//			int[] wk = new int[n];
		//
		//			for (int i = 0; i < n; i++) {
		//				wk[i] = scanner.nextInt();
		//			}

		Arrays.sort(wk);

		int res = IntStream.range(0, n).reduce(0, (sum, i) -> {
			if (i == 0) {
				sum++;
			} else if (wk[i] != wk[i - 1]) {
				sum++;
			}
			return sum;
		});
		//			int res = 0;
		//			for (int i = 0; i < wk.length; i++) {
		//				if (i == 0) {
		//					res++;
		//				} else if (wk[i] != wk[i - 1]) {
		//					res++;
		//				}
		//
		//			}

		System.out.println(res);
		if (scanner != null) {
			scanner.close();
		}
	}

	private void solveC2() {
		Scanner scanner = null;
		int n = 0;
		int y = 0;

		try {
			scanner = new Scanner(System.in);
			n = scanner.nextInt();
			y = scanner.nextInt();

			for (int i = n; i >= 0; i--) {
				if (i * 10000 > y) {
					continue;
				}
				for (int j = 0; j <= n - i; j++) {
					int k = n - i - j;
					if (i * 10000 + j * 5000 + k * 1000 == y) {
						System.out.println(i + " " + j + " " + k);
						return;
					}
				}
			}

			System.out.println(-1 + " " + -1 + " " + -1);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveC3() {
		Scanner scanner = null;
		int n = 0;
		int y = 0;

		try {
			scanner = new Scanner(System.in);
			n = scanner.nextInt();
			y = scanner.nextInt();

			for (int i = n; i >= 0; i--) {
				if (i * 10000 > y) {
					continue;
				}
				for (int j = 0; j <= n; j++) {
					if (i + j <= n && i * 10000 + j * 5000 + (n - i - j) * 1000 == y) {
						System.out.println(i + " " + j + " " + (n - i - j));
						return;
					}
				}
			}

			System.out.println(-1 + " " + -1 + " " + -1);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveC() {
		Scanner scanner = null;
		int n = 0;
		int y = 0;

		try {
			scanner = new Scanner(System.in);
			n = scanner.nextInt();
			y = scanner.nextInt();

			for (int i = n; i >= 0; i--) {
				if (i * 10000 > y) {
					continue;
				}
				for (int j = 0; j <= n - i; j++) {
					for (int k = 0; k <= n - i - j; k++) {
						if (n == i + j + k && i * 10000 + j * 5000 + k * 1000 == y) {
							System.out.println(i + " " + j + " " + k);
							return;
						}
					}
				}
			}

			System.out.println(-1 + " " + -1 + " " + -1);

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

			System.out.println("");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}
}