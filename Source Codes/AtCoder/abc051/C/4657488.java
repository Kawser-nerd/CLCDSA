import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		//		new Main().solveB();
		new Main().solveC();
		// new Main().solveD();
	}

	private void solveA() {
		Scanner scanner = null;
		String wk = "";

		try {
			scanner = new Scanner(System.in);
			wk = scanner.next();

			System.out.println(wk.replaceAll(",", " "));

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int numK = 0;
		int s = 0;

		try {
			scanner = new Scanner(System.in);
			numK = scanner.nextInt();
			s = scanner.nextInt();

			int startK = 0;
			if (numK <= s / 3) {
				startK = numK;
			}
			int res = 0;
			for (int i = 0; i <= numK; i++) {
				for (int j = 0; j <= numK; j++) {
					if (s - i - j < 0) {
						break;
					} else if (s - i - j <= numK) {
						res++;
					}
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
		int lineSX = 0;
		int lineSY = 0;
		int lineTX = 0;
		int lineTY = 0;

		try {
			scanner = new Scanner(System.in);
			lineSX = scanner.nextInt();
			lineSY = scanner.nextInt();
			lineTX = scanner.nextInt();
			lineTY = scanner.nextInt();

			StringBuilder builderRes = new StringBuilder();

			StringBuilder builderGo = new StringBuilder();
			StringBuilder builderBack = new StringBuilder();

			for (int i = 0; i < lineTY - lineSY; i++) {
				builderGo.append("U");
				builderBack.append("D");
			}
			for (int i = 0; i < (lineTX - lineSX); i++) {
				builderGo.append("R");
				builderBack.append("L");
			}

			builderRes.append(builderGo).append(builderBack);
			builderGo.setLength(0);
			builderBack.setLength(0);

			builderGo.append("L");
			builderBack.append("R");

			for (int i = 0; i < (lineTY - lineSY) + 1; i++) {
				builderGo.append("U");
				builderBack.append("D");
			}
			for (int i = 0; i < (lineTX - lineSX) + 1; i++) {
				builderGo.append("R");
				builderBack.append("L");
			}

			builderGo.append("D");
			builderBack.append("U");

			builderRes.append(builderGo).append(builderBack);

			System.out.println(builderRes.toString());

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