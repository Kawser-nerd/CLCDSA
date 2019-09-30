import java.util.Arrays;
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
		char[] name = null;

		try {
			scanner = new Scanner(System.in);
			name = scanner.next().toCharArray();

			int half = name.length % 2 == 0 ? name.length / 2 : (name.length / 2) + 1;
			int length = name.length - 1;

			boolean isKaibun = true;
			for (int i = 0; i < half; i++) {
				if (name[i] != name[length - i]) {
					isKaibun = false;
				}
			}

			if (isKaibun) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void setUmetate() {
		for (int i = 0; i < wk.length; i++) {
			for (int j = 0; j < wk.length; j++) {
				if (wk[i][j] == 'o') {
					continue;
				}
				int res = 0;
				if (i > 0) {
					res += wk[i - 1][j] == 'o' ? 1 : 0;
				}
				if (i < 9) {
					res += wk[i + 1][j] == 'o' ? 1 : 0;
				}
				if (j > 0) {
					res += wk[i][j - 1] == 'o' ? 1 : 0;
				}
				if (j < 9) {
					res += wk[i][j + 1] == 'o' ? 1 : 0;
				}
				if (res >= 2) {
					umetate[i][j] = true;
				}
			}
		}
	}

	private void setReach(int currentX, int currentY, boolean isFirst) {

		if (currentX > 9 || currentX < 0) {
			return;
		}
		if (currentY > 9 || currentY < 0) {
			return;
		}
		if (reach[currentX][currentY] && !isFirst) {
			return;
		}
		if (wk[currentX][currentY] == 'o') {
			reach[currentX][currentY] = true;
		}

		if (currentX > 0 && (wk[currentX - 1][currentY] == 'o')) {
			setReach(currentX - 1, currentY, false);
		}
		if (currentX < 9 && (wk[currentX + 1][currentY] == 'o')) {
			setReach(currentX + 1, currentY, false);
		}
		if (currentY > 0 && (wk[currentX][currentY - 1] == 'o')) {
			setReach(currentX, currentY - 1, false);
		}
		if (currentY < 9 && (wk[currentX][currentY + 1] == 'o')) {
			setReach(currentX, currentY + 1, false);
		}
	}

	private boolean compareReach() {

		boolean res = true;
		side: for (int i = 0; i < wk.length; i++) {
			for (int j = 0; j < wk.length; j++) {
				if (wk[i][j] == 'o' && !reach[i][j]) {
					res = false;
					break side;
				}
			}
		}
		return res;

	}

	private boolean[][] umetate = new boolean[10][10];
	private boolean[][] reach = new boolean[10][10];
	private char[][] wk = new char[10][10];

	private void solveB() {
		Scanner scanner = null;
		fillBoolean(umetate);

		;
		try {
			scanner = new Scanner(System.in);

			for (int i = 0; i < wk.length; i++) {
				wk[i] = scanner.next().toCharArray();
			}
			setUmetate();

			for (int i = 0; i < wk.length; i++) {
				for (int j = 0; j < wk.length; j++) {
					if (umetate[i][j]) {
						fillBoolean(reach);
						reach[i][j] = true;
						setReach(i, j, true);
						if (compareReach()) {
							System.out.println("YES");
							return;
						}
					}
				}
			}

			System.out.println("NO");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void fillBoolean(boolean[][] wkArray) {
		for (int i = 0; i < 10; i++) {
			Arrays.fill(wkArray[i], false);
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